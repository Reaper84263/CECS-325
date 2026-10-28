// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 3 – Sort Contest
// Due Date: 10-12-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bubble(vector<int>& numbers){
    cout << "Starting bubble sort with " << numbers.size() << " items" << endl;
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (numbers[j] > numbers[j + 1]){
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    cout << "Ending bubble sort." << endl;
}


int main(int argc, char* argv[]){
    if (argc > 3 || argc < 3){
        throw invalid_argument("Invalid number of arguments");
    }
    else{
        cout << " Starting my sort" << endl;
        ifstream numsfile(argv[1]);
        
        vector<int> numbers;
        int num;
        while (numsfile >> num){
            numbers.push_back(num);
        }
        numsfile.close();
        
        bubble(numbers);

        ofstream outfile(argv[2]);
        for (int i = 0; i < numbers.size(); i++){
            outfile << numbers[i] << endl;
        }
        outfile.close();
        cout << "Ending bubble sort" << argv[2] << endl;
        
        
    }

}
