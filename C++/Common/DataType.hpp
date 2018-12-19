#include <ostream>

#ifndef __LINEAR_LIST_DATA__
#define __LINEAR_LIST_DATA__

template <typename T>
struct SinglyNode
{
	T m_data;
	SinglyNode* next;

	SinglyNode(): next(NULL)
	{
	}

	SinglyNode(T e, SinglyNode* _next = NULL)
	{
		m_data = e;
		next = _next;
	}
};

template <typename T>
struct DoublyNode
{
	T m_data;
	DoublyNode* prev;
	DoublyNode* next;

	DoublyNode():prev(NULL),next(NULL)
	{
	}

	DoublyNode(T e, DoublyNode* _prev = NULL, DoublyNode* _next = NULL)
	:m_data(e),prev(_prev),next(_next)
	{
	}
};

template<typename T>
struct Tuple
{
	int row;
	int column;

	T value;

	Tuple(int row, int column, T value)
	:row(row), column(column), value(value)
	{
	}

	Tuple<T>& operator = (const Tuple<T>& tuple)
	{
		row    = tuple.row;
		column = tuple.column;
		value  = tuple.value;

		return *this;
	}
};

template<typename T>
struct BTreeNode
{
	T val;

	BTreeNode<T> *parent;
	BTreeNode<T> *left;
	BTreeNode<T> *right;

	BTreeNode(T _val, BTreeNode<T>* _parent=NULL, BTreeNode<T>*_left=NULL, BTreeNode<T>* _right=NULL)
	:parent(_parent), val(_val), left(_left), right(_right)
	{
	}
};

template<class T>
struct Link
{
	T* ptr;

	Link<T>* prev;
	Link<T>* next;

	Link()
	:ptr(NULL),prev(NULL),next(NULL)
	{
	}

	Link(T* ptr)
	:ptr(ptr),prev(NULL),next(NULL)
	{
	}
};

#endif
