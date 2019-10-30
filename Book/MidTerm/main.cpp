/* File:   main.cpp
 * Author: Matthew Borja
 * Created on October 28, 2019, 9:21 PM
 * Purpose: Answer the problems from the midterm.
 */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>

#include "bankaccount.h"
#include "employee.h"

using namespace std;

void menu();
void problem1();
void getBnkInfo(Account *,int,int);
void bankDestroy(Account*);
void problem2();
void intro(Employee*,const int,const int);
void payRoll(Employee*,const int,const int,int);
void toEnglish(Employee*,int);
string words(bool,int);
void empDestroy(Employee *);
void problem4();
void getEncryptData(char*,int);
void encrypt(char*,int);
void decrypt(char*,int);
void problem5();
void problem6();
void problem7();

int main() {
    int choice;
        do{
         menu();
         cin>>choice;
         switch(choice){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    cout<<"Problem not included."<<endl;break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   cout<<"Exiting Menu"<<endl;}
        }while(choice>0&&choice<8);
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Problem 3 is not included in the menu."<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
}

void problem1(){
    int numAccts, counter;
    
    cout<<"Welcome to Bank of Mark.\n";
    cout<<"How many accounts would you like to open? ";
    cin>>numAccts;                                  //Get number of accounts to create.
    cin.ignore();                                   //Ignore next /0 in keyboard buffer.
    Account *acctPtr = new Account[numAccts];       //Dynamically allocate memory.
    for(counter=0; counter<numAccts; counter++){
        getBnkInfo(acctPtr,numAccts,counter);       //Loop through accounts.
    }
    cout<<"Thank you for choosing Bank of Mark!";   //Bid farewell.
    bankDestroy(acctPtr);                           //Deallocate memory.
}

void getBnkInfo(Account *acctPtr, int numAccts, int counter){
    bool numeric=0, fiveDig=0;  //Flags used for input validation.
    int numChck, chckAmt, numDep, depAmt, penalty=20;   //Used to process data.
    cout<<"What is your name? ";
    getline(cin, acctPtr[counter].name);
    cout<<"Please enter your address. ";
    getline(cin, acctPtr[counter].address);
    while(numeric==false&&fiveDig==false){  //Input validation. Cannot be less than 5 digits
        cout<<"Please enter your account number. (ex: 12345) ";             //Must be numeric.
        cin>>acctPtr[counter].acctNum;
        if(strlen(acctPtr[counter].acctNum)==5){
            fiveDig=true;   //If string length is 5, turn on flag.
        }
        if(isdigit(stoi(acctPtr[counter].acctNum))){
            numeric=true;   //If string is numeric, turn on flag.
        }
        if (numeric==false && fiveDig==false){  //Ask user to input legal data.
            cout<<"Your account number must consist of only 5 numeric digits.\n";
        }
    }
    cout<<"Please enter your balance at the beginning of the month. ";
    cin>>acctPtr[counter].bal;      //Get starting balance.
    cout<<"Checks - How many checks did you write? ";   //Get number of withdrawals.
    cin>>numChck;
    for(int i=0; i<numChck; i++){   //Loop through all checks.
        cout<<"Enter the amount of check "<<i+1<<": ";
        cin>>chckAmt;
        acctPtr[counter].totChck += chckAmt;
    }
    cout<<"Deposits - How many deposits have you made to your account? ";   //Get number of deposits.
    cin>>numDep;
    for(int j=0; j<numDep; j++){    //Loop through all deposits.
        cout<<"Enter the amount of deposit "<<j+1<<": ";
        cin>>depAmt;
        acctPtr[counter].totDep += depAmt;
    }
    cin.ignore();   //Ignore next /0 in keyboard buffer.
    acctPtr[counter].bal += acctPtr[counter].totDep - acctPtr[counter].totChck; //Calculate total
    cout<<"Your new balance is: $"<<acctPtr[counter].bal<<endl; //Display new balance.
    if(acctPtr[counter].bal<0){ //If overdraw... Penalize.
        cout<<"You have overdrawn the account. The penalty for overdraw is $20.\n";
        acctPtr[counter].bal-=penalty;  //Apply overdraw penalty.
        cout<<"After debiting this penalty to your account, your new balance is $"
            <<acctPtr[counter].bal<<endl;
    }   //Otherwise, display account information below.
    cout<<acctPtr[counter].name<<"\t Account #:"<<acctPtr[counter].acctNum<<endl
        <<acctPtr[counter].address<<endl<<"Your balance: $"<<acctPtr[counter].bal<<endl;
}

