#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

double ship, total, ordertot;//double allows these variables to be stored as decimals 
char userInput;
const char period = '.'; const char dash = '-';	//variables needed to create periods and dashes in code 
string NameOfItem, dest;

//These are the variables that will be included with the shipping costs 
const double BigOrder = 0.00;
const double smallUSA = 6.00;
const double smallCAN = 8.00;
const double smallAUS = 10.00;
const double smallJUP = 12.00;
const double mediumUSA = 9.00;
const double mediumCAN = 12.00;
const double mediumAUS = 14.00;
const double mediumJUP = 16.00;
const double largeUSA = 12.00;
const double largeCAN = 15.00;
const double largeAUS = 17.00;
const double largeJUP = 21.00;
const double fragile = 2.00;

//These are the variables that are used for the price 
const double mediummin = 50.01;
const double mediummax = 100.01;
const double largemax = 150.00;

int main() {
	cout << setw(50) << setfill(period) << period << endl;// This part shows the beginning of the Program as the introduction
	cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
	cout << setw(50) << setfill(period) << period << endl;
	cout << endl;
	cout << endl;

	cout << left << setw(49) << setfill(period) << "Please enter the item name (no spaces)" << ":";//This is where the user puts in a name for an item
	cin >> NameOfItem;

	cout << left << setw(49) << setfill(period) << "Is the item fragile? (y=yes/n=no)" << ":";//User is asked if item is fragile they put y or n for yes or no
	cin >> userInput;
	switch (userInput)
	{
	case 'Y':
		ship = ship + fragile;
		break;
	case 'y':
		ship = ship + fragile;
		break;
	case 'N':
		break;
	case 'n':
		break;
	default:
		cout << endl;
		cout << "Invalid entry, exiting";//if there is an entry other than y or n this part of the code allows the program to state as an invalid entry
		return 0;

	}
	cout << left << setw(49) << setfill(period) << "Please enter your order total" << ":";//order total is inputted here by user
	cin >> ordertot;

	cout << left << setw(49) << setfill(period) << "Please enter destination. (usa/can/aus/jup)" << ":";//the three options that are available as destinations for the shipment
	cin >> dest;
	if (dest == "usa" || dest == "can" || dest == "asu" || dest == "jup") {
		cout << endl;
	}
	else {
		cout << endl;
		cout << "Invalid entry, exiting";//This also allows the program to be invalid if the destination is not usa,can, or asu
		return 0;
	}

	transform(NameOfItem.begin(), NameOfItem.end(), NameOfItem.begin(), ::toupper);//This allows the item name to be capital letters
	cout << left << setw(40) << setfill(period) << "Your item is" << NameOfItem << endl;// This shows the output of the orginal item user types in 

// these statements allow the calculations to be made by the program in order to show the cost based on your order total
	if (ordertot < mediummin && dest == "usa") {
		ship = ship + smallUSA; 
	}
	else if (ordertot < mediummin && dest == "can") {
		ship = ship + smallCAN;
	}
	else if (ordertot < mediummin && dest == "aus") {
		ship = ship + smallAUS; 
	}
	else if (ordertot < mediummin && dest == "jup") {
		ship = ship + smallJUP;
	}
	else if (ordertot > mediummin && ordertot <= mediummax && dest == "usa") {
		ship = ship + mediumUSA;
	}
	else if (ordertot > mediummin && ordertot <= mediummax && dest == "can") {
		ship = ship + mediumCAN;
	}
	else if (ordertot > mediummin && ordertot <= mediummax && dest == "aus") {
		ship = ship + mediumAUS;
	}
	else if (ordertot > mediummin && ordertot <= mediummax && dest == "jup") {
		ship = ship + mediumJUP;
	}
	else if (ordertot > mediummax && ordertot <= largemax && dest == "usa") {
		ship = ship + largeUSA;
	}
	else if (ordertot > mediummax && ordertot <= largemax && dest == "can") {
		ship = ship + largeCAN;
	}
	else if (ordertot > mediummax && ordertot <= largemax && dest == "aus") {
		ship = ship + largeAUS;
	}
	else if (ordertot > mediummax && ordertot <= largemax && dest == "jup") {
		ship = ship + largeJUP;
	}
	else {
		ship = BigOrder;
	}

	cout << setw(40) << setfill(period) << "Your shipping cost is" << "$";
	cout << fixed << setprecision(2) << ship << endl;

	transform(dest.begin(), dest.end(), dest.begin(), ::toupper);//This allows the output of the destination to be in capital letters

	cout << left << setw(40) << setfill(period) << "Your are shipping to" << dest << endl;

	//The total shipping cost is calculated at the end
	total = ship + ordertot;

	cout << left << setw(40) << setfill(period) << "Your total shipping costs are" << "$" << total << endl;
	cout << endl;

	//This is the concluding statement 
	cout << setfill(dash) << setw(40) << dash;
	cout << "Thank You!" << endl;

}
