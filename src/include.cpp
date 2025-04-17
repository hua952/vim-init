#include <iostream>
#include <sstream>
#include <map>
#include <memory>
#include <regex>

#include <cstring>
#include <cstdlib>
#include <cstdio>
int main (int nArg, char* argS[])
{
	int nRet = 0;
	
	std::string strLine;
	getline (std::cin, strLine);
	auto& cOut = std::cout;
	cOut<<R"--(#include ")--"<<strLine<<".h\""<<std::endl;
	return nRet;
}
