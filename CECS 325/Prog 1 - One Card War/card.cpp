// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 1 – One-Card War
// Due Date: 9-16-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#include "card.h"
#include <iostream>

using namespace std;

Card::Card() : suit('C'), rank('2')
{
}
Card::Card(char newSuit, char newRank)
{
    suit = newSuit;
    rank = newRank;
}

void Card::show()
{
    if (rank == 'T')
        cout << "10";
    else
        cout << rank;

    cout << suit;
}

int Card::compare(Card other)
{
    const char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    int thisIdx = -1;
    int otherIdx = -1;

    for (int i = 0; i < 13; i++)
    {
        if (rank == ranks[i]) thisIdx = i;
        if (other.rank == ranks[i]) otherIdx = i;
    }

    if (thisIdx < otherIdx)
        return -1;       
    else 
       if (thisIdx > otherIdx)
        return 1;      
    else
        return 0;       
}