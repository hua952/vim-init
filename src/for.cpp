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
	std::string i, n;
	std::stringstream ss (strLine);
	ss>>i>>n;
	auto pos = strLine.find (i);
	std::string strSpace;
	if (strLine.npos != pos) {
		strSpace = strLine.substr (0, pos);
	}

	auto& cOut = std::cout;
	cOut<<strSpace<<"for (decltype ("<<n<<") "<<i<<" = 0; "<<i<<" < "<<n<<"; "<<i<<"++) {"<<std::endl
		<<strSpace<<"}"<<std::endl;
	return nRet;
}
