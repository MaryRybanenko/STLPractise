#include <vector>
#include <string>
#include <fstream>



class textFiltration
{
private:
	std::vector<std::string> fileContent;
	int pageSize = 10;

	std::string filePrepearing(std::ifstream &file, int &vectSize);
	void printToScreen(std::vector<std::string> src);

public:
	void showPlainText();
	void loadFromFile();
	void latinFiltre();
	void rusFiltre();
	void punctuationFiltre();
	void numberFiltre();

};