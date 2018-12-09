#include "SinglyLinkQueue.h"

template<typename T>
singly_link_queue::SinglyLinkQueue<T>::SinglyLinkQueue()
{
	mSize = 0;
	front = rear = NULL;
}

template<typename T>
singly_link_queue::SinglyLinkQueue<T>::~SinglyLinkQueue()
{
	SinglyNode<T>* p_front;
	while(NULL != front)
	{
		p_front = front->next;
		delete front;
		front   = p_front;
	}
	front = rear = NULL;
}

template<typename T>
bool singly_link_queue::SinglyLinkQueue<T>::push(T t)
{
	SinglyNode<T>* p_node = new SinglyNode<T>(t);
	if(rear == NULL)
	{
		front = rear = p_node;
	}
	else
	{
		rear->next = p_node;
		rear       = p_node;
	}

	mSize++;

	return true;
}

template<typename T>
T singly_link_queue::SinglyLinkQueue<T>::pop()
{
	T t = front->m_data;

	SinglyNode<T>* p_node = front->next;
	delete front;
	front = p_node;

	mSize--;

	return t;
}

template<typename T>
bool singly_link_queue::SinglyLinkQueue<T>::empty()
{
	return NULL == front;
}


template<typename T>
int singly_link_queue::SinglyLinkQueue<T>::size()
{
	return mSize;
}

template<typename T>
void singly_link_queue::SinglyLinkQueue<T>::clear()
{
	mSize = 0;
	SinglyNode<T>* p_node = NULL;
	while(front != NULL)
	{
		p_node = front->next;
		delete front;
		front  = p_node;
	}
	front = rear = NULL;
}

template<typename T>
void singly_link_queue::SinglyLinkQueue<T>::print()
{
	cout << "SinglyLinkQueue:" << endl;
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