void bankDestroy(Account *ptr){
    delete []ptr;               //Deallocate memory
}

void problem2(){    //Payroll problem.
    const int FULLTIME=40, DUBTIME=50;  //Use const ints for readability.
    Employee *empPtr=nullptr;           //Declare pointer.
    cout<<"Company Payroll Program\n";
    intro(empPtr,FULLTIME,DUBTIME);     //Introduce user.
    empDestroy(empPtr);                 //After all steps, deallocate memory.
}

void intro(Employee *empPtr,const int FULLTIME,const int DUBTIME){
    int num=0;  //Initialize number of paychecks to calculate.
    cout<<"How many paychecks would you like to calculate?";
    cin>>num;
    empPtr=new Employee[num];   //Dynamically allocate enough memory for number of loops.
    for(int count=0;count<num;count++){
        payRoll(empPtr,FULLTIME,DUBTIME,count); //Call function to calculate.
    }
}

void payRoll(Employee *empPtr,const int FULLTIME,const int DUBTIME, int num){
    cin.ignore();   //Ignore next /0 in keyboard buffer.
    cout<<"Name: ";
    getline(cin, empPtr[num].name);
    cout<<"What is your hourly pay rate? ";
    cin>>empPtr[num].payRate;
    cout<<"How many hours have you worked this week? ";
    cin>>empPtr[num].hours;
    if(empPtr[num].hours<=FULLTIME){    //If less than 40 hrs, standard rate of pay.
        empPtr[num].gross=empPtr[num].hours*empPtr[num].payRate;
    }
    else if(empPtr[num].hours>FULLTIME&&empPtr[num].hours<=DUBTIME){    //If over 40 hours but less than 50, apply double time.
        empPtr[num].gross=empPtr[num].hours*empPtr[num].payRate;
        empPtr[num].gross+=(empPtr[num].hours-FULLTIME)*(empPtr[num].payRate*2);
    }
    else if(empPtr[num].hours>DUBTIME){ //If over 50 hours, apply triple time appropriately.
    empPtr[num].gross=empPtr[num].hours*empPtr[num].payRate;
    empPtr[num].gross+=(empPtr[num].hours-FULLTIME)*(empPtr[num].payRate*2);
    empPtr[num].gross+=(empPtr[num].hours-DUBTIME)*(empPtr[num].payRate*3);
    }
    else if(empPtr[num].hours>168){ //Input validation. Only 168 hours in a week.
        cout<<"That is more hours than in a single week. Please enter a real value.";
    }
    //Display user's pay in paycheck format.
    cout<<"Riverside Tech Inc.\n4800 Magnolia Ave., Riverside, CA 92506\n"; //Fake business name and address.
    cout<<"Name: "<<empPtr[num].name<<"\t\tAmount: $"<<empPtr[num].gross;
    toEnglish(empPtr,num);  //Function to handle English version of amount.
}

