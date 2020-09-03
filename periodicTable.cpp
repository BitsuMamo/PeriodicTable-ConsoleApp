#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <string.h>

using namespace std;
// Constants
const int COLS = 18;
const int ROWS = 9;
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
    char symbol[3];
    char name[14];
    int atomicNumber;
    string classColor;
    string classification;
};

void mainMenu();
void subMenu();
void printTable(element periodicTable[][COLS]);
void searchRes(element periodicTable[][COLS], char target[]);
void searchRes(element periodicTable[][COLS], int atomicNumber);
string calcElecConfig(int atomicNumber);
void viewElement(element periodicTable[][COLS], int r, int c);
void noElement();

int main(){
    element periodicTable[ROWS][COLS] = 
		{
			{{"H", "Hydrogen", 1, NONMETAL[0], NONMETAL[1]},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {"He", "Helium", 2, NOBGAS[0], NOBGAS[1]}},
			{{"Li", "Lithium", 3, ALKMETAL[0], ALKMETAL[1]},
			 {"Be", "Beryilium", 4, ALKEARTH[0], ALKEARTH[1]},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {"B", "Boron", 5, METALLOID[0], METALLOID[1]},
			 {"C", "Carbon", 6, NONMETAL[0], NONMETAL[1]},
			 {"N", "Nitrogen", 7, NONMETAL[0], NONMETAL[1]},
			 {"O", "Oxygen", 8,  NONMETAL[0], NONMETAL[1]},
			 {"F", "Fluorine", 9, HALOGEN[0], HALOGEN[1]},
			 {"Ne", "Neon", 10, NOBGAS[0], NOBGAS[1]}},
			{{"Na", "Sodium", 11,  ALKMETAL[0], ALKMETAL[1]},
			 {"Mg", "Magnesium", 12, ALKEARTH[0], ALKEARTH[1]},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {""},
			 {"Al", "Aluminum", 13, BASICMETAL[0], BASICMETAL[1]},
			 {"Si", "Silicon", 14, METALLOID[0], METALLOID[1]},
			 {"P", "Phosphorus", 15, NONMETAL[0], NONMETAL[1]},
			 {"S", "Sulfur", 16, NONMETAL[0], NONMETAL[1]},
			 {"Cl", "Chlorine", 17, HALOGEN[0], HALOGEN[1]},
			 {"Ar", "Argon", 18,  NOBGAS[0], NOBGAS[1]}},
			{{"K", "Potassium", 19, ALKMETAL[0], ALKMETAL[1]},
			 {"Ca", "Calcium", 20, ALKEARTH[0], ALKEARTH[1]},
			 {"Sc", "Scandium", 21, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ti", "Titanium", 22, TRANSMETAL[0], TRANSMETAL[1]},
			 {"V", "Vanadium", 23,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Cr", "Chromium", 24, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Mn", "Manganese", 25, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Fe", "Iron", 26, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Co", "Cobalt", 27, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ni", "Nickel", 28, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Cu", "Copper", 29, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Zn", "Zinc", 30,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ga", "Gallium", 31,BASICMETAL[0], BASICMETAL[1]},
			 {"Ge", "Germanium", 32, NONMETAL[0], NONMETAL[1]},
			 {"As", "Arsenic", 33, METALLOID[0], METALLOID[1]},
			 {"Se", "Selenium", 34, NONMETAL[0], NONMETAL[1]},
			 {"Br", "Bromine", 35, HALOGEN[0], HALOGEN[1]},
			 {"Kr", "Krypton", 36, NOBGAS[0], NOBGAS[1]}},
			{{"Rb", "Rubuduium", 37,ALKMETAL[0], ALKMETAL[1]},
			 {"Sr", "Strontium", 38, ALKEARTH[0], ALKEARTH[1]},
			 {"Y", "Yttrium", 39,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Zr", "Zirconium", 40, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Nb", "Niobium", 41, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Mo", "Molybdenum", 42, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Tc", "Technetium", 43, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ru", "Ruthenium", 44 , TRANSMETAL[0], TRANSMETAL[1]},
			 {"Rh", "Rhodium", 45,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Pd", "Palladium", 46, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ag", "Silver", 47,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Cd", "Cadium", 48, TRANSMETAL[0], TRANSMETAL[1]},
			 {"In", "Indium", 49,  BASICMETAL[0], BASICMETAL[1]},
			 {"Sn", "Tin", 50,  BASICMETAL[0], BASICMETAL[1]},
			 {"Sb", "Antimony", 51, METALLOID[0], METALLOID[1]},
			 {"Te", "Tellurium", 52, METALLOID[0], METALLOID[1]},
			 {"I", "Iodine", 53,  HALOGEN[0], HALOGEN[1]},
			 {"Xe", "Xenon", 54,  NOBGAS[0], NOBGAS[1]}},
			{{"Cs", "Cesium", 55, ALKMETAL[0], ALKMETAL[1]},
			 {"Ba", "Barium", 56, ALKEARTH[0], ALKEARTH[1]},
			 {"->", "", 0, "", LAT[0]},
			 {"Hf", "Hafnium", 72, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ta", "Tantalum", 73, TRANSMETAL[0], TRANSMETAL[1]},
			 {"W", "Tungsten", 74, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Re", "Rhenium", 75, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Os", "Osmium", 76,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ir", "Iridium", 77, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Pt", "Platinum", 78,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Au", "Gold", 79,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Hg", "Mercury", 80,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Tl", "Thallium", 81, BASICMETAL[0], BASICMETAL[1]},
			 {"Pb", "Lead", 82, BASICMETAL[0], BASICMETAL[1]},
			 {"Bi", "Bismuth", 83,  BASICMETAL[0], BASICMETAL[1]},
			 {"Po", "Polonium", 84, METALLOID[0], METALLOID[1]},
			 {"At", "Asttatine", 85, HALOGEN[0], HALOGEN[1]},
			 {"Rn", "Radon", 86,  NOBGAS[0], NOBGAS[1]}},
			{{"Fr", "Francium", 87, ALKMETAL[0], ALKMETAL[1]},
			 {"Ra", "Radium", 88, ALKEARTH[0], ALKEARTH[1]},
			 {"=>", "", 0, "", ACT[0]},
			 {"Rf", "Rutherfordium", 104, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Db", "Dubnium", 105, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Sg", "Seaborgium", 106,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Bh", "Bohrium", 107,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Hs", "Hassium", 108,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Mt", "Meitnerium", 109, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Ds", "Darmastadtium", 110,  TRANSMETAL[0], TRANSMETAL[1]},
			 {"Rg", "Roentgenium", 111, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Cn", "Copernicium", 112, TRANSMETAL[0], TRANSMETAL[1]},
			 {"Nh", "Nihonium", 113,  BASICMETAL[0], BASICMETAL[1]},
			 {"Fl", "Flerovium", 114, BASICMETAL[0], BASICMETAL[1]},
			 {"Mc", "Moscovium", 115, BASICMETAL[0], BASICMETAL[1]},
			 {"Lv", "Livermorium", 116, BASICMETAL[0], BASICMETAL[1]},
			 {"Ts", "Tennessine", 117,  HALOGEN[0], HALOGEN[1]},
			 {"Og", "Oganesson", 118, NOBGAS[0], NOBGAS[1]}},
			{{""},
			 {"->", "", 0, "", LAT[0]},
			 {"La", "Lanthanum", 57, LAT[0], LAT[1]},
			 {"Ce", "Cerium", 58, LAT[0], LAT[1]},
			 {"Pr", "Praseodyium", 59, LAT[0], LAT[1]},
			 {"Nd", "Neodymium", 60,  LAT[0], LAT[1]},
			 {"Pm", "Promethium", 61, LAT[0], LAT[1]},
			 {"Sm", "Samarium", 62,  LAT[0], LAT[1]},
			 {"Eu", "Europium", 63,  LAT[0], LAT[1]},
			 {"Gd", "Gadolinium", 64, LAT[0], LAT[1]},
			 {"Tb", "Terbium", 65, LAT[0], LAT[1]},
			 {"Dy", "Dysporosium", 66, LAT[0], LAT[1]},
			 {"Ho", "Holmium", 67,  LAT[0], LAT[1]},
			 {"Er", "Erbium", 68,  LAT[0], LAT[1]},
			 {"Tm", "Thulium", 69, LAT[0], LAT[1]},
			 {"Yb", "Ytterbium", 70, LAT[0], LAT[1]},
		    {"Lu", "Lutetium", 71, LAT[0], LAT[1]},
			 {""}},
			{{""},
			 {"=>", "", 0, ACT[0], ACT[1]},
			 {"Ac", "Actinium", 89, ACT[0], ACT[1]},
			 {"Th", "Thorium", 90,  ACT[0], ACT[1]},
			 {"Pa", "Protactinium", 91, ACT[0], ACT[1]},
			 {"U", "Uraniuim", 92, ACT[0], ACT[1]},
			 {"Np", "Neptunium", 93, ACT[0], ACT[1]},
			 {"Pu", "Plutonium", 94, ACT[0], ACT[1]},
			 {"Am", "Americium", 95, ACT[0], ACT[1]},
			 {"Cm", "Curium", 96, ACT[0], ACT[1]},
			 {"Bk", "Berkelium", 97, ACT[0], ACT[1]},
			 {"Cf", "Californium", 98, ACT[0], ACT[1]},
			 {"Es", "Einsteinium", 99, ACT[0], ACT[1]},
			 {"Fm", "Fermium", 100,  ACT[0], ACT[1]},
			 {"Md", "Mendelevium", 101, ACT[0], ACT[1]},
			 {"No", "Nobelium", 102,  ACT[0], ACT[1]},
			 {"Lr", "Lawrencium", 103, ACT[0], ACT[1]},
			 {""}}};
    int choice;
    int subChoice;
    do{
        mainMenu();
        cin>>choice;
        switch(choice){
            case 1:
                // Gets periodicTable;
                printTable(periodicTable);
                break;
            case 2:
                // For search
                do{
                    subMenu();
                    cin>>subChoice;
                    switch(subChoice){
                        case 1:
                            char target_1[14];
                            cout<<"Input: ";
                            cin>>target_1;
                            searchRes(periodicTable, target_1);

                            break;
                        case 2:
                            int target_2;
                            cout<<"Input: ";
                            cin>>target_2;
                            searchRes(periodicTable, target_2);

                            break;
                        default:
                            break;
                    }
                }while((subChoice < 1 && subChoice > 2) || subChoice  != 0);

                break;
            default:
                break;
        }
    }while((choice < 1 && choice > 2) || choice  != 0);

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
}
void subMenu(){
    system("cls");
	cout << "+----------------------------+" << endl;
	cout << setw(1) << "|" << setw(28) << "*Search is case sensitive*" << setw(1) << "|" << endl;
	cout << "+--+-------------------------+" << endl;
	cout << setw(1) << "|" << setw(2) << "0." << setw(1) << "|" << setw(25) << left << "Go Back" << setw(1) << "|" << endl;
	cout << "+--+-------------------------+" << endl;
	cout << setw(1) << "|" << setw(2) << "1." << setw(1) << "|" << setw(25) << left << "Search By Name and Symbol" << setw(1) << "|" << endl;
	cout << "+--+-------------------------+" << endl;
	cout << setw(1) << "|" << setw(2) << "2." << setw(1) << "|" << setw(25) << left << "Search By Atomic Number" << setw(1) << "|" << endl;
	cout << "+--+----+--------------------+" << endl;
	cout << setw(1) << "|"<< "Choice" << setw(7) << " |";
}


void searchRes(element periodicTable[][COLS], int atomicNumber){
    bool exists = false;
    for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++c){
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
        for(int c = 0; c < COLS; ++c){
            if(strcmpi(target, periodicTable[r][c].symbol) == 0 || strcmpi(target, periodicTable[r][c].name) == 0){
                viewElement(periodicTable, r, c);
                exists = true;
            }
        }
    }
    if(!exists){
       noElement(); 
    }
}
//TODO: check on how to change intger to string
string calcElecConfig(int atomicNumber){
    string config = "";
	if (atomicNumber <= 2){
        config += atomicNumber;
	}
	else if (atomicNumber > 2 && atomicNumber <= 10){
        config += "2,";
        config += atomicNumber - 2;
    }
	else{
        config += "2";
		atomicNumber = atomicNumber - 2;
		// Creating temporary atomic number to do claculations on
		int atmp = atomicNumber;
		for (int i = 0; i < (atomicNumber / 8); i++){
            config += ",8";
			atmp -= 8;
		}
		if (atmp != 0){
            config += "," + atmp;
		}
	}
    return config;
}
//This is for output so can do it later
void viewElement(element periodicTable[][COLS], int i, int j){
	// Output of search result
    system("cls");
	cout << periodicTable[i][j].classColor;
	cout << "+------------------------------------------------+" << endl;
	cout << setw(1) << "|" << left << setw(18) << "Symbol " << setw(1) << "|" << right << setw(29) << periodicTable[i][j].symbol<< setw(1) << "|" << endl;
	cout << "+------------------+-----------------------------+" << endl;
	cout << setw(1) << "|" << left << setw(18) << "Name " << setw(1) << "|" << right << setw(29) << periodicTable[i][j].name<< setw(1) << "|" << endl;
	cout << "+------------------+-----------------------------+" << endl;
	cout << setw(1) << "|" << left << setw(18) << "Atomic Number " << setw(1) << "|" << right << setw(29) << periodicTable[i][j].atomicNumber<< setw(1) << "|" << endl;
	cout << "+------------------+-----------------------------+" << endl;
	cout << setw(1) << "|" << left << setw(18) << "Config" << setw(1) << "|" << right << setw(29) << calcElecConfig(periodicTable[i][j].atomicNumber)<< setw(1) << "|" << endl;
    cout << "+------------------+-----------------------------+" << endl;
	cout << setw(1) << "|" << left << setw(18) << "Classification " << setw(1) << "|" << right << setw(29) << periodicTable[i][j].classification<< setw(1) << "|" << endl;
	cout << "+------------------+-----------------------------+" << endl;
    system("pause");
    cout<<RESET;
}

void noElement(){
	cout << "+-----------------+" << endl;
	cout << "|"<< "No Element Found"<< "|" << endl;
	cout << "+-----------------+" << endl;
}

void printTable(element periodicTable[][COLS]){
			// For loop to display the periodic table
			system("cls");
            // Group Number 
			cout << setw(5) << " " << setw(5) << left << "1" << setw(5) << left << "2" << setw(5) << left << "3" << setw(5) << left << "4" << setw(5) << left << "5" << setw(5) << left << "6" << setw(5) << left << "7" << setw(5) << left << "8" << setw(5) << left << "9"
				 << setw(5) << "10" << setw(5) << "11" << setw(5) << "12" << setw(5) << left << "13" << setw(5) << left << "14" << setw(5) << left << "15" << setw(5) << left << "16" << setw(5) << left << "17" << setw(5) << left << "18" << endl;
			for (int i = 0; i < 9; i++)
			{
				// Output of period numbers
				if (i < 7)
				{
					cout << setw(2) << left << i + 1;
				}
				else
				{
					// Consideration of the last two rows which are not periods
					cout << setw(2) << left << "";
				}

				// Prints atomic number
				for (int k = 0; k < 18; k++)
				{
                    if(periodicTable[i][k].atomicNumber != 0){
                        cout <<  periodicTable[i][k].classColor << left << setw(4) << periodicTable[i][k].atomicNumber<< RESET << BOLDWHITE << "|" << RESET;
                    }else{
                        cout<<setw(5)<<" ";
                    }
				}
				cout << endl;

				// Correction of offset caused by the atomic numbers and period numbers
				cout << setw(2) << "";

				// Prints elements
				for (int j = 0; j < 18; j++)
				{
					cout << periodicTable[i][j].classColor << left << setw(4) << right << periodicTable[i][j].symbol << RESET << BOLDWHITE << "|" << RESET;
				}
				cout << endl;
				// Divider output between each row.
				cout << BOLDWHITE << "------+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+" << RESET << endl;
			}

			// Key that relates to color code and classification
			cout << setw(25) << " "
				 << "+----------------------------------+" << endl;
			cout << setw(23) << " " << setw(3) << "|" << ALKMETAL[0] << setw(17) << ALKMETAL[1] << RESET << "|" << ALKEARTH[0] << setw(14) << ALKEARTH[1] << RESET << setw(3) << "|" << endl;
			cout << setw(25) << " "
				 << "+-------------------+--------------+" << endl;
			cout << setw(23) << " " << setw(3) << "|" << TRANSMETAL[0] << setw(17) << TRANSMETAL[1] << RESET << "|" << BASICMETAL[0] << setw(14) << BASICMETAL[1] << RESET << setw(3) << "|" << endl;
			cout << setw(25) << " "
				 << "+-------------------+--------------+" << endl;
			cout << setw(23) << " " << setw(3) << "|" << METALLOID[0] << setw(17) << METALLOID[1] << RESET << "|" << NONMETAL[0] << setw(14) << NONMETAL[1] << RESET << setw(3) << "|" << endl;
			cout << setw(25) << " "
				 << "+-------------------+--------------+" << endl;
			cout << setw(23) << " " << setw(3) << "|" << HALOGEN[0] << setw(17) << HALOGEN[1] << RESET << "|" << NOBGAS[0] << setw(14) << NOBGAS[1] << RESET << setw(3) << "|" << endl;
			cout << setw(25) << " "
				 << "+-------------------+--------------+" << endl;
			cout << setw(23) << " " << setw(3) << "|" << LAT[0] << setw(17) << LAT[1] << RESET << "|" << ACT[0] << setw(14) << ACT[1] << RESET << setw(3) << "|" << endl;
			cout << setw(25) << " "
				 << "+----------------------------------+" << endl;

			system("pause");
} 
