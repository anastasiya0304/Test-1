#include "stdafx.h"
#include "Btree.h"
#include "CorrectBT.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

bool CheckCorrectBT(std::string iFile, std::string oFile)
{
	BTree t(5); 

	std::ifstream file(iFile, std::ios_base::binary);
	std::string command;
	while (!file.eof())
	{
		file >> command;
		if (command == "add")
		{
			int a;
			file >> a;
			while (a != 0)
			{
				t.insert(a);
				file >> a;
			}

		}
		if (command == "delete")
		{
			int a;
			file >> a;
			while (a != 0)
			{
				t.remove(a);
				file >> a;

			}
		}

		if (command == "search")
		{
			int a;
			file >> a;
			while (a != 0)
			{
				t.search(a);
				file >> a;

			}
		}

		if (command == "print")
		{
			std::ofstream out(oFile, std::ios_base::binary);
			t.traverse(out);
			out.close();
		}
		if (command == "min")
		{
			std::ofstream outM(oFile, std::ios_base::binary);
			t.get_min(outM);
			outM.close();
		}
	}
	file.close();

	std::ifstream check(oFile, std::ios_base::in);
	std::string a = "";
	int i = 0;
	while (!check.eof())
	{
		check >> a[i];
		a += a[i];
		i++;
	}
	check.close();

	std::string b = "";
	std::string name = "";
	if (iFile == "002.dat.txt")
	{
		name = "002.txt";
	}
	else
	{
		name = "004.txt";
	}
	std::ifstream check1(name, std::ios_base::in);
	int ind = 0;
	while (!check1.eof())
	{
		check1 >> b[ind];
		b += b[ind];
		ind++;
	}
	check1.close();

	if (a != b)
	{
		return false;
	}
	return true;
}
