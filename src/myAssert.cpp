#include <iostream>
#include <sstream>

int main (int nArg, char* argS[])
{
	int nRet = 0;
	std::string strLine;
	getline (std::cin, strLine);
	std::string strWord;
	std::stringstream ss (strLine);
	ss>>strWord;
	auto pos = strLine.find (strWord);
	std::string strSpace;
	if (strLine.npos != pos) {
		strSpace = strLine.substr (0, pos);
	}
	strWord = strLine.substr (pos, strLine.npos);
	auto& cOut = std::cout;
	cOut<<strSpace<<"myAssert ("<<strWord<<");"<<std::endl;
	return nRet;
}
