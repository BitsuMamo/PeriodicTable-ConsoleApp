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
const string LAT[2] = {"\033[31m", "Lanthanide"};					  /* Red */
const string ALKMETAL[2] = {"\033[32m", "Alkali Metal"};			  /* Green */
const string ALKEARTH[2] = {"\033[34m", "Alkali Earth"};			  /* Blue */
const string HALOGEN[2] = {"\033[35m", "Halogen"};					  /* Magenta */
const string NOBGAS[2] = {"\033[36m", "Noble Gas"};					  /* Cyan */
const string ACT[2] = {"\033[1m\033[31m", "Actinide"};				  /* Bold LAT */
const string TRANSMETAL[2] = {"\033[1m\033[32m", "Transition Metal"}; /* Bold ALKMETAL */
const string BASICMETAL[2] = {"\033[1m\033[34m", "Basic Metal"};	  /* Bold ALKEARTH */
const string NONMETAL[2] = {"\033[1m\033[35m", "Non Metal"};		  /* Bold MAGENTA */
const string METALLOID[2] = {"\033[1m\033[36m", "Metalloid"};		  /* Bold Cyan */

struct element{
    char name[14];
    char symbol[2];
    int atomicNumber;
    char classification[20];
    char colorCode[20];   
};

void mainMenu();
void periodicTable();
void searchRes(string nameSymbol);
void searchRes(int atomicNumber);
string calcElecConfig(int atomicNumber);

int main(){
    element periodicTable =  
    int input;
    do{
        mainMenu();
        cin>>input;
        switch(input){
            case 1:
                // Gets periodicTable;
                periodicTable();
                break;
            case 2:
                //TODO: Research how to get value of any type auto
                // Gets search result of a specific target;
                cout<<"Input search target(Name, Symbol, Atomic Number)";
                //auto target = cin;
                //cin>>target;
                //searchRes(target);
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

void periodicTable(){} // Did it but need some revision maybe an overhall

void searchRes(int atomicNumber){} 

void searchRes(char nameSymbol){}

string calcElecConfig(int atomicNumber){} // Already did it
