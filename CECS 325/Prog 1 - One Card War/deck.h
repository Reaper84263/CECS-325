// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 1 – One-Card War
// Due Date: 9-16-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck
{
private:
    Card cards[52];
    int nextCard;

public:
    Deck();
    Card deal();
    void show();
    void shuffle();
};

#endif
