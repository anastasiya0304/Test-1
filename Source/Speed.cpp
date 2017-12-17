#include "stdafx.h"
#include "Btree.h"
#include "SplayTree.h"
#include "Speed.h"
#include "ReadFile.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

void speed(std::string iFile, std::string oFile)
{
	//проверяем би дерево
	auto beginB = std::chrono::high_resolution_clock::now();

	ReadFileBT(iFile, "test.txt");

	auto endB = std::chrono::high_resolution_clock::now();
	auto resB = std::chrono::duration_cast<std::chrono::microseconds>(endB - beginB).count();

	//проверяем косое дерево
	auto beginS = std::chrono::high_resolution_clock::now();

	ReadFileST(iFile, "test.txt");

	auto endS = std::chrono::high_resolution_clock::now();
	auto resS = std::chrono::duration_cast<std::chrono::microseconds>(endS - beginS).count();


	std::ofstream out(oFile);
	out << resS << " microsecomds for Splay tree\n";
	out << resB << " microsecomds for B tree\n";
	out.close();
}
