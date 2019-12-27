#include "Tree.h"

void insert(Tree& tree, std::string key, size_t value)
{
	TreeNode* node = new TreeNode{key, value, nullptr, nullptr};
	TreeNode* it = tree.root;
	TreeNode* prev = nullptr;
	while (it)
	{
		prev = it;
		if (it->key < key)
		{
			it = it->left;
		}
		else 
		{
			it = it->right;
		}
	}
	if (prev == nullptr)
	{
		tree.root = node;
		return;
	}
	if (prev->key < key)
	{
		prev->left = node;
	}
	else
	{
		prev->right = node;
	}
}

void deleteTree(Tree& tree)
{
	deleteNode(tree.root);
}

int find(Tree& tree, std::string key)
{
	TreeNode* it = tree.root;
	while (it)
	{
		if (it->key == key)return it->value;
		else if (it->key < key)
		{
			it = it->left;
		}
		else
		{
			it = it->right;
		}
	}
	return -1;
}
void deleteNode(TreeNode* node)
{
	if(!node)
		return;
	deleteNode(node->right);
	deleteNode(node->left);
	delete node;
	
}
