//============================================================================
// Name        : BinaryDecimalHexConverter.cpp
// Author      : Aaron Jay Macaldo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int decimalToBinary(int);
int binaryToDecimal(string);
string decimalToHex(int);
int hexToDecimal(string);

int main() {
	int userInput = 0;
	int decimal = 0;
	string binary = "";
	string hex = "";


	while(userInput != 9) {
		cout << "Choose and enter one of the following conversion items (1-5) or press 9 to exit: " << endl;
		cout << "1) Decimal to Binary Conversion" << endl;
		cout << "2) Binary to Decimal Conversion" << endl;
		cout << "3) Decimal to Hexadecimal Conversion" << endl;
		cout << "4) Hexadecimal to Decimal Conversion" << endl;
		cout << "9) Exit Program" << endl;
		cin >> userInput;
		cout << endl;

		if(userInput == 1) {
			cout << "Please enter a positive decimal number:" << endl;
			cin >> decimal;

			if(decimal >= 0) {
				cout << "The binary of " << decimal << " is: " << decimalToBinary(decimal) << endl;
			}
		}
		else if(userInput == 2) {
			cout << "Please enter a binary number (1's and 0's): " << endl;
			cin >> binary;

			if(binary.size() > 8) {
				cout << "Error: You typed more than 8 bits" << endl;
				continue;
			}

			for(int i = 0; i < binary.size(); i++) {
				if(binary[i] != '1' && binary[i] != '0') {
					cout << "Error: You entered a number other than 1 or 0" << endl;
					break;
				}
				if(i == binary.size()-1) {
					cout << "The decimal of " << binary << " is: " << binaryToDecimal(binary) << endl;
				}
			}
		}
		else if(userInput == 3) {
			cout << "Please enter a positive decimal number:" << endl;
			cin >> decimal;

			if(decimal >= 0) {
				cout << "The hexadecimal of " << decimal << " is: " << decimalToHex(decimal) << endl;
			}
		}

		else if(userInput == 4) {
			cout << "Please enter a hexadecimal number (0-9,a,b,c,d,e,f): " << endl;
			cin >> hex;

			if(hex.size() > 4) {
				cout << "Error: You entered more than 4 digits" << endl;
				continue;
			}

			for(int i = 0; i < hex.size(); i++) {
				if(hex[i] != '0' && hex[i] != '1' && hex[i] != '2' && hex[i] != '3' && hex[i] != '4' && hex[i] != '5' && hex[i] != '6' && hex[i] != '7' && hex[i] != '8' && hex[i] != '9'
						&& hex[i] != 'A' && hex[i] != 'B' && hex[i] != 'C' && hex[i] != 'D' && hex[i] != 'E' && hex[i] != 'F') {
					cout << "Error: You entered a number other than 0-9,a,b,c,d,e,f" << endl;
					break;
				}
				if(i == hex.size()-1) {
					cout << "The decimal of " << hex << " is: " << hexToDecimal(hex) << endl;
				}
			}


		}
		else {}

	}

//	int userInput = 0;
//	cout << "Enter a decimal number: ";
//	cin >> userInput;
//
//	cout << "The binary of " << userInput << " is: ";
//	cout << decimalToBinary(userInput) << endl;

//	string userInput = "";
//	cout << "Enter a binary number: ";
//	cin >> userInput;
//
//	cout << "The decimal of " << userInput << " is: ";
//	cout << binaryToDecimal(userInput) << endl;

//	int userInput = 654;
//	cout << "Enter a decimal number: ";
//	//cin >> userInput;
//
//	cout << "The hex of " << userInput << " is: ";
//	cout << decimalToHex(userInput) << endl;

//	string userInput = "";
//	cout << "Enter a hex number: ";
//	cin >> userInput;
//
//	cout << "The decimal of " << userInput << " is: ";
//	cout << hexToDecimal(userInput) << endl;








	cout << "Program Ending!" << endl;
	return 0;
}

int decimalToBinary(int theDecimal) {
	int returnBinary = 0;
	int counter = 0;

	while(theDecimal >= 1) {
		if(theDecimal%2 == 1) {
			returnBinary += pow(10, counter);
		}
		theDecimal = theDecimal / 2;
		counter++;
	}

	return returnBinary;
}

int binaryToDecimal(string theBinary) {
	int returnDecimal = 0;

	for(int i = 0; i < theBinary.size(); i++) {
		if(theBinary[theBinary.size()-1-i] == '1') {
			returnDecimal += pow(2, i);
		}
	}

	return returnDecimal;
}

string decimalToHex(int theDecimal) {
	string returnHex = "";
	string theChar;

	while(theDecimal >= 1) {
		if(theDecimal%16 < 10) {
			theChar = to_string(theDecimal%16);
			returnHex = theChar + returnHex;
		}
		else if(theDecimal%16 == 10) {
			returnHex.push_back('A');
		}
		else if(theDecimal%16 == 11) {
			returnHex.push_back('B');
		}
		else if(theDecimal%16 == 12) {
			returnHex.push_back('C');
		}
		else if(theDecimal%16 == 13) {
			returnHex.push_back('D');
		}
		else if(theDecimal%16 == 14) {
			returnHex.push_back('E');
		}
		else if(theDecimal%16 == 15) {
			returnHex.push_back('F');
		}
		else {}
		theDecimal = theDecimal/16;
	}

	return returnHex;
}

int hexToDecimal(string theHex) {
	int returnDecimal = 0;

	for(int i = 0; i < theHex.size(); i++) {
		if((theHex[theHex.size()-1-i]-48) < 10) {
			returnDecimal += (theHex[theHex.size()-1-i]-48) * pow(16, i);
		}
		else if(theHex[theHex.size()-1-i] == 'A') {
			returnDecimal += 10 * pow(16, i);
		}
		else if(theHex[theHex.size()-1-i] == 'B') {
			returnDecimal += 11 * pow(16, i);
		}
		else if(theHex[theHex.size()-1-i] == 'C') {
			returnDecimal += 12 * pow(16, i);
		}
		else if(theHex[theHex.size()-1-i] == 'D') {
			returnDecimal += 13 * pow(16, i);
		}
		else if(theHex[theHex.size()-1-i] == 'E') {
			returnDecimal += 14 * pow(16, i);
		}
		else if(theHex[theHex.size()-1-i] == 'F') {
			returnDecimal += 15 * pow(16, i);
		}
		else{}
	}

	return returnDecimal;
}
