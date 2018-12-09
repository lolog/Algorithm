#include "DoublyLinkQueue.h"

template<typename T>
doubly_link_queue::DoublyLinkQueue<T>::DoublyLinkQueue()
{
	mSize = 0;
	front = rear = NULL;
}

template<typename T>
doubly_link_queue::DoublyLinkQueue<T>::~DoublyLinkQueue()
{
	DoublyNode<T>* p_front;
	while(NULL != front)
	{
		p_front = front->next;
		delete front;
		front   = p_front;
	}
	front = rear = NULL;
}

template<typename T>
bool doubly_link_queue::DoublyLinkQueue<T>::push(T t)
{
	DoublyNode<T>* p_node = new DoublyNode<T>(t);
	if(rear == NULL)
	{
		front = rear = p_node;

		front->next = rear;
		rear->prev  = front;
	}
	else
	{
		rear->next   = p_node;
		p_node->prev = rear;
		rear       = p_node;
	}

	mSize++;

	return true;
}

template<typename T>
bool doubly_link_queue::DoublyLinkQueue<T>::rpush(T t)
{
	DoublyNode<T>* p_node = new DoublyNode<T>(t);
	if(rear == NULL)
	{
		front = rear = p_node;

		front->next = rear;
		rear->prev  = front;
	}
	else
	{
		p_node->next = front;
		front->prev  = p_node;
		front = p_node;
	}

	mSize++;

	return true;
}

template<typename T>
T doubly_link_queue::DoublyLinkQueue<T>::pop()
{
	T t = front->m_data;

	DoublyNode<T>* p_node = front->next;
	delete front;
	front = p_node;

	mSize--;

	return t;
}

template<typename T>
T doubly_link_queue::DoublyLinkQueue<T>::rpop()
{
	T t = front->m_data;

	DoublyNode<T>* p_node = rear->prev;
	delete rear;
	rear = p_node;

	mSize--;

	return t;
}

template<typename T>
bool doubly_link_queue::DoublyLinkQueue<T>::empty()
{
	return NULL == front;
}


template<typename T>
int doubly_link_queue::DoublyLinkQueue<T>::size()
{
	return mSize;
}

template<typename T>
void doubly_link_queue::DoublyLinkQueue<T>::clear()
{
	mSize = 0;
	DoublyNode<T>* p_node = NULL;
	while(front != NULL)
	{
		p_node = front->next;
		delete front;
		front  = p_node;
	}
	front = rear = NULL;
}

template<typename T>
void doubly_link_queue::DoublyLinkQueue<T>::print()
{
	cout << "DoublyLinkQueue:" << endl;
	cout << "     Size = " << mSize << endl;
	cout << "     Elements = ";

	if(mSize > 0) {
		cout << pop();
	}
	while(mSize > 0)
	{
		cout << ", " << pop();
	}
	cout << endl;
}
