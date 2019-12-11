/* 
 * File:   Card.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 12:45 PM
 * Purpose: The specification for the Card class.
 */

#ifndef CARD_H
#define CARD_H

class Card{
    private:
        char cNum;   //Private data member
        char side;
    public:
        Card(char);  //Constructor
        //Member functions to...
        char suit(); //... get suits,
        char face(); //... get faces,
        char value();//... get values.
};

#endif /* CARD_H */