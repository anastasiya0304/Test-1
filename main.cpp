#include "stdafx.h"
#include "Btree.h"
#include "SplayTree.h"
#include "CorrectST.h"
#include "CorrectBT.h"
#include "Speed.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Not arguments" << std::endl;
		return 0;
	}

	std::string inFile = argv[1];
	std::string outFile = argv[2];

	if (inFile == "001.dat.txt" || inFile == "003.dat.txt")
	{
		if (!CheckCorrectST(inFile, outFile))
		{
			std::cout << "Incorrect" << std::endl;;
		}
	}
	
	if (inFile == "002.dat.txt" || inFile == "004.dat.txt")
	{
		if (!CheckCorrectBT(inFile, outFile))
		{
			std::cout << "Incorrect" << std::endl;;
		}
	}

	if (inFile == "005.dat.txt" || inFile == "006.dat.txt" || inFile == "007.dat.txt" || inFile == "008.dat.txt" || inFile == "009.dat.txt")
	{
		speed(inFile, outFile);
	}

	return 0;
}
