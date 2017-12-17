#include "stdafx.h"
#include "Btree.h"
#include "SplayTree.h"
#include "Correct.h"

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

	if (argv[3] != nullptr)
	{

		speed(inFile, outFile);
	}
	else
	{
		if (!CheckCorrect(inFile, outFile))

	}

	system("pause");
	return 0;
}
