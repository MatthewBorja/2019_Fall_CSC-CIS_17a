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
void Player::setHand(){
    hand=new Hand(deck->deal(nDeal),nDeal);
}
void Player::prntHand() const{
    hand->display();
}