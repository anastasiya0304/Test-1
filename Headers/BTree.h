#pragma once
#include "stdafx.h"
#include<iostream>


class BTreeNode
{
	int *keys;  
	int t;      
	BTreeNode **C; 
	int n;    
	bool leaf; 
public:
	BTreeNode(int _t, bool _leaf);   

	void insertNonFull(int k);

	void splitChild(int i, BTreeNode *y);

	void traverse(std::ofstream &fout);

	BTreeNode *search(int k);  

	int findKey(int k);

	void remove(int k);
	void removeFromLeaf(int idx);
	void removeFromNonLeaf(int idx);
	int getPred(int idx);
	int getSucc(int idx);
	void fill(int idx);
	void borrowFromPrev(int idx);
	void borrowFromNext(int idx);
	void merge(int idx);

	friend class BTree;
};


class BTree
{
	BTreeNode *root; 
	int t;
public:
	  
	BTree(int _t)
	{
		root = NULL;  t = _t;
	}

	void traverse(std::ofstream &fout)
	{
		if (root != NULL) root->traverse(fout);
	}

	BTreeNode* search(int k)
	{
		return (root == NULL) ? NULL : root->search(k);
	}
	
	void remove(int k);

	void insert(int k);
};
