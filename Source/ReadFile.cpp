#include "stdafx.h"
#include "SplayTree.h"
#include "Btree.h"
#include <iostream>
#include <fstream>
#include <string>

void ReadFileST(std::string iFile, std::string oFile)
{
	SplayTree st;

	struct node *root = NULL;

	std::ifstream file(iFile, std::ios_base::binary);
	std::string command = "";

	while (!file.eof())
	{
		command = "";
		file >> command;

		if (command == "add")
		{
			int key, data;
			file >> key;
			file >> data;

			while (data != 0 && key != 0)
			{
				root = st.insert(root, key, data);
				file >> key;
				file >> data;
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
}



void ReadFileBT(std::string iFile, std::string oFile)
{
	BTree t(50);

	std::ifstream fileB(iFile, std::ios_base::binary);
	std::string command;
	while (!fileB.eof())
	{
		fileB >> command;
		if (command == "add")
		{
			int k, d;
			fileB >> k;
			fileB >> d;
			while (d != 0 && k != 0 )
			{
				t.insert(k, d);
				fileB >> k;
				fileB >> d;
			}

		}
		if (command == "delete")
		{
			int a;
			fileB >> a;
			while (a != 0)
			{
				t.remove(a);
				fileB >> a;

			}
		}

		if (command == "search")
		{
			int a;
			fileB >> a;
			while (a != 0)
			{
				t.search(a);
				fileB >> a;

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
			std::ofstream outM(oFile, std::ios_base::binary | std::ios_base::app);
			outM << t.min() << " ";
			outM.close();
		}

		if (command == "max")
		{
			std::ofstream outX(oFile, std::ios_base::binary | std::ios_base::app);
			outX << t.max() << " ";
			outX.close();
		}
	}
	fileB.close();
}
