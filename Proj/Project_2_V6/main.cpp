/* 
 * File:   main.cpp
 * Author: Matthew Borja
 * Created on December 3, 2019, 12:42 PM
 * Purpose: Demonstrate key concepts learned throughout CIS-17A, specifically
 *          chapters 13-16, through a complicated game.
 */

#include <iostream>
#include "Player.h"
#include "Table.h"
using namespace std;

int menu();
bool game();
void won();

int main() {
    bool win=0;
    int nDeal=7;
    int choice;
    choice=menu();
    if(choice==1){
        cout<<"Starting a new game!"<<endl;
        win=game();
    }
    if(win){
        won();
    }
    return 0;
}

int menu(){
    bool again=true;
    int choice;
    while(again){
        cout<<"=========================Solitaire========================="<<endl;
        cout<<"\t\t\tMain Menu\n";
        cout<<"\t1. Start New Game."<<endl;
        cout<<"\t2. Exit."<<endl;
        cout<<"==========================================================="<<endl;
        cin>>choice;
        if(choice==1||choice==2){
            again=false;
        }
    }
    return choice;
}

bool game(){
    bool victory=0;
    int nCard=52,nDeal=1;
    string name;
    cout<<"Enter username: ";
    cin>>name;
    Player player(name,nCard,nDeal);
    player.setTable();
    while(victory!=1){
        player.display();
        //To do
    }
    return true;
}

void won(){
    cout<<"Congratulations! You won!";
    exit(0);
}