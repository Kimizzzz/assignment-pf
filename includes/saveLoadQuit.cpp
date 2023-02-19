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
#include <fstream>

#include "helpers.h"
#include "display.h"

using namespace std;

// asking the user whether if he/she want to save the game or not

/*void saveGame()
{
	cout << "Enter the file name to save the game to(fileName.txt): ";
	cin >> fileName;

	ofstream saveFile;
	saveFile.open(fileName);
	if (saveFile.is_open())
	{
		saveFile << ;
		saveFile << ;

		saveFile.close();

		cout << "Game Saved";
	}
	system("pause");
}*/

// loads the game from the saved file

void loadGame()
{
	char choice;

	cout << "Do you want to save the game?(y/n): ";
	cin >> choice;

	if(choice == 'y')
	{
		void saveGame();
	}
	else
	{	
		resetDisplay();
		clearScreen();
		string fileName;

		cout << "Enter the file name to load the game from(fileName.txt): ";
		cin >> fileName;

		ifstream loadFile;
		loadFile.open(fileName);
		if (loadFile.is_open())
		{
			string line;

			while(getline(loadFile, line))
			{
				cout << line << endl;
			}
			loadFile.close();

			cout << "Game Loaded" << endl;
		}
		system("pause");
	}
}

// asking the user whether if he/she want to quit the game or not

bool quitGame()
{
	char choice;
	cout << "Are you sure you want to quit the game?(y/n): ";
	cin >> choice;

	if (choice == 'y')
	{
		bool flag = true;
		resetDisplay();
		clearScreen();
		flag = false;
	}
	else
	{
		// returns to the game
	}
	resetDisplay();
	return 0;
}