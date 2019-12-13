/* 
 * File:   Table.cpp
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:33 PM
 * Purpose: The implementation of Table class.
 */

#include "Table.h"

Table::Table(){
    pileCnt=new int[NUMPILES];
    pileNum=0;
    stock=nullptr;
}

Table::~Table(){
    delete []pileCnt;
}

void Table::setTableau(unsigned char *pile, unsigned char nDeal){
    for(unsigned char count=0;count<nDeal;count++){
        t[pileNum][count]=pile[count];
        pileCnt[count]=count;
    }

    pileNum++;
}

void Table::display(){
    int i;
    f.display();
    cout<<"--------------------TABLEAU--------------------\n";
    cout<<"   #0"<<endl;
    for(unsigned char r=0;r<pileNum;r++){
        cout<<"#"<<static_cast<int>(r)<<":";
        for(unsigned char c=0;c<=pileCnt[r];c++){
            Card crd(t[r][c]);
            cout<<crd.suit()<<crd.face()<<" ";
        }
        cout<<"."<<endl;
    }
    cout<<"-----------------------------------------------\n";
}

void Table::options(){
    int choice;
    cout<<"Options:\n";
    cout<<"1. Add to Foundation."<<endl;
    cout<<"2. Move Card in Tableau."<<endl;
    cout<<"3. Pick from the Stock Pile."<<endl;
    cout<<"9. Quit."<<endl;
    cin>>choice;
    switch(choice){
        case 1: addToFoundation();
            break;
        case 2: 
            break;
        case 3: 
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8: options();
            break;
        case 9: exit(0);
            break;
    }
}

void Table::addToFoundation(){
    int r,c;
    cout<<"Pick a card from the Tableau:\nRow: ";
    cin>>r;
    cout<<"Column: ";
    cin>>c;
    Card card(t[r][c]);
    cout<<card.suit();
    if(card.suit()=='C'){
        f.addToC(t[r][c]);
    }
    else if(card.suit()=='D'){
        f.addToD(t[r][c]);
    }
    else if(card.suit()=='H'){
        f.addToH(t[r][c]);
    }
    else if(card.suit()=='S'){
        f.addToS(t[r][c]);
    }
}