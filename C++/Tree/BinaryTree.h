#include <iostream>
#include "../Common/DataType.hpp"

#ifndef __BINARY_TREE__
#define __BINARY_TREE__

namespace binary_tree
{
	using namespace std;

	template<typename T>
	class BinaryTree
	{
		public:
			// VLR
			BinaryTree();
			~BinaryTree();

		public:
			void insert1(const T& t);
			void insert2(const T& t);
			void insert3(const T& t);
			bool find(const T& t);
			bool del3(const T& t);

			void print();

		private:
			static bool _print(BTreeNode<T>* _node);
			static bool _gc(BTreeNode<T>*    _node);
			static bool _find(BTreeNode<T>* _node, const T& t);

			//===================================================
			// ordered inserted
			//===================================================
			void _insert1(BTreeNode<T>* _parent, const T& val);
			//===================================================
			// entirely binary tree
			//===================================================
			void _insert2(BTreeNode<T>* _parent, const T& val);
			//===================================================
			// normal binary tree
			//===================================================
			void _insert3(BTreeNode<T>* _parent, const T& val);

			//===================================================
			// normal binary tree delete
			//===================================================
			bool _del3(BTreeNode<T>* _node, const T& t);

			void _loop1(BTreeNode<T>* _node, bool (*func)(BTreeNode<T>* _pointer));
			bool _loop2(BTreeNode<T>* _node, const T& t, bool (*func)(BTreeNode<T>* _pointer, const T& t));

		private:
			int mCount;
			BTreeNode<T>* root;

			// queue insert
			typedef BTreeNode<T> _BTreeNode;
			Link<_BTreeNode>* frontLeaf;
			Link<_BTreeNode>* rearLeaf;
	};
}

#endif
