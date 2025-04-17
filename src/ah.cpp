#include <iostream>
#include <sstream>
#include <map>
#include <memory>

#include <cstring>
#include <cstdlib>
#include <cstdio>
using typeMap = std::map <std::string, int>;

typeMap g_typeMap;

int main (int nArg, char* argS[])
{
	int nRet = 0;
	auto& rMap = g_typeMap;
	rMap ["int"] = 0;
	rMap ["bool"] = 0;
	rMap ["long"] = 0;
	rMap ["short"] = 0;
	rMap ["char"] = 0;
	rMap ["sbyte"] = 0;
	rMap ["ubyte"] = 0;
	rMap ["word"] = 0;
	rMap ["uword"] = 0;
	rMap ["dword"] = 0;
	rMap ["udword"] = 0;
	rMap ["qword"] = 0;
	rMap ["uqword"] = 0;
	rMap ["float32"] = 0;
	rMap ["float64"] = 0;
	rMap ["pubyte"] = 0;
	rMap ["PVoid"] = 0;
	rMap ["loopHandleType"] = 0;

	int nT = 4;
	std::string strPrv;
	getline (std::cin, strPrv);
	std::string strLine;
	getline (std::cin, strLine);
	auto posT = strLine.find (";");
	if (strLine.npos != posT) {
		strLine = strLine.substr (0, posT);
	}
	std::string strType;
	std::string strVar;
	auto nF = strLine.find ("unique_ptr");
	if (strLine.npos == nF) {
		nF = strLine.find ("shared_ptr");
		if (nF != strLine.npos) {
			nT = 3;
		}
	} else {
		nT = 3;
	}
	std::string  subType;
	std::string  firstWord;
	if (3 == nT) {
		std::stringstream ss (strLine);
		ss>>firstWord;
		while (ss>>strVar);
		if (strVar.c_str()[0] == 'm' && strVar.c_str()[1] == '_') {
			strVar = strVar.c_str () + 2;
		}

		auto nFF = strLine.find (">");
		auto strT = strLine.substr (0, nFF + 1);
		std::stringstream s2 (strT);
		std::string temp;
		s2>>temp;
		nFF = strT.find (temp);
		strType = strT.substr (nFF);
		nFF = strType.find ("<");
		subType = strType.substr (nFF + 1, strType.length () - nFF - 2);
		nFF = subType.find ("[");
		if (subType.npos != nFF) {
			subType = subType.substr (0, nFF);
		}
	} else {
		std::stringstream ss (strLine);
		ss>>strType>>strVar;

		firstWord = strType;
		if (strVar == "*") {
			ss>>strVar;
			strType += "*";
			nT = 1;
		} else {
			auto c = *(strType.rbegin ());
			if ('*' == c) {
				nT = 1;
			} else {
				auto it = rMap.find (strType);
				if (rMap.end () == it) {
					nT = 2;
				} else {
					nT = 0;
				}
			}
		}
		if (strVar.c_str()[0] == 'm' && strVar.c_str()[1] == '_') {
			strVar = strVar.c_str () + 2;
		}
	}
	auto pos = strLine.find (firstWord);
	std::string strSpace;
	if (strLine.npos != pos) {
		strSpace = strLine.substr (0, pos);
	}
	auto& cOut = std::cout;
	std::string strRet = strType;

	if (3 == nT) {
		strRet = "const ";
		strRet += subType;
		strRet += "*";
	} else if (2 == nT) {
		strRet += "&";
	}

	cOut<<strSpace<<strRet<<"  "<<strVar<<" ();"<<std::endl;
	/*
	auto& rE = std::cerr;
	rE<<" nT = "<<nT<<std::endl;
	*/
	do {
		if (2 == nT) {
			break;
		}
		auto pWord = std::make_unique <char[]> (strVar.length () + 1);
		auto pW = pWord.get ();
		strcpy (pW, strVar.c_str ());
		if ('a' <= pW[0] && pW[0] <= 'z') {
			pW[0] -= 32;
		}
		std::string strArgType;
		if (3 == nT) {
			strArgType = "const ";
			strArgType += subType;
			strArgType += "*";
		} else {
			strArgType = strType;
		}
		cOut<<strSpace<<"void  set"<<pW<<" ("<<strArgType<<" v);"<<std::endl;
	} while (0);
	cOut<<strPrv<<std::endl;

	cOut<<strSpace<<strType<<"  m_"<<strVar<<";"<<std::endl;
	return nRet;
}
