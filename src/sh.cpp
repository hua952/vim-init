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
	std::stringstream ss (strLine);
	ss>>strWord;
	auto pos = strLine.find (strWord);
	std::string strSpace;
	if (strLine.npos != pos) {
		strSpace = strLine.substr (0, pos);
	}
	auto& cOut = std::cout;
	cOut<<strSpace<<"struct "<<strWord<<std::endl
		<<strSpace<<"{"<<std::endl
		<<strSpace<<"};"<<std::endl;
	return nRet;
}
