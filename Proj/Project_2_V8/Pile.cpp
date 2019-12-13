/* 
 * File:   Pile.cpp
 * Author: Matthew Borja
 * Created on December 5, 2019, 11:56 AM
 * Purpose: The implementation of the Pile class.
 */

#include "Pile.h"
#include "Card.h"
using namespace std;

Pile::Pile(){
    nCards=0;
    cards=0;
}
Pile::Pile(unsigned char *crd,unsigned char num){
    cards=crd;
    nCards=num;
}

Pile::~Pile(){
    delete []cards;
}

void Pile::display(){
    for(unsigned char crd=0;crd<nCards;crd++){
        Card card(cards[crd]);
        cout<<static_cast<int>(cards[crd])<<" "<<card.face()
            <<card.suit()<<" "
            <<static_cast<int>(card.value());
    }
}