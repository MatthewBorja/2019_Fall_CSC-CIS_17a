/* 
 * File:   Hand.cpp
 * Author: Matthew Borja
 * Created on December 3, 2019, 7:08 PM
 * Purpose: The implementation of the Hand class.
 */

#include "Hand.h"
#include "Card.h"
#include <iostream>
using namespace std;

Hand::Hand(char *crd, char num){
    cards=crd;
    nCards=num;
}

Hand::~Hand(){
    delete []cards;
}

void Hand::display(){
    for(char count=0;count<nCards;count++){
        Card card(cards[count]);
        cout<<static_cast<int>(cards[count])<<" "<<card.face()<<card.suit()<<" "
            <<static_cast<int>(card.value())<<endl;
    }
}