#pragma once
#include "stdafx.h"
#include <iostream>


struct node
{
	int key;
	int data;
	struct node *left, *right;
};
class SplayTree
{
public:

	SplayTree() {};
	~SplayTree() {};

	struct node* newNode(int _key, int _data);
	struct node *splay(struct node *root, int key);
	struct node *insert(struct node *root, int k, int _data);
	struct node *search(struct node *root, int key);
	struct node* delete_key(struct node *root, int key);
	void print(struct node *root, std::ofstream &fout);
	void structure(struct node *root);
	struct node* get_min(struct node *root);
	struct node* get_max(struct node *root);

private:

	struct node* zig(struct node* x);
	struct node* zag(struct node* x);

};
