// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 1 – One-Card War
// Due Date: 9-16-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H

class Card
{
public:
    Card();
    Card(char, char);
    void show();
    int compare(Card);

private:
    char suit;
    char rank;
};

#endif
