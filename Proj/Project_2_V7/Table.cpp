/* 
 * File:   Table.cpp
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:33 PM
 * Purpose: The implementation of Table class.
 */

#include "Table.h"

Table::Table(){

    pileNum=0;
    stock=nullptr;
}

Table::~Table(){

}

void Table::setTableau(char *pile, char nDeal){
    for(char count=0;count<nDeal;count++){
        t[pileNum][count]=pile[count];
    }
    for(char clear=12;clear>nDeal;clear--){
        t[pileNum][clear]=0;
    }
    pileNum++;
}

void Table::addFoundation(){
    
}

void Table::display(){
    f.display();
    cout<<"--------------------TABLEAU--------------------\n";
    for(char r=0;r<7;r++){
        for(char c=0;c<13;c++){
            Card crd(t[r][c]);
            if(t[r][c]!=0){
                cout<<crd.suit()<<crd.face()<<" ";
            }
        }
        cout<<"."<<endl;
    }
    cout<<"-----------------------------------------------\n";
}