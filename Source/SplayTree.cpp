#include "stdafx.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>

//создаем новое дерево, выделяем память 
struct node* SplayTree::newNode(int _key, int _data)
{
	struct node* f_node = new node;
	f_node->key = _key;
	f_node->data = _data;
	f_node->left = NULL;
	f_node->right = NULL;
	return f_node;
}

//правый поворот
struct node* SplayTree::zig(struct node *x)
{
	struct node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

//левый поворот
struct node* SplayTree::zag(struct node *x)
{
	struct node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

// Элемент key делает вершиной дерева, если он есть в дереве, либо последний элемент на пути к key 
struct node* SplayTree::splay(struct node *root, int key)
{
	// Если корень нулевой или равен key
	if (root == NULL || root->key == key)
		return root;

	if (root->key > key)
	{
		// Если нет Key 
		if (root->left == NULL)
			return root;

		// Zig-Zig 
		if (root->left->key > key)
		{
			// вызываем рекурсивно функцию
			root->left->left = splay(root->left->left, key);

			// Первый правый поворот
			root = zig(root);
		}
		else if (root->left->key < key) // Zig-Zag 
		{
			root->left->right = splay(root->left->right, key);

			// Первый левый поворот
			if (root->left->right != NULL)
				root->left = zag(root->left);
		}

		// правый поворот и возвращаем корень
		return (root->left == NULL) ? root : zig(root);
	}
	else
	{
		if (root->right == NULL)
			return root;

		// Zig-Zag 
		if (root->right->key > key)
		{
			// рекурсия
			root->right->left = splay(root->right->left, key);

			// правый поворот
			if (root->right->left != NULL)
				root->right = zig(root->right);
		}
		else if (root->right->key < key)// Zag-Zag 
		{
			// левый поворот
			root->right->right = splay(root->right->right, key);
			root = zag(root);
		}

		// левый поворот
		return (root->right == NULL) ? root : zag(root);
	}
}

// Вставка новой вершины
struct node* SplayTree::insert(struct node *root, int k, int _data)
{
	if (root == NULL)
		return newNode(k, _data);

	// Проверяем есть ли элемент в дереве
	root = splay(root, k);

	if (root->key == k)
		return root;

	// создаем новый узел
	struct node* newnode = newNode(k, _data);

	// добавляем элемент
	if (root->key > k)
	{
		newnode->right = root;
		newnode->left = root->left;
		root->left = NULL;
	}
	else
	{
		newnode->left = root;
		newnode->right = root->right;
		root->right = NULL;
	}

	return newnode;
}

//поиск
struct node* SplayTree::search(struct node *root, int key)
{
	return splay(root, key);
}

// Удаление элемента
struct node* SplayTree::delete_key(struct node *root, int key)
{
	struct node *temp;
	if (!root)
		return NULL;

	//делаем нужное значение вершиной   
	root = splay(root, key);
	if (key != root->key)
		return root;

	// Если левое поддерево пусто 
	if (!root->left)
	{
		temp = root;
		root = root->right;
	}

	// Иначе
	else
	{
		temp = root;
		root = splay(root->left, key);
		root->right = temp->right;
	}

	return root;

}

struct node* SplayTree::get_min(struct node *root)
{
	if (root->left)
	{
		root = splay(root, root->left->key);
		return get_min(root);
	}
	return root;
}

struct node* SplayTree::get_max(struct node *root)
{
	if (root->right)
	{
		root = splay(root, root->right->key);
		return get_max(root);
	}
	return root;
}


//выводим на экран
void SplayTree::structure(struct node *root)
{
	if (root)
	{
		structure(root->left);
		std::cout << "key: " << root->key;
		if (root->left)
			std::cout << " | left child: " << root->left->key;
		if (root->right)
			std::cout << " | right child: " << root->right->key;
		std::cout << "\n";
		structure(root->right);
	}
}

void SplayTree::print(struct node *root, std::ofstream &fout)
{
	if (root != NULL)
	{
		fout<< root->data << " ";
		print(root->left, fout);
		print(root->right, fout);
	}
}
