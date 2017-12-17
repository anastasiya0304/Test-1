#include "stdafx.h"
#include "SplayTree.h"
#include "Correct.h"
#include "ReadFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

bool CheckCorrect(std::string& iFile, std::string& oFile)
{
	ReadFileST(iFile, oFile);

	//проверяем корректность косого дерева
	std::ifstream check(oFile, std::ios_base::in);

	std::string str_st = "";

	int i = 0;

	while (!check.eof())
	{
		check >> str_st[i];
		str_st += str_st[i];
		i++;
	}
	check.close();

	std::string str_st_res = "";

	std::ifstream check1("001.txt", std::ios_base::in);

	int ind = 0;

	while (!check1.eof())
	{
		check1 >> str_st_res[ind];
		str_st_res += str_st_res[ind];
		ind++;
	}
	check1.close();

	if (str_st != str_st_res)
	{
		std::cout << "Incorrect splay tree" << std::endl;

		return false;
	}

	ReadFileBT(iFile, oFile);

	//проверяем корректность БИ дерева
	std::ifstream check3(oFile, std::ios_base::in);

	std::string str_bt = "";

	int in = 0;

	while (!check3.eof())
	{
		check3 >> str_bt[in];
		str_bt += str_bt[in];
		in++;
	}
	check3.close();

	std::string str_bt_res = "";

	std::ifstream check4("002.txt", std::ios_base::in);

	int indx = 0;

	while (!check4.eof())
	{
		check4 >> str_bt_res[indx];
		str_bt_res += str_bt_res[indx];
		indx++;
	}
	check4.close();

	if (str_bt != str_bt_res)
	{
		std::cout << "Incorrect B tree" << std::endl;

		return false;
	}

	return true;
}
