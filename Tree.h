#pragma once
#include <string>

struct TreeNode
{
	std::string key;
	size_t value;
	TreeNode* left;
	TreeNode* right;
};

struct Tree
{
	TreeNode* root;
};



void insert(Tree& tree, std::string key, size_t value);
void deleteTree(Tree& tree);
int find(Tree& tree, std::string key);
void deleteNode(TreeNode* node);
