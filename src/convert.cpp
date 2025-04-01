#include <iostream>
#include <sstream>

int main (int nArg, char* argS[])
{
	int nRet = 0;
	std::string strLine;
	getline (std::cin, strLine);
	std::string strWord;
	std::string strValue;
	std::string strEV;
	std::stringstream ss (strLine);
	ss>>strWord>>strValue>>strEV;
	auto pos = strLine.find (strWord);
	std::string strSpace;
	if (strLine.npos != pos) {
		strSpace = strLine.substr (0, pos);
	}
	auto& cOut = std::cout;
	cOut<<strSpace<<"auto  "<<strWord<<" = ("<<strValue<<")("<<strEV<<");"<<std::endl;
	return nRet;
}
