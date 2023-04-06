#include <iostream>
#include <fstream>
#include <sstream>

int main (int nArg, char* argS[])
{
	int nRet = 0;
	do {
		if (3 != nArg) {
			nRet = 1;
			break;
		}
		std::string strPath = argS[1];
		strPath += "/";
		auto className = argS[2];
		auto hfile = strPath;
		hfile += className;
		auto cfile = hfile;
		hfile += ".h";
		cfile += ".cpp";
		std::ifstream ifs (hfile.c_str ());
		if (ifs) {
			ifs.close ();
			nRet = 2;
			break;
		}
		std::ifstream cifs (cfile.c_str ());
		if (cifs) {
			cifs.close ();
			nRet = 3;
			break;
		}
		std::ofstream ofs (hfile.c_str ());
		ofs<<"#ifndef _"<<className<<"_h__"<<std::endl
		   <<"#define _"<<className<<"_h__"<<std::endl
		   <<std::endl
		   <<"class "<<className<<std::endl
		   <<"{"<<std::endl
		   <<"public:"<<std::endl
		   <<"    "<<className<<" ();"<<std::endl
		   <<"    ~"<<className<<" ();"<<std::endl
		   <<"};"<<std::endl
		   <<"#endif"<<std::endl;
		ofs.close ();

		std::ofstream cfs (cfile.c_str ());
		cfs<<"#include \""<<className<<".h\""<<std::endl
		   <<std::endl
		   <<className<<":: "<<className<<" ()"<<std::endl
		   <<"{"<<std::endl
		   <<"}"<<std::endl
		   <<std::endl
		   <<className<<":: ~"<<className<<" ()"<<std::endl
		   <<"{"<<std::endl
		   <<"}"<<std::endl
		   <<std::endl;
		   cfs.close ();
	} while (0);
	// auto& cOut = std::cout;
	// cOut<<"nRet = "<<nRet<<" path = "<<argS[1]<<" className = "<<argS[2]<<std::endl;
	return nRet;
}
