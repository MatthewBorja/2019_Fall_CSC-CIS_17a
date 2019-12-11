/* 
 * File:   Table.cpp
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:33 PM
 * Purpose: The implementation of Table class.
 */

#include "Table.h"

Table::Table(){
    maxPerPile=7;
    pileNum=0;
    t1=nullptr;     //To hold the cards for each of the 7 piles.
    t2=nullptr;
    t3=nullptr;
    t4=nullptr;
    t5=nullptr;
    t6=nullptr;
    t7=nullptr;
    stock=nullptr;
}

Table::~Table(){
    delete []t1;
}

void Table::setTableau(char *pile){
    t1=pile;
    
}

void Table::addFoundation(){
    
}

void Table::display(){
    f.display();
}