#include "stdafx.h"
#include "Btree.h"
#include "SplayTree.h"
#include "Speed.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

void speed(std::string iFile, std::string oFile)
{
	BTree t(20); 
	std::ifstream file(iFile, std::ios_base::binary);
	std::string command = "";

	auto beginB = std::chrono::high_resolution_clock::now();

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
	}

	auto endB = std::chrono::high_resolution_clock::now();
	auto resB = std::chrono::duration_cast<std::chrono::microseconds>(endB - beginB).count();

	file.close();

	command = "";

	SplayTree st;

	struct node *root = NULL;

	std::ifstream fileS(iFile, std::ios_base::binary);

	auto beginS = std::chrono::high_resolution_clock::now();
	while (!fileS.eof())
	{
		

		fileS >> command;

		if (command == "add")
		{
			int a;
			fileS >> a;

			while (a != 0)
			{
				root = st.insert(root, a);
				fileS >> a;
			}

		}

		if (command == "delete")
		{
			int a;
			fileS >> a;

			while (a != 0)
			{
				root = st.delete_key(root, a);
				fileS >> a;
			}
		}

		if (command == "search")
		{
			int a;
			fileS >> a;

			while (a != 0)
			{
				root = st.search(root, a);
				fileS >> a;
			}
		}

		
	}
	auto endS = std::chrono::high_resolution_clock::now();
	auto resS = std::chrono::duration_cast<std::chrono::microseconds>(endS - beginS).count();
	fileS.close();

	std::ofstream out(oFile);
	out << resS << " microsecomds for Splay tree\n";
	out << resB << " microsecomds for B tree\n";
	std::cout << "ho;if";
	out.close();
}
