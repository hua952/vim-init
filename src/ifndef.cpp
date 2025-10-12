#include <iostream>
#include <sstream>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm> // 包含 std::replace

int main (int nArg, char* argS[])
{
	int nRet = 0;
    do {
	    //std::string strLine;
	    //getline (std::cin, strLine);
        std::string strDef = "_";
        strDef += argS[1];
        strDef += "__";
        std::replace(strDef.begin(), strDef.end(), '.', '_');
        std::cout<<"#ifndef "<<strDef<<std::endl
            <<"#define "<<strDef<<std::endl
            <<"#endif";
    } while (0);
    return nRet;
}
