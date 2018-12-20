#include <iostream>
#include "LinkHeap.h"
#include "../Common/TreeQueue.cpp"

namespace link_heap
{
	template<typename T>
	LinkHeap<T>::LinkHeap()
	{
		mCount      = 0;
		root        = NULL;

		treeQueue = new TreeQueue<_BTreeNode>();
		treeQueue->init(10);
	}

	template<typename T>
	LinkHeap<T>::~LinkHeap()
	{
		treeQueue->gc();
		_loop1(root, LinkHeap<T>::_gc);
	}

	template<typename T>
	void LinkHeap<T>::insert(const T& t)
	{
		if(NULL == root)
		{
			root = new BTreeNode<T>(t);
		}
		else
		{
			treeQueue->clear();
			treeQueue->push(root);
			_insert(t);
		}
		mCount++;
	}

	template<typename T>
	void LinkHeap<T>::_insert(const T& val)
	{
		BTreeNode<T>* p_node = treeQueue->current();
		if(NULL == p_node)
		{
			return;
		}
		T t = val;
		if(t < p_node->val)
		{
			t           = p_node->val;
			p_node->val = val;
		}
		if(NULL == p_node->left)
		{
			p_node->left  = new BTreeNode<T>(t, p_node);
		}
		else if(NULL == p_node->right)
		{
			if(t < p_node->left->val)
			{
				T _t = t;
				t    = p_node->left->val;

				p_node->left->val = _t;
			}
			p_node->right  = new BTreeNode<T>(t, p_node);
		}
		else
		{
			treeQueue->next();
			treeQueue->push(p_node->left);
			treeQueue->push(p_node->right);
			_insert(t);
		}
	}

	template<typename T>
	bool LinkHeap<T>::find(const T& t)
	{
		return _loop2(root, t, LinkHeap<T>::_find);
	}

	template<typename T>
	bool LinkHeap<T>::_find(BTreeNode<T>*  _node, const T& t)
	{
		if(t == _node->val)
		{
			return true;
		}
		return false;
	}

	template<typename T>
	bool LinkHeap<T>::del(const T& t)
	{
		if(NULL == root)
		{
			return false;
		}

		treeQueue->clear();
		treeQueue->push(root->left);
		treeQueue->push(root->right);
		if(t == root->val)
		{
			delete root;
			root = NULL;
		}
		return _del(t);
	}

	template<typename T>
	bool LinkHeap<T>::_del(const T& t)
	{
		BTreeNode<T>* p_node = treeQueue->current();
		if(NULL == p_node)
		{
			return false;
		}
		if(NULL == root)
		{
			root = p_node;
		}
		if(t == p_node->val)
		{
			treeQueue->push(p_node->left);
			treeQueue->push(p_node->right);

			treeQueue->next();
			BTreeNode<T>* p_leaf   = treeQueue->current();

			if(NULL == p_leaf)
			{
				if(t == p_node->parent->left->val)
				{
					p_node->parent->left = NULL;
				}
				else
				{
					p_node->parent->right = NULL;
				}
				delete p_node;
				return true;
			}
			else {
				p_node->val = p_leaf->val;
				p_leaf->val = t;

				return _del(t);;
			}
		}
		else
		{
			treeQueue->next();
			treeQueue->push(p_node->left);
			treeQueue->push(p_node->right);
			return _del(t);
		}
	}

	template<typename T>
	void LinkHeap<T>::print()
	{
		cout << "LinkHeap: " << endl;
		cout << "     Element: ";
		_loop1(root, LinkHeap<T>::_print);
		cout << endl;
	}

	template<typename T>
	bool LinkHeap<T>::_print(BTreeNode<T>* _node)
	{
		cout << _node->val << ", ";
		return true;
	}

	template<typename T>
	bool LinkHeap<T>::_gc(BTreeNode<T>* _node)
	{
		delete _node;
		return true;
	}

	template<typename T>
	void LinkHeap<T>::_loop1(BTreeNode<T>* _node, bool (*func)(BTreeNode<T>* _pointer))
	{
		if(NULL != _node)
		{
			BTreeNode<T>* left  = _node->left;
			BTreeNode<T>* right = _node->right;

			if(func(_node))
			{
				_loop1(left,  func);
				_loop1(right, func);
			}
		}
	}

	template<typename T>
	bool LinkHeap<T>::_loop2(BTreeNode<T>* _node, const T& t, bool (*func)(BTreeNode<T>* _pointer, const T& t))
	{
		if(NULL != _node)
		{
			BTreeNode<T>* left  = _node->left;
			BTreeNode<T>* right = _node->right;

			if(func(_node, t))
			{
				return true;
			}

			return _loop2(left, t, func) || _loop2(right, t, func);
		}
		return false;
	}
}
