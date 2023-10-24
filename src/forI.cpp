#include <iostream>
#include <sstream>

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
	cOut<<strSpace<<"for (auto "<<i<<" = "<<n<<".begin (); "<<i<<" != "<<n<<".end (); "<<i<<"++) {"<<std::endl
		<<strSpace<<"}"<<std::endl;
	return nRet;
}

