// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#include <iostream>
#include <conio.h>
#include <fstream>

#include "helpers.h"
//#include "Board.h"

using namespace std;

char input;

//Initialise FileIO
ofstream outStream;
ifstream inStream;

//Array containing current game state
//string currentGameState[20];

//Returns a boolean specifying if the user wants to quit or not.
bool quitGame()
{
	clearScreen();
	cout << "Are you sure you want to quit? (Y/N) \n";
	
	input = _getch();

	if (input == 'y' || input == 'Y')
	{
		clearScreen();
		return true;
	}
	else
	{
		return false;
	}
}

/*void saveGame()
{
	cout << "Save game? This will overwrite any previous saves. (Y/N)" << endl;

	input = _getch();

	if (input == 'y' || input == 'Y')
	{
		outStream.open("save.txt");

		if (outStream.fail())
		{
			cout << "Error Saving" << endl;
		}

		for (int i = 0; i < 20; i++)
		{
			outStream << currentGameState[i] << endl;
		}

		outStream <<  << endl;

		outStream.close();

	}

	clearScreen();
}

void loadGameFromSave()
{
	//Open text file, check for errors.
	string save = "save.txt";
	inStream.open(save);
	if (inStream.fail())
	{
		//Convert to C-String to comply with perror function parameters.
		const char * fileCString = save.c_str();
		perror(fileCString);
		cout << endl;
		return;
	}

	//Load game state
	string line;
	for (int x = 0; x < 20; x++)
	{
		getline(inStream, line);
		currentGameState[x] = line;
	}

	inStream.close();

	displayAlienAttributes(currentGameState)
}*/