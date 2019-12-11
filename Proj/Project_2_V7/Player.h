/* File:   Player.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 9:14 PM
 * Purpose: The specification for the Player class.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "AbsPlayer.h"
#include "Deck.h"
#include "Table.h"

class Player : public AbsPlayer{
    protected:
        string name;
        Table table;
        Deck *deck;
        char nDeal;
        friend class Deck;
    public:
        Player(string, char, char); 
        ~Player();
        void setTable();
        string getName() const {return name;}   //Inline Function
        void display();
};

#endif /* PLAYER_H */