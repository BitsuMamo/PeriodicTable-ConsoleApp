#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

// Constants colors
const string RESET = "\033[0m";
const string BOLDWHITE = "\033[1m\033[37m";

// Array constants for colors and classification
const string LAT[2] = {"\033[31m", "Lanthanide"};
const string ALKMETAL[2] = {"\033[32m", "Alkali Metal"};
const string ALKEARTH[2] = {"\033[34m", "Alkali Earth"};
const string HALOGEN[2] = {"\033[35m", "Halogen"};	
const string NOBGAS[2] = {"\033[36m", "Noble Gas"};
const string ACT[2] = {"\033[1m\033[31m", "Actinide"};
const string TRANSMETAL[2] = {"\033[1m\033[32m", "Transition Metal"};
const string BASICMETAL[2] = {"\033[1m\033[34m", "Basic Metal"};	
const string NONMETAL[2] = {"\033[1m\033[35m", "Non Metal"};	
const string METALLOID[2] = {"\033[1m\033[36m", "Metalloid"};

struct element{
    char name[14];
    char symbol[2];
    int atomicNumber;
    char classification[20];
    char colorCode[20];   
};

void mainMenu();
void periodicTable();
void searchRes(element periodicTable[][COLS], string nameSymbol);
void searchRes(element periodicTable[][COLS], int atomicNumber);
string calcElecConfig(int atomicNumber);
void viewElement(element periodicTable, int r, int c);
void noElement();

int main(){
    element periodicTable =  
    int choice;
    do{
        mainMenu();
        cin>>choice;
        switch(choice){
            case 1:
                // Gets periodicTable;
                periodicTable();
                break;
            case 2:
                subMenu();
                cin>>subChoice;
                switch(subChoice){
                    case 1:
                        char target[14];
                        cout<<"Input: ";
                        cin>>target;
                        searchRes(periodicTable, target);

                        break;
                    case 2:
                        int target;
                        cout<<"Input: ";
                        cin>>target;
                        searchRes(periodicTable, target);
        
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }while((input < 1 || input > 2) & input  != 0);

    return 0;
}

void mainMenu(){
	system("cls");
	cout << "+-------------------------+" << endl;
	cout << setw(1) << "|" << setw(2) << "0." << setw(1) << "|" << setw(22) << left << "To Exit" << setw(1) << "|" << endl;
	cout << "+--+----------------------+" << endl;
	cout << setw(1) << "|" << setw(2) << "1." << setw(1) << "|" << setw(22) << left << "Modern Periodc Table" << setw(1) << "|" << endl;
	cout << "+--+----------------------+" << endl;
	cout << setw(1) << "|" << setw(2) << "2." << setw(1) << "|" << setw(22) << left << "Elemental Search" << setw(1) << "|" << endl;
	cout << "+--+----+-----------------+" << endl;
	cout << setw(1) << "|" << "Choice" << setw(5) << " |";
}// Already did it


void searchRes(element periodicTable[][COLS]int atomicNumber){
    bool exists = false;
    for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++C){
            if(atomicNumber == periodicTable[r][c].atomicNumber){
                viewElement(periodicTable, r, c);
                exists = true;
            }
        }
    }
    if(!exists){
       noElement(); 
    }
} 

void searchRes(element periodicTable[][COLS], char target[]){
    bool exists = false;
    for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++C){
            if(target == periodicTable[r][c].symbol || target == periodicTable[r][c].name){
                viewElement(periodicTable, r, c);
                exists = true;
            }
        }
    }
    if(!exists){
       noElement(); 
    }
}
//Copy form previous code
string calcElecConfig(int atomicNumber){
    string config = "";
    if(atomicNumber <= 2){
        config += atomicNumber;
    }
} // Already did it
//This is for output so can do it later
void viewElement(element periodicTable[][COLS], int r, int c){}

void noElement(){}

void printTable(){} // Did it but need some revision maybe an overhall
