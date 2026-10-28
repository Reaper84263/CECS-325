// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 1 – One-Card War
// Due Date: 9-16-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#include "deck.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Deck::Deck()
{
    nextCard = 0;
    const char suits[4] = {'D', 'C', 'H', 'S'};
    const char ranks[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    int pos = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            cards[pos] = Card(suits[suit], ranks[rank]);
            pos++;
        }
    }
}

Card Deck::deal()
{
    if (nextCard >= 52)
        return Card();
    return cards[nextCard++];
}

void Deck::show()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 13; col++)
        {
            cards[row * 13 + col].show();
            cout << " ";
        }

        cout << endl;
    }
}


void Deck::shuffle()
{
    
    for (int i = 0; i < 51; i++) {
        int j = rand() % (51 - i + 1) + i;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    nextCard = 0;
}
