#include <math.h>
#include "DoublyLinkList.h"

template<typename Type>
doubly_list::DoublyLinkList<Type>::DoublyLinkList()
{
	m_count = 0;
	head  = NULL;
	tail  = NULL;
}

template<typename Type>
doubly_list::DoublyLinkList<Type>::~DoublyLinkList()
{
	DoublyNode<Type>* current_node = head;
	DoublyNode<Type>* temp_node    = NULL;
	while(NULL != current_node)
	{
		temp_node    = current_node;
		current_node = current_node->next;
		delete temp_node;
	}
}

template<typename Type>
void doubly_list::DoublyLinkList<Type>::addHead(Type e)
{
	m_count++;
	DoublyNode<Type>* p_node = new DoublyNode<Type>(e, NULL, head);

	if(NULL == head)
	{
		head = tail = p_node;
		tail->prev  = head;
	}
	else
	{
		head->prev = p_node;
		head       = p_node;
	}
}

template<typename Type>
void doubly_list::DoublyLinkList<Type>::addTail(Type e)
{
	m_count++;
	DoublyNode<Type>* p_node = new DoublyNode<Type>(e, tail, NULL);

	if(NULL == head)
	{
		head = tail = p_node;
		head->next  = tail;
	}
	else
	{
		tail->next = p_node;
		tail       = p_node;
	}
}

template<typename Type>
bool doubly_list::DoublyLinkList<Type>::del(Type e)
{
	bool is_del = false;

	if(m_count == 1)
	{
		if(head->m_data == e)
		{
			m_count--;
			delete head;
			head = tail = NULL;
		}
	}
	else
	{
		DoublyNode<Type>* p_head = head;
		DoublyNode<Type>* p_tail = tail;

		int i    = 0;
		int size = ceil(m_count / 2.0);
		while(i < size)
		{
			if(p_head->m_data == e)
			{
				p_head->prev->next = p_head->next;
				p_head->next->prev = p_head->prev;

				delete p_head;
				is_del = true;
				m_count--;

				break;
			}
			if(p_tail->m_data == e)
			{
				p_tail->prev->next = p_tail->next;
				p_tail->next->prev = p_tail->prev;

				delete p_tail;
				is_del = true;
				m_count--;

				break;
			}

			p_head = p_head->next;
			p_tail = p_tail->prev;

			i++;
		}
	}

	return is_del;
}

template<typename Type>
int doubly_list::DoublyLinkList<Type>::size()
{
	return m_count;
}

template<typename Type>
bool doubly_list::DoublyLinkList<Type>::contains(Type e)
{
	if(m_count == 1)
	{
		if(head->m_data == e)
		{
			return true;
		}
	}
	else
	{
		DoublyNode<Type>* p_head = head;
		DoublyNode<Type>* p_tail = tail;

		int i    = 0;
		int size = ceil(m_count / 2);
		while(i < size)
		{
			if(p_head->m_data == e)
			{
				return true;
			}
			if(p_tail->m_data == e)
			{
				return true;
			}

			p_head = p_head->next;
			p_tail = p_tail->prev;

			i++;
		}
	}
	return false;
}

template<typename Type>
void doubly_list::DoublyLinkList<Type>::print()
{
	// ==================================================
	cout << "DoublyLinkList：" << endl;
	cout << "   count = " << m_count << endl;

	// ==================================================
	cout << "   from head: ";

	DoublyNode<Type>* p_node = head;
	// first
	if(NULL != p_node)
	{
		cout << p_node->m_data;
		p_node = p_node->next;
	}
	// next
	while(NULL != p_node)
	{
		cout << ", " << p_node->m_data;
		p_node = p_node->next;
	}
	cout << endl;

	// ==================================================
	cout << "   from tail: ";

	p_node = tail;
	// first
	if(NULL != p_node)
	{
		cout << p_node->m_data;
		p_node = p_node->prev;
	}
	// next
	while(NULL != p_node)
	{
		cout << ", " << p_node->m_data;
		p_node = p_node->prev;
	}
	cout << endl;
}
