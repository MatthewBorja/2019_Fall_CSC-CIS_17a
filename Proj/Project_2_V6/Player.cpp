/* 
 * File:   Player.cpp
 * Author: Matthew Borja
 * Created on December 3, 2019, 9:22 PM
 * Purpose: The implementation of Player class.
 */

#include "Player.h"

Player::Player(string n, char nCard, char nDl){
    name=n;
    deck=new Deck(nCard);
    nDeal=nDl;
}
Player::~Player(){
    delete deck;
}
void Player::setTable(){
    table.setTableau(deck->deal(nDeal++));
    
    
}
void Player::display() const{
    
}