#include"text_filtration.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include <sstream>


void textFiltration::showPlainText()
{
	printToScreen(fileContent);
}


std::string textFiltration::filePrepearing(std::ifstream &file, int &vectSize)
{
	std::stringstream strStream;
	strStream << file.rdbuf();
	std::string str = strStream.str();

	int pageSize = 10;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '\n')
		{
			str[i] = ' ';
		}
	}

	int dotCounter = 0;
	int k = 1;
	int sizeAllStr = str.size();
	for (int i = 0; i < sizeAllStr; i++)
	{
		if (str[i] == '.')
		{
			dotCounter++;
		}

		if (dotCounter / pageSize == k)
		{
			str.insert(i + 1, "\n");
			k++;
		}
	}

	str.push_back('\n');
	vectSize = k;

	return str;

}

void textFiltration::loadFromFile()
{
	std::ifstream infile("data.txt");

	int vectSize;

	if (infile)
	{

		std::string fileString = filePrepearing(infile, vectSize);
		infile.close();

		fileContent.resize(vectSize);
		int fileStringSize = fileString.size();
		int firstPos = 0, nextPos;
		for (int i = 0, j = 0; i < fileStringSize; i++)
		{
			if (fileString[i] == '\n')
			{
				nextPos = i + 1;
				fileContent[j] = fileString.substr(firstPos, nextPos - firstPos);
				firstPos = nextPos;
				j++;

			}
		}
	}
	else
	{
		std::cout << "Can't open file\n";
	}
}


void textFiltration::printToScreen(std::vector<std::string> src)
{
	int key;
	enum keyCode { ESC = 27, BACK = 75, FORVARD = 77 };
	int srcSize = src.size();
	int index = 0;

	system("cls");
	std::cout << src[0];
	do
	{
		key = _getch();
		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			if (key == BACK)
			{
				index--;
			}
			else if (key == FORVARD)
			{
				index++;
			}

			if (index < 0)
			{
				index = srcSize - 1;
			}
			else if (index > srcSize - 1)
			{
				index = 0;
			}

			system("cls");
			std::cout << src[index];
			
			std::cout << "\n\nPress ESC to exit.";
		}
	} while (key != ESC);

}

void textFiltration::punctuationFiltre()
{

	std::vector<std::string>::iterator iter;
	std::vector<std::string> withoutPunctuation = fileContent;
	int size = withoutPunctuation.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < withoutPunctuation[i].size(); j++)
		{
			if (iswpunct(withoutPunctuation[i].at(j)))
			{
				withoutPunctuation[i].at(j) = ' ';
			}
		}
	}

	printToScreen(withoutPunctuation);
}

void textFiltration::latinFiltre()
{
	std::vector<std::string>::iterator iter;
	std::vector<std::string> deleteLatinSymbols = fileContent;
	int size = deleteLatinSymbols.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < deleteLatinSymbols[i].size(); j++)
		{
			if (iswalpha(deleteLatinSymbols[i].at(j)))
			{
				deleteLatinSymbols[i].at(j) = ' ';
			}
		}
	}

	printToScreen(deleteLatinSymbols);
}
void textFiltration::rusFiltre()
{

	std::vector<std::string>::iterator iter;
	std::vector<std::string> deleteRusSymbols = fileContent;
	int size = deleteRusSymbols.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < deleteRusSymbols[i].size(); j++)
		{
			if (deleteRusSymbols[i].at(j) >= 'à' && deleteRusSymbols[i].at(j) <= 'ÿ' ||
				deleteRusSymbols[i].at(j) >= 'À' && deleteRusSymbols[i].at(j) <= 'ß')
			{
				deleteRusSymbols[i].at(j) = ' ';
			}
		}
	}

	printToScreen(deleteRusSymbols);

}

void textFiltration::numberFiltre()
{
	std::vector<std::string>::iterator iter;
	std::vector<std::string> deleteNumbers = fileContent;
	int size = deleteNumbers.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < deleteNumbers[i].size(); j++)
		{
			if (iswdigit(deleteNumbers[i].at(j)))
			{
				deleteNumbers[i].at(j) = ' ';
			}
		}
	}

	printToScreen(deleteNumbers);
}