void toEnglish(Employee *empPtr, int num){
    bool dubDgt=false;  //Flag to determine whether to use "Eleven" instead of "one one dollars".
    string english; //To temporarily store strings from switch statement and append to amount structure member.
    int thsnds,hundrds,tens,twoDig,ones,count=0;    //To hold digit of thousands, hundreds place, etc.
    if(empPtr[num].gross>0&&empPtr[num].gross<10){  //If amount $0-$9
        ones=empPtr[num].gross;                     //Get ones place digit.
        count=1;                                    //How many times to run switch statement. (One time)
    }
    else if(empPtr[num].gross>9&&empPtr[num].gross<100){    //If amount $10-$99
        twoDig=empPtr[num].gross/10;    //Get single digit of tens place.
        tens=empPtr[num].gross;         //Get two digit amount of pay.
        ones=empPtr[num].gross-tens;    //Get ones place digit.
        count=2;                        //Run switch statement twice.
    }
    else if(empPtr[num].gross>99&&empPtr[num].gross<1000){  //If amount $100-$999
        hundrds=empPtr[num].gross/100;                      //Get hundreds digit
        twoDig=(empPtr[num].gross-(hundrds*100))/10;        //Get tens digit (So 88 is "Eighty-Eight" instead of "Eight Eight")
        tens=(empPtr[num].gross-(hundrds*100));             //Get two digit amount
        ones=(empPtr[num].gross-(hundrds*100+(twoDig*10))); //Get ones digit.
        count=3;                                            //Run switch three times.
    }
    else if(empPtr[num].gross>999&&empPtr[num].gross<10000){    //If amount $1000-$9999.
        thsnds=empPtr[num].gross/1000;                                  //Get thousands digit.
        hundrds=(empPtr[num].gross-(thsnds*1000))/100;                  //Get hundreds digit.
        twoDig=(empPtr[num].gross-(thsnds*1000+(hundrds*100)))/10;      //Get tens digit. (So 59 is "Fifty-Nine" instead of "Five Nine")
        tens=(empPtr[num].gross-(thsnds*1000+(hundrds*100)));           //Get last two digits (So 13 is "Thirteen" instead of "One Three")
        ones=empPtr[num].gross-(thsnds*1000+(hundrds*100+(twoDig*10))); //Get last digit
        count=4;                                                        //Run switch four times.
    }
    for(int i=count;i>0;i--){   //Loop through switch depending on how big number is.
        if(i==4){   //If value is ####
            english=words(dubDgt,thsnds);
            empPtr[num].amount.append(english);
            empPtr[num].amount.append(" Thousand ");
        }
        if(i==3){   //If value is ###
            english=words(dubDgt,hundrds);
            empPtr[num].amount.append(english);
            empPtr[num].amount.append(" Hundred ");
        }
        if(i==2){   //If value is ##
            if(tens>9&&tens<20){    //If 10-19 use words "ten through nineteen"
                english=words(dubDgt,tens);
                empPtr[num].amount.append(english);
            }
            else{                   //If 20-99 use tens version of numbers: i.e: Forty, Fifty, Sixty, etc. 
                dubDgt=true;
                english=words(dubDgt,twoDig);
                empPtr[num].amount.append(english);
                dubDgt=false;
            }
        }
        if(i==1&&dubDgt==false){    //If tens place is a 0, get word for one's digit.
            english=words(dubDgt,ones);
            empPtr[num].amount.append(english);
        }
    }
    cout<<endl<<empPtr[num].amount<<"\tDollars";    //Display full English version of amount.
}

string words(bool dubDgt,int val){
    string word;
    switch(val){
        case 0:
            word=" ";
        break;
        case 1: 
            word="One";
        break;
        case 2:
            if(dubDgt==true)
                word="Twenty-";
            else
                word="Two";
        break;
        case 3:
            if(dubDgt==true){
                word="Thirty-";
            }
            else
                word="Three";
        break;
        case 4:
            if(dubDgt==true)
                word="Forty-";
            else
                word="Four";
            break;
        case 5:
            if(dubDgt==true)
                word="Fifty-";
            else
                word="Five";
            break;
        case 6:
            if(dubDgt==true)
                word="Sixty-";
            else
                word="Six";
            break;
        case 7:
            if(dubDgt==true)
                word="Seventy-";
            else
                word="Seven";
            break;
        case 8:
            if(dubDgt==true)
                word="Eighty-";
            else
                word="Eight";
            break;
        case 9:
            if(dubDgt==true)
                word="Ninety-";
            else
                word="Nine";
            break;
        case 10:
            word="Ten";
            break;
        case 11:
            word="Eleven";
            break;
        case 12:
            word="Twelve";
            break;
        case 13:
            word="Thirteen";
            break;
        case 14:
            word="Fourteen";
            break;
        case 15:
            word="Fifteen";
            break;
        case 16:
            word="Sixteen";
            break;
        case 17:
            word="Seventeen";
            break;
        case 18:
            word="Eighteen";
            break;
        case 19:
            word="Nineteen";
            break;
    }
    return word;
}

void empDestroy(Employee *ptr){
    delete []ptr;       //Deallocate memory.
}

void problem4(){    //Data encryption problem.
    int size=4,choice;  //Limit digits to 4. Store user choice.
    char data[size], again; //C-string and menu choice.
    char *dataPtr=data;     //Pointer
    do{
        cout<<"Data Encryption Software 2019\n";
        cout<<"This program encrypts and decrypts four digit integers within the octal number system.\n";
        cout<<"1. Encrypt\n2. Decrypt\n";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            getEncryptData(dataPtr,size);
            encrypt(dataPtr,size);
        }
        else if(choice==2){
            getEncryptData(dataPtr,size);
            decrypt(dataPtr,size);
        }
        cout<<"Would you like to input another number? (Y/N)";
        cin>>again;
    } while(toupper(again)!='N');
    dataPtr=nullptr;    //Unassign pointer.
}

