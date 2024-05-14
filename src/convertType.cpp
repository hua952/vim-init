#include <iostream>
#include <sstream>

bool writeAuto (const char* szTxt)
{
	bool bRet = true;
	auto pC = szTxt;
	while (*pC) {
		if (!('A'<=*pC && *pC <= 'Z' || 'a'<=*pC && *pC <= 'z' || '0'<=*pC && *pC <= '9' || '_'==*pC)) {
			bRet = false;
			break;
		}
		pC++;
	}
	return bRet;
}

int main (int nArg, char* argS[])
{
	int nRet = 0;
	std::string strLine;
	getline (std::cin, strLine);
	std::string val, strType, n;
	std::stringstream ss (strLine);
	ss>>val;
	auto pos = strLine.find (val);
	std::string strSpace;
	strSpace = strLine.substr (0, pos);
	ss>>strType;
	pos = strLine.find (strType);
	pos += strType.length();
	auto subStr = strLine.substr (pos);
	std::stringstream ssNo(subStr);
	std::string word;
	ssNo>>word;
	pos = subStr.find(word);
	word = subStr.substr(pos);
	auto& cOut = std::cout;
	cOut<<strSpace;
	auto bW = writeAuto(val.c_str());
	if (bW) {
		cOut<<"auto ";
	}
	cOut<<val<<" = ("<<strType<<")("<<word<<");";
	return nRet;
}
