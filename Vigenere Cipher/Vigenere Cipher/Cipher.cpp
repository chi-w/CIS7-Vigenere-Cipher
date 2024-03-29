#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

bool checkAlpha(std::string);	// input veritification function
std::string get_key_string(std::string, int);
std::string encrypt(std::string, std::string); // function that deals encryption
int ASCII_to_int(char);
string decrypt(string input, string keyString);   // function that deals decryption
void calldecrept();

int main()
{
	string name; // The user giving their name
	int num;  // Having to have the user pick a choice
	char letter; // for the part that will end the do while loop


	std::string key;	// variable to hold the key user input 
	std::string keyString = "";	// generated by repeating key 
	std::string shift = "";
	std::string plaintext;	//	plaintext input
	std::string encrypted = "";		// output
	int textLength = 0; //	initialize variable textLength


	do {

		cout << "Hi, welcome to the Cipher Machine! What is your name? ";
		getline(cin, name);

		cout << "Okay, " << name << ", What would you like to do? ";
		cout << "\n1) Would you like to Encrypt.";
		cout << "\n2) Would you like to Decrypt.\n";
		cin >> num;

		if (num == 1 || num == 2)
		{
			switch (num)
			{
			case 1:
				// This is an encrypton demo
				std::cout << "Enter a key in English aphabet: ";
				std::cin >> key;
				// veritify the key by calling the checkAlpha function
				while (!checkAlpha(key))
				{
					std::cout << "Only enter English alphabet characters; please enter another key\n";
					std::cin >> key;

				}

				std::cout << "Enter the message you want to encrypt: ";
				std::cin >> plaintext;
				while (!checkAlpha(plaintext))
				{
					std::cout << "Only enter English alphabet characters; please enter another message\n";
					std::cin >> plaintext;
				}
				// if the length of key is shorter than that of plaintext, repeat the key

				textLength = plaintext.length();	// Assign a value to textLength
													// Assign variable keyString a value by calling get_key_string function
				keyString = get_key_string(key, textLength);
				// call the encrypt function to and assign the return value to the encrypted variable
				encrypted = encrypt(plaintext, keyString);
				std::cout << "The encrypted text is " << encrypted << endl; ;
				break;
			case 2:
				calldecrept();
				break;
			default: cout << "Error!";
			}
		}
		else
		{
			cout << "You did not select the right number!\n";

		}

		cout << "Would you like to restart? (Y/N)\n";
		cin >> letter;
		if (toupper(letter))
		{
			system("cls");
		}
		cin.ignore();
	} while (letter == 'y' || letter == 'Y');


	system("pause");
	return 0;
}


bool checkAlpha(std::string input)
{
	bool flag = true;
	for (int i = 0; i < input.length() && flag == true; ++i)
	{
		if (isalpha(input[i]))
			flag = 1;
		else
			flag = 0;
	}
	return flag;
}

std::string get_key_string(std::string key, int textLength)
{
	std::string keyString = "";
	if (key.length() < textLength)
	{
		for (int i = 0, j = 0; i < textLength; ++i, ++j)
		{
			j %= key.length();
			keyString += key[j];
		}
		return keyString;
	}
	else
	{
		for (int i = 0; i < textLength; ++i)
			keyString += key[i];
		return keyString;
	}

}

std::string encrypt(std::string input, std::string keyString)
{
	// initialize a string
	std::string encrypted = "";

	for (int i = 0; i < input.length(); ++i)
	{
		char keyword = keyString[i]; // initilize a varible shift assigned to each key characters of the keyString
		int shift = ASCII_to_int(keyword);
		if (isupper(input[i]))
			encrypted += char((input[i] - 65 + shift) % 26 + 65);
		else
			encrypted += char((input[i] - 97 + shift) % 26 + 97);
	}
	return encrypted;

}

string decrypt(string input, string keyString)
{
	// initialize a string
	std::string decrypted = "";

	for (int i = 0; i < input.length(); ++i)
	{
		char keyword = keyString[i]; // initilize a varible shift assigned to each key characters of the keyString
		int shift = ASCII_to_int(keyword);
		if (isupper(input[i]))
			decrypted += char((abs(input[i] - 65 - shift)) % 26 + 65);
		else
			decrypted += char((abs(input[i] - 97 - shift)) % 26 + 97);
	}
	return decrypted;
}

// function to convert key character to their relative position on alphabet table

int ASCII_to_int(char key)
{
	if (isupper(key))
		return key -= 65; // since the restrict on the range of key (only alphabet characters), and since 65 and 97 will not chage
						  // in the course of the program; the overflow warning can be ignored

	else if (islower(key))
		return key -= 97;

}

void calldecrept()
{
	std::string cipherText;
	std::string key;
	std::string keyString;
	std::string decrepted;
	int textLength = 0;
	std::cout << "Enter a key in English aphabet: ";
	std::cin >> key;
	// veritify the key by calling the checkAlpha function
	while (!checkAlpha(key))
	{
		std::cout << "Only enter English alphabet characters; please enter another key\n";
		std::cin >> key;

	}

	std::cout << "Enter the message you want to decrypt: ";
	std::cin >> cipherText;
	while (!checkAlpha(cipherText))
	{
		std::cout << "Only enter English alphabet characters; please enter another message\n";
		std::cin >> cipherText;
	}
	// if the length of key is shorter than that of plaintext, repeat the key

	textLength = cipherText.length();	// Assign a value to textLength
										// Assign variable keyString a value by calling get_key_string function
	keyString = get_key_string(key, textLength);
	// call the encrypt function to and assign the return value to the encrypted variable
	decrepted = decrypt(cipherText, keyString);

	std::cout << "The decrepted message is: " << decrepted << '\n';
}
