#include "Tree.h"
#include "BinaryTree.cpp"
#include "../Common/DataType.hpp"

namespace tree
{
	Tree::Tree()
	{
		btree = new BinaryTree<int>();
	}

	Tree::~Tree()
	{
		delete btree;
	}

	void Tree::binaryTree()
	{
		//==============================
		//          10
		//     11        12
		//  13    14  15    16
		//==============================
		btree->insert3(10);
		btree->insert3(13);
		btree->insert3(15);
		btree->insert3(12);
		btree->insert3(14);
		btree->insert3(11);
		btree->insert3(16);

		cout << "element 11 is exist = " << btree->find(11) << endl;
		btree->print();
		btree->del3(16);
		btree->print();
	}
}
