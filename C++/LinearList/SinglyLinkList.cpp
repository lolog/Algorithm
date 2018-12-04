#include "SinglyLinkList.h"

template<typename Type>
singly_list::SinglyLinkList<Type>::SinglyLinkList()
{
	m_count = 0;
	head  = NULL;
	tail  = NULL;
}

template<typename Type>
singly_list::SinglyLinkList<Type>::~SinglyLinkList()
{
	SinglyNode<Type>* current_node = head;
	SinglyNode<Type>* temp_node    = NULL;
	while(NULL != current_node)
	{
		temp_node    = current_node;
		current_node = current_node->next;
		delete temp_node;
	}
}

template<typename Type>
void singly_list::SinglyLinkList<Type>::addHead(Type e)
{
	m_count++;
	head = new SinglyNode<Type>(e, head);

	if(NULL == tail)
	{
		tail = head;
	}
}

template<typename Type>
void singly_list::SinglyLinkList<Type>::addTail(Type e)
{
	m_count++;

	if(NULL == tail)
	{
		head = tail = new SinglyNode<Type>(e);
	}
	else
	{
		tail->next = new SinglyNode<Type>(e);
		tail = tail->next;
	}
}

template<typename Type>
bool singly_list::SinglyLinkList<Type>::del(Type e)
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
		SinglyNode<Type>* p_prev_node = head;
		SinglyNode<Type>* p_curr_node = head;

		while(NULL != p_curr_node)
		{
			if(p_curr_node->m_data == e)
			{
				// delete current node
				p_prev_node->next = p_curr_node->next;

				delete p_curr_node;
				is_del = true;
				m_count--;

				break;
			}
			p_prev_node = p_curr_node;
			p_curr_node = p_curr_node->next;
		}
	}

	return is_del;
}

template<typename Type>
int singly_list::SinglyLinkList<Type>::size()
{
	return m_count;
}

template<typename Type>
bool singly_list::SinglyLinkList<Type>::contains(Type e)
{
	SinglyNode<Type>* p_node = head;
	while(NULL != p_node)
	{
		if(p_node->m_data == e)
		{
			return true;
		}
		p_node = p_node->next;
	}
	return false;
}

template<typename Type>
void singly_list::SinglyLinkList<Type>::print()
{
	cout << "SinglyLinkList Elements:" << endl;
	cout << "    ";

	SinglyNode<Type>* p_node = head;
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
}
