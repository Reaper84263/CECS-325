// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 3 – Sort Contest
// Due Date: 10-12-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4 || argc > 4){
        throw invalid_argument("Invalid number of arguments");
    }
    else{
        cout << "argv[0]:" << argv[0] << endl;
        cout << "argv[1]:" << argv[1] << endl;
        cout << "argv[2]:" << argv[2] << endl;
        cout << "argv[3]:" << argv[3] << endl;

        int COUNT = stoi(argv[1]);
        int MIN = stoi(argv[2]);
        int MAX = stoi(argv[3]);

        ofstream numsfile("numbers.dat");
        for (int i = 0; i < COUNT; i++){
            numsfile << (rand() % (MAX - MIN + 1) + MIN) << endl;
        }
        numsfile.close();
        return 0;
    }
    
    
}