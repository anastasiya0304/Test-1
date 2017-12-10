#include "stdafx.h"
#include "SplayTree.h"
#include "CorrectST.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

bool CheckCorrectST(std::string iFile, std::string oFile)
{
	SplayTree st;

	struct node *root = NULL;

	std::ifstream file(iFile, std::ios_base::binary);
	std::string command = "";

	while (!file.eof())
	{
		file >> command;

		if (command == "add")
		{
			int a;
			file >> a;

			while (a != 0)
			{
				root = st.insert(root, a);
				file >> a;
			}

		}

		if (command == "delete")
		{
			int a;
			file >> a;

			while (a != 0)
			{
				root = st.delete_key(root, a);
				file >> a;
			}
		}

		if (command == "search")
		{
			int a;
			file >> a;

			while (a != 0)
			{
				root = st.search(root, a);
				file >> a;
			}
		}

		if (command == "min")
		{
			root = st.get_min(root);
		}

		if (command == "max")
		{
			root = st.get_max(root);
		}

		if (command == "print")
		{
			std::ofstream out(oFile, std::ios_base::binary);
			st.print(root, out);
			out.close();
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
	if (iFile == "001.dat.txt")
	{
		name = "001.txt";
	}
	else
	{
		name = "003.txt";
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
