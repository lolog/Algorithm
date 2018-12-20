#include <iostream>
#include "../Common/DataType.hpp"
#include "../Common/TreeQueue.h"

#ifndef __LINK_HEAP__
#define __LINK_HEAP__

namespace link_heap
{
	using namespace std;
	using tree_queue::TreeQueue;

	template<typename T>
	class LinkHeap
	{
		public:
			// VLR
			LinkHeap();
			~LinkHeap();

		public:
			void insert(const T& t);
			bool find(const T& t);
			bool del(const T& t);

			void print();

		private:
			static bool _print(BTreeNode<T>* _node);
			static bool _gc(BTreeNode<T>*    _node);
			static bool _find(BTreeNode<T>* _node, const T& t);

			void _insert(const T& val);
			bool _del(const T& t);

			void _loop1(BTreeNode<T>* _node, bool (*func)(BTreeNode<T>* _pointer));
			bool _loop2(BTreeNode<T>* _node, const T& t, bool (*func)(BTreeNode<T>* _pointer, const T& t));

		private:
			int mCount;
			BTreeNode<T>* root;

			// queue insert
			typedef BTreeNode<T>  _BTreeNode;
			TreeQueue<_BTreeNode>* treeQueue;
	};
}

#endif
