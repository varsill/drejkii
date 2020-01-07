/** @file */
#pragma once
#include <string>

/** Struktura wêz³a drzewa*/
struct TreeNode
{
	std::string key;	///< nazwa miasta 
	size_t value;		///< licznik niepowtarzaj¹cych siê miast w pliku
	TreeNode* left;		///< lewy syn w drzewie	
	TreeNode* right;	///< prawy syn w drzewie
};
/** Struktura drzewa*/
struct Tree
{
	TreeNode* root;		///< wskaŸnik na korzeñ drzewa
};


/** Funkcja dodaj¹ca miasto do drzewa
@param tree przekazuje drzewo do funkcji
@param key przekazuje nazwa miasta
@param value przekazuje liczbe miast w drzewie*/
void insert(Tree& tree, std::string key, size_t value);
/** Rekurencyjna funkcja usuwania drzewa
@param tree przekazuje drzewo do funkcji*/
void deleteTree(Tree& tree);
/** Funkcja znajduje dane miasto w drzewie
@param tree przekazuje drzewo do funkcji
@param key przekazuje nazwe miasta
@return zwraca indeks miasta*/
int find(Tree& tree, std::string key);
/** Funkcja usuwa dany wêze³ drzewa
@param node przekazuje dany wêze³ drzewa do usuniêcia*/
void deleteNode(TreeNode* node);
