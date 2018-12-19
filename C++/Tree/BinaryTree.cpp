#include <iostream>
#include "BinaryTree.h"

namespace binary_tree
{
	template<typename T>
	BinaryTree<T>::BinaryTree()
	{
		mCount = 0;
		root   = NULL;

		frontLeaf = rearLeaf = new Link<_BTreeNode>();
	}

	template<typename T>
	BinaryTree<T>::~BinaryTree()
	{
		_loop1(root, BinaryTree<T>::_gc);

		Link<_BTreeNode>* p_link = NULL;
		while(NULL != frontLeaf)
		{
			p_link   = frontLeaf->next;
			delete frontLeaf;
			frontLeaf = p_link;
		}
	}

	template<typename T>
	void BinaryTree<T>::insert1(const T& t)
	{
		if(NULL == root)
		{
			root = new BTreeNode<T>(t);
		}
		else
		{
			_insert1(root, t);
		}
	}

	template<typename T>
	void BinaryTree<T>::insert2(const T& t)
	{
		BTreeNode<T>* _node = new BTreeNode<T>(t);
		if(NULL == root)
		{
			root           = _node;
			frontLeaf->ptr = root;
			return;
		}
		BTreeNode<T>* e_node = frontLeaf->ptr;
		if(NULL == e_node->left)
		{
			e_node->left = _node;
		}
		else if(NULL == e_node->right)
		{
			e_node->right            = _node;
			// delete this node
			Link<_BTreeNode>* p_link = frontLeaf->next;
			delete frontLeaf;
			frontLeaf                 = p_link;
		}

		rearLeaf->next       = new Link<_BTreeNode>(_node);
		rearLeaf->next->prev = rearLeaf;
		rearLeaf             = rearLeaf->next;
	}

	template<typename T>
	void BinaryTree<T>::insert3(const T& t)
	{
		if(NULL == root)
		{
			root = new BTreeNode<T>(t);
		}
		else
		{
			_insert3(root, t);
		}
	}

	template<typename T>
	bool BinaryTree<T>::find(const T& t)
	{
		return _loop2(root, t, BinaryTree<T>::_find);
	}

	template<typename T>
	bool BinaryTree<T>::del3(const T& t)
	{
		return _del3(root, t);
	}

	template<typename T>
	bool BinaryTree<T>::_find(BTreeNode<T>*  _node, const T& t)
	{
		if(t == _node->val)
		{
			return true;
		}
		return false;
	}

	template<typename T>
	bool BinaryTree<T>::_del3(BTreeNode<T>* _node, const T& t)
	{
		if(NULL != _node)
		{
			BTreeNode<T>* left  = _node->left;
			BTreeNode<T>* right = _node->right;

			if(t == _node->val)
			{
				if(root->val == _node->val)
				{
					BTreeNode<T>* _p_node  = root;
					root                   = root->left;

					BTreeNode<T>* leftNode = _node;
					while(NULL != leftNode->left)
					{
						leftNode = leftNode->left;
					}
					leftNode->left = _p_node->right;
					delete _p_node;

					return true;
				}
				if((NULL == _node->left) ^ (NULL == _node->right))
				{
					BTreeNode<T>* leafNode = NULL;
					if(NULL != _node->left)
					{
						leafNode = _node->left;
					}
					else {
						leafNode = _node->right;
					}
					_node->val   = leafNode->val;
					_node->left  = leafNode->left;
					_node->right = leafNode->right;
					delete leafNode;

					return true;
				}

				if(t == _node->parent->left->val)
				{
					_node->parent->left = _node->left;
				}
				else
				{
					_node->parent->right = _node->left;
				}
				// leaf
				if(NULL == _node->left)
				{
					delete _node;
					return true;
				}
				// left and right is not null
				BTreeNode<T>* leftNode = _node->left;
				while(NULL != leftNode->left)
				{
					leftNode = leftNode->left;
				}
				leftNode->left = _node->right;
				delete _node;

				return true;
			}

			return _del3(left, t) || _del3(right, t);
		}

		return false;
	}

	template<typename T>
	void BinaryTree<T>::print()
	{
		cout << "BinaryTree: " << endl;
		cout << "     Element: ";
		_loop1(root, BinaryTree<T>::_print);
		cout << endl;
	}

	template<typename T>
	bool BinaryTree<T>::_print(BTreeNode<T>* _node)
	{
		cout << _node->val << ", ";
		return true;
	}

	template<typename T>
	bool BinaryTree<T>::_gc(BTreeNode<T>* _node)
	{
		delete _node;
		return true;
	}

	template<typename T>
	void BinaryTree<T>::_insert1(BTreeNode<T>* _parent, const T& val)
	{
		T t_val = val;
		if(val < _parent->val)
		{
			t_val        = _parent->val;
			_parent->val = val;
		}
		if(NULL == _parent->left)
		{
			_parent->left = new BTreeNode<T>(t_val, _parent);
			return;
		}
		if(NULL == _parent->right)
		{
			if(t_val < _parent->left->val)
			{
				_parent->right = _parent->left;
				_parent->left  = new BTreeNode<T>(t_val, _parent);
			}
			else
			{
				_parent->right = new BTreeNode<T>(t_val, _parent);
			}
			return;
		}
		if(t_val <= _parent->left->val)
		{
			_insert1(_parent->left, t_val);
		}
		else if(t_val > _parent->right->val)
		{
			_insert1(_parent->right, t_val);
		}
	}

	template<typename T>
	void BinaryTree<T>::_insert3(BTreeNode<T>* _parent, const T& val)
	{
		if(NULL == _parent->left)
		{
			_parent->left = new BTreeNode<T>(val, _parent);
			return;
		}
		if(NULL == _parent->right)
		{
			_parent->right = new BTreeNode<T>(val, _parent);
			return;
		}
		if(val <= _parent->left->val)
		{
			_insert3(_parent->left, val);
		}
		else if(val > _parent->right->val)
		{
			_insert3(_parent->right, val);
		}
	}

	template<typename T>
	void BinaryTree<T>::_loop1(BTreeNode<T>* _node, bool (*func)(BTreeNode<T>* _pointer))
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
	bool BinaryTree<T>::_loop2(BTreeNode<T>* _node, const T& t, bool (*func)(BTreeNode<T>* _pointer, const T& t))
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
