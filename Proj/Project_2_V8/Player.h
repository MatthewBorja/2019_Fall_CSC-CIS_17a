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
        unsigned char nDeal;
        friend class Deck;
    public:
        Player(string, unsigned char, unsigned char); 
        ~Player();
        void setTable();
        string getName() const {return name;}   //Inline Function
        void play();
};

#endif /* PLAYER_H */