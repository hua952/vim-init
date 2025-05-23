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
	std::string className;
	if (2 == nArg) {
		className = argS[1];
	}
	int nT = 4;
	std::string strLine;
	getline (std::cin, strLine);
	auto szR = R"--((\s*)(\w+.+)(\b\w[\w\d]*\s*\(.*\))\s*(\w*)(;*))--";
	/*
	auto& rE = std::cerr;
	rE<<" szR = "<<szR<<std::endl;
	*/
	std::regex r(szR);
	std::stringstream ss;
	if (className.empty ()) {
		ss<<"$2$3$4";
	} else {
		ss<<"$2 "<<className<<":: $3$4";
	}
	std::string funH = std::regex_replace(strLine, r, ss.str().c_str());
	std::string retType = std::regex_replace(strLine, r, "$2");
	auto& cOut = std::cout;
	std::string strSpace;
	cOut<<strSpace<<funH<<std::endl
		<<strSpace<<"{"<<std::endl;
	bool bRet = false;
	auto pos = retType.find ("void");
	if (strLine.npos == pos) {
		bRet = true;
	}
	if (bRet) {
		cOut<<strSpace<<"    "<<retType<<" nRet = 0;"<<std::endl;
	}
	cOut<<strSpace<<"    do {"<<std::endl
		<<strSpace<<"    } while (0);"<<std::endl;
	if (bRet) {
		cOut<<strSpace<<"    return nRet;"<<std::endl;
	}
	cOut<<strSpace<<"}"<<std::endl<<std::endl;
	return nRet;
}
