#include"text_filtration.h"

#include <iostream>
#include <windows.h>



void mainMenu(int &choise)
{
	system("cls");
	std::cout << "1. Show text without modification.\n";
	std::cout << "2. Clear punctuation.\n";
	std::cout << "3. Clear English symbols.\n";
	std::cout << "4. Clear Russian symbols.\n";
	std::cout << "5. Clear numbers.\n";
	std::cout << "6. Exit.\n";

	std::cout << "Press number of action: ";
	std::cin >> choise;
}

int main()
{
	std::locale::global(std::locale(""));
	enum action {PLAIN = 1, PUNCT, ENG, RUS, NUM,  EXIT};
	textFiltration obj;

	int userChoise = 0;

	obj.loadFromFile();

	do
	{
		mainMenu(userChoise);

		switch (userChoise)
		{
		case PLAIN:
			obj.showPlainText();
			break;
		case PUNCT:
			obj.punctuationFiltre();
			break;
		case ENG:
			obj.latinFiltre();
			break;
		case RUS:
			obj.rusFiltre();
			break;
		case NUM:
			obj.numberFiltre();
			break;
		default:
			if (userChoise != EXIT)
			{
				std::cout << "Nonexistent command!!!\n";
				Sleep(2000);
			}

			break;
		}

	} while (userChoise != EXIT);
	
	
	return 0;
}