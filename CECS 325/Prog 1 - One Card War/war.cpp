// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 1 – One-Card War
// Due Date: 9-16-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#include "deck.h"
#include <iostream>
#include "card.h"
using namespace std;

int main()
{
    Deck deck;
    
    string p1;
    string p2;

    int p1Wins = 0;
    int p2Wins = 0;
    int ties = 0;

    std::cout << "Enter the name of player 1: ";
    std::cin >> p1;
    std::cout << "Enter the name of player 2: ";
    std::cin >> p2;

    
    std::cout << "\nOriginal deck:\n";
    deck.show();

    deck.shuffle();
    std::cout << "\nShuffled deck:\n";
    deck.show();

    cout << "\nStarting!\n";
    for (int game = 1; game <= 26; game++) {
        Card card1 = deck.deal();
        Card card2 = deck.deal();
        int result = card1.compare(card2);

        cout << "Game " << game << ": " << p1 << " ";
        card1.show();
        cout << " vs. " << p2 << " ";
        card2.show();

        if (result == 1) {
            cout << " - " << p1 << " wins";
            p1Wins++;
        } else if (result == -1) {
            cout << " - " << p2 << " wins";
            p2Wins++;
        } else {
            cout << " - Tie";
            ties++;
        }
        cout << endl;
    }

    cout << "\nFinal Stats\n";
    cout << p1 << " wins: " << p1Wins << endl;
    cout << p2 << " wins: " << p2Wins << endl;
    cout << "Ties: " << ties << endl;

    return 0;
}
