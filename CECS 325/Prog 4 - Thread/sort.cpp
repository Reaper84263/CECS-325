// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 4 – Thread
// Due Date: 11-2-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>

using namespace std;

constexpr int THREAD_COUNT = 16;
long long totalSwaps = 0;
mutex swapsMutex;


void bubble(int* numbers, size_t size, int processNumber)
{
    long long processSwaps = 0;

    for (size_t end = size; end > 1; --end) {
        bool changed = false;
        for (size_t i = 1; i < end; ++i) {
            if (numbers[i - 1] > numbers[i]) {
                int value = numbers[i - 1];
                numbers[i - 1] = numbers[i];
                numbers[i] = value;
                ++processSwaps;
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }

    {
        lock_guard<mutex> lock(swapsMutex);
        totalSwaps += processSwaps;
        cout << "Process " << processNumber << " swap count:" << processSwaps << endl;
    }
}


void merge(int* numbers, int* temp, size_t first, size_t middle, size_t last)
{
    size_t left = first;
    size_t right = middle;
    size_t output = first;

    while (left < middle && right < last) {
        if (numbers[left] <= numbers[right]) {
            temp[output++] = numbers[left++];
        } else {
            temp[output++] = numbers[right++];
        }
    }
    while (left < middle) {
        temp[output++] = numbers[left++];
    }
    while (right < last) {
        temp[output++] = numbers[right++];
    }
    for (size_t i = first; i < last; ++i) {
        numbers[i] = temp[i];
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3 && argc != 4) {
        cerr << "Usage: " << argv[0] << " input-file output-file [-test]" << endl;
        return 1;
    }
    if (argc == 4 && string(argv[3]) != "-test") {
        cerr << "Invalid option: " << argv[3] << " (expected -test)" << endl;
        return 1;
    }

    const size_t count = (argc == 4) ? 10000 : 1000000;
    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error: cannot open input file " << argv[1] << endl;
        return 1;
    }

    int* numbers = new int[count];
    for (size_t i = 0; i < count; ++i) {
        if (!(input >> numbers[i])) {
            cerr << "Error: input file contains fewer than " << count << " numbers" << endl;
            delete[] numbers;
            return 1;
        }
    }
    int extra;
    if (input >> extra) {
        cerr << "Error: input file contains more than " << count << " numbers" << endl;
        delete[] numbers;
        return 1;
    }
    input.close();

   
    thread workers[THREAD_COUNT];
    for (int process = 0; process < THREAD_COUNT; ++process) {
        const size_t first = count * static_cast<size_t>(process) / THREAD_COUNT;
        const size_t last = count * static_cast<size_t>(process + 1) / THREAD_COUNT;
        workers[process] = thread(bubble, numbers + first, last - first, process);
    }
    for (int process = 0; process < THREAD_COUNT; ++process) {
        workers[process].join();
    }

    int* temporary = new int[count];
    for (size_t width = count / THREAD_COUNT; width < count; width *= 2) {
        for (size_t first = 0; first < count; first += 2 * width) {
            const size_t middle = first + width < count ? first + width : count;
            const size_t last = first + 2 * width < count ? first + 2 * width : count;
            if (middle < last) {
                merge(numbers, temporary, first, middle, last);
            }
        }
    }

    cout << "Total Swaps:" << totalSwaps << endl;
    ofstream output(argv[2]);
    if (!output) {
        cerr << "Error: cannot open output file " << argv[2] << endl;
        delete[] temporary;
        delete[] numbers;
        return 1;
    }
    for (size_t i = 0; i < count; ++i) {
        output << numbers[i] << '\n';
    }
    if (!output) {
        cerr << "Error: failed while writing output file " << argv[2] << endl;
        delete[] temporary;
        delete[] numbers;
        return 1;
    }

    delete[] temporary;
    delete[] numbers;
    return 0;
}
