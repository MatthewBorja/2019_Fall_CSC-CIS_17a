/* 
 * File:   Card.cpp
 * Author: Matthew Borja
 * Created on December 3, 2019, 12:48 PM
 * Purpose: The implementation for the Card class.
 */

#include "Card.h"

//Constructor
Card::Card(char nmbr){
    cNum=nmbr%52;   //Ensure the card number does not exceed 52 (deck size).
}

char Card::suit(){
    char suits[4]={'C','D','H','S'};    //Char array to store suit.
    char num=cNum/13;   //Get appropriate char of card number, limit to 13 per suit.
    return suits[num];  //Return appropriate suit.
}

char Card::face(){
    //Char array to represent different face values.
    char faces[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char num=cNum%13;   //Modulus by 13 to keep in-bounds.
    return faces[num];  //Return appropriate face value.
}

char Card::value(){
    char num=cNum%13;   //Value is the card number modulus 13.
    num++;              //Increment.
    return num>10?10:num;
}