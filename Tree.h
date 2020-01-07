/** @file */
#pragma once
#include <string>

/** Struktura w�z�a drzewa*/
struct TreeNode
{
	std::string key;	///< nazwa miasta 
	size_t value;		///< licznik niepowtarzaj�cych si� miast w pliku
	TreeNode* left;		///< lewy syn w drzewie	
	TreeNode* right;	///< prawy syn w drzewie
};
/** Struktura drzewa*/
struct Tree
{
	TreeNode* root;		///< wska�nik na korze� drzewa
};


/** Funkcja dodaj�ca miasto do drzewa
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
/** Funkcja usuwa dany w�ze� drzewa
@param node przekazuje dany w�ze� drzewa do usuni�cia*/
void deleteNode(TreeNode* node);
