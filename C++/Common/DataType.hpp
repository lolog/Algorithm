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

#endif
