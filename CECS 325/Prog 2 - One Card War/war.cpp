// Name: Bryan Giang
// Class: CECS 325-01
// Project Name: Prog 2 – One-Card War
// Due Date: 9-28-2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Card
{
public:
    Card(char rank, char suit);
    void display();
    int compare(Card);

private:
    char suit;
    char rank;
};

Card::Card(char rank, char suit)
    : suit(suit), rank(rank)
{
}

void Card::display()
{
    if(rank == 'K'){
	    cout << 'K';
			}
	else if(rank == 'T'){
		cout << 10;
			}
	else if(rank == 'A'){
		cout << 'A';
			}
	else{
		cout << rank;
			}
	cout << suit << " ";
}


int Card::compare(Card other)
{
    const vector<char> ranks = {'A', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'T', 'J', 'Q', 'K'};
    int myValue = -1;
    int otherValue = -1;

    for (int i = 0; i < 13; i++) {
        if (rank == ranks[i])
            myValue = i;
        if (other.rank == ranks[i])
            otherValue = i;
    }

    if (myValue > otherValue)
        return 1;
    else if (myValue < otherValue)
        return -1;
    else
        return 0;
}


class Deck
{
private:
    vector<Card> cards;

public:
    Deck()
    {
    vector<char> suits = {'C', 'D', 'H', 'S'};
    vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            cards.push_back(Card(ranks[rank], suits[suit])); 

        
        }
    }
    }

    Card deal()
    {
        if (cards.empty())
            throw runtime_error("Deck is empty");
        
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
    }
 
    void display()
    {
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 13; col++)
            {
                cards[row * 13 + col].display();
                cout << " ";
            }

            cout << endl;
        }
    }

    void shuffle()
    {
        for (size_t i = 0; i < cards.size() - 1; i++) {
            size_t j = rand() % (cards.size() - i) + i;
            swap(cards[i], cards[j]);
        }
    }

    bool isEmpty()
    {
        return cards.empty();
    }
};

struct Player
{
    string name;
    int win;
    int lose;
    int tie;
};

int main()
{
    Deck deck;
    Player p1;
    Player p2;

    p1.win = 0;
    p1.lose = 0;
    p1.tie = 0;
    p2.win = 0;
    p2.lose = 0;
    p2.tie = 0;


    
    std::cout << "Enter the name of player 1: ";
    std::cin >> p1.name;
    std::cout << "Enter the name of player 2: ";
    std::cin >> p2.name;

    cout << "How many games would you like to play? ";
    int num_games;
    std::cin >> num_games;

    cout << "\nOriginal deck:\n";
    deck.display();
    deck.shuffle();

    std::cout << "\nShuffled deck:\n";
    deck.display();

    
    for (int game = 1; game <= num_games; game++) {
        
        try{


            Card card1 = deck.deal();
            Card card2 = deck.deal();
            int result = card1.compare(card2);

            cout << "Game " << game << ": " << p1.name << " ";
            card1.display();
            cout << " vs. " << p2.name << " ";
            card2.display();  

            if (result == 1) {
                cout << " - " << p1.name << " wins";
                p1.win++;
                p2.lose++;
            } else if (result == -1) {
                cout << " - " << p2.name << " wins";
                p2.win++;
                p1.lose++;
            } else {
                cout << " - Tie";
                p1.tie++;
                p2.tie++;
            }
            cout << endl;
        }
    catch (const runtime_error&) {
        cout << "The deck is empty." << endl;
        break;
    }
    }

    cout << "\nFinal Stats\n";
    cout << p1.name << endl;
    cout << "Wins: " << p1.win << endl;
    cout << "Losses: " << p1.lose << endl;
    cout << "Ties: " << p1.tie << endl;

    cout << endl;

    cout << p2.name << endl;
    cout << "Wins: " << p2.win << endl;
    cout << "Losses: " << p2.lose << endl;
    cout << "Ties: " << p2.tie << endl;

    return 0;  
}


