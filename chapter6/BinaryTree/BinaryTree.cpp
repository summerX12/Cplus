#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

template<typename elemType>
class BinaryTree;


template<typename elemType>
inline ostream&
operator<<(ostream &os, const BinaryTree<elemType> &bt)
{
	os << "Tree: " << endl;
	bt.preorder(os);
	return os;
}

int main()
{
	BinaryTree <string> bt;

	bt.insert("Piglet");
	bt.insert("Eeyore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");

	cout << "Preorder traversal: \n";
	cout << bt<<endl;


	bt.remove("Piglet");
	cout << "Preorder traversal after remove Piglet: \n";
	bt.preorder();
	cout << endl;

	bt.remove("Chris");
	cout << "Preorder traversal after remove Chris: \n";
	bt.preorder();
	cout << endl;

	return 0;
}