void getEncryptData(char* dataPtr, int size){
    cout<<"Enter a four digit integer: ";  
    cin.getline(dataPtr, size+1);   //Get number.
    for(int i=0; i<size;i++){
        if(dataPtr[i]>='8'){    //Input validation. Number must be 0-7
            i=size; //Stop for-loop.
            cout<<"Invalid input. Enter a four digit value using only 0-7.\n";  //Inform user.
            getEncryptData(dataPtr,size);   //Recall this function.
        }
    }
}

void encrypt(char *dataPtr,int size){
    int value;  //Temporarily store data for computation.
    for(int add=0;add<size;add++){  //Pass data from c-string to int.
        value=dataPtr[add]-48;  //Factor for ascii.
        value=(value+5)%8;      //Add 5 and mod the sum by 8.
        dataPtr[add]=value+48;  //Pass data back to c-string.
    }
    swap(dataPtr[0], dataPtr[2]);   //Swap element 0 and 2
    swap(dataPtr[1], dataPtr[3]);   //Swap element 1 and 3.
    
    for(int num=0;num<size;num++){
        cout<<dataPtr[num];         //Display new encrypted data.
    }
    cout<<endl;
}

void decrypt(char *dataPtr,int size){
    int val;    //Temp data storage.
    swap(dataPtr[0],dataPtr[2]);    //Swap data back.
    swap(dataPtr[1],dataPtr[3]);    //Swap data back.
    for(int count=0;count<size;count++){
        val=dataPtr[count]-48;  //Pass data to int for computing.
        val-=5;                 //Subtract 5.
        if(val<0){              //If result is negative, then digit was changed by modulus.
            val+=5;             //Add 5 back.
            val+=(8-5);         //Reverse modulus.
        }
        dataPtr[count]=val+48;  //Pass data back to c-string.
    }
    for(int num=0;num<size;num++){
        cout<<dataPtr[num];     //Display decrypted data.
    }
    cout<<endl;
}

void problem5(){
    cout<<"Factorials of Primitive Data Types\n";
    cout<<setw(15)<<right<<"short"<<setw(16)<<"8th Factorial"<<endl;
    cout<<setw(15)<<right<<"unsigned"<<setw(16)<<"8th Factorial"<<endl;
    cout<<setw(15)<<right<<"int"<<setw(16)<<"13th Factorial"<<endl;
    cout<<setw(15)<<right<<"unsigned"<<setw(16)<<"13th Factorial"<<endl;
    cout<<setw(15)<<right<<"long"<<setw(16)<<"13th Factorial"<<endl;
    cout<<setw(15)<<right<<"unsigned"<<setw(16)<<"13th Factorial"<<endl;
    cout<<setw(15)<<right<<"float"<<setw(16)<<"35th Factorial"<<endl;
    cout<<setw(15)<<right<<"double"<<setw(16)<<"171st Factorial"<<endl;
}
void problem6(){
    cout<<"\tConverting Bases"<<endl;
    cout<<setw(18)<<left<<"(Base 10) 2.875"<<setw(20)<<right<<"0.1796875"<<endl;
    cout<<setw(18)<<left<<"(Base  2) 10.111"<<setw(20)<<right<<"0.0010111"<<endl;
    cout<<setw(18)<<left<<"(Base  8) 2.7"<<setw(20)<<right<<"0.134"<<endl;
    cout<<setw(18)<<left<<"(Base 16) 2.F"<<setw(20)<<right<<"0.2E"<<endl;
    cout<<setw(12)<<left<<" 2.875"<<setw(24)<<"0101 1100|0000 0000|0000 0000|1111 1101"<<endl;
    cout<<setw(12)<<left<<"-2.875"<<setw(24)<<"1101 1100|0000 0000|0000 0000|1111 1101"<<endl;
    cout<<setw(12)<<" 0.1796875:"<<setw(24)<<"0101 1100|0000 0000|0000 0000|1111 1110"<<endl;
    cout<<setw(12)<<"-0.1796875:"<<setw(24)<<"1101 1100|0000 0000|0000 0000|1111 1110"<<endl;
}
void problem7(){
}
