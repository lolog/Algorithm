#include "BinaryTree.h"

#ifndef __TREE__
#define __TREE__

namespace tree
{
	using binary_tree::BinaryTree;

	class Tree
	{
		public:
			Tree();
			~Tree();

		public:
			void binaryTree();

		private:
			BinaryTree<int>* btree;
	};
}

#endif
