#include <iostream>
#include <sstream>

#include <cstring>
#include <cstdlib>
#include <cstdio>
int main (int nArg, char* argS[])
{
	int nRet = 0;
	std::string strLine;
	getline (std::cin, strLine);
	std::string strWord;
	std::string strValue;
	std::stringstream ss (strLine);
	ss>>strWord>>strValue;
	auto pos = strLine.find (strWord);
	std::string strSpace;
	if (strLine.npos != pos) {
		strSpace = strLine.substr (0, pos);
	}
	auto& cOut = std::cout;
	cOut<<strSpace<<"auto  "<<strWord<<" = std::make_unique<char[]> ("<<strValue<<");"<<std::endl;
	return nRet;
}
