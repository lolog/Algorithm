#include <malloc.h>
#include "SequentQueue.h"

template<typename T>
sequent_queue::SequentQueue<T>::SequentQueue()
{
	init(defaultSize);
}

template<typename T>
sequent_queue::SequentQueue<T>::SequentQueue(int capacity)
{
	init(capacity);
}

template<typename T>
sequent_queue::SequentQueue<T>::~SequentQueue()
{
	front = rear = 0;
	free(elements);
}

template<typename T>
void sequent_queue::SequentQueue<T>::init(int capacity)
{
	front = 0;
	rear  = 0;

	mCapacity = capacity;
	elements  = (T*) malloc(sizeof(T) * capacity);
}

template<typename T>
bool sequent_queue::SequentQueue<T>::push(T t)
{
	int _feature = (rear + 1) % mCapacity;
	if(front == _feature)
	{
		return false;
	}

	elements[rear] = t;
	rear           = _feature;

	return true;
}

template<typename T>
T sequent_queue::SequentQueue<T>::pop()
{
	T t   = elements[front];
	front = (front + 1) % mCapacity;

	return t;
}

template<typename T>
bool sequent_queue::SequentQueue<T>::empty()
{
	if(rear == front)
	{
		return true;
	}
	return false;
}

template<typename T>
int sequent_queue::SequentQueue<T>::size()
{
	return (rear - front + mCapacity) % mCapacity;
}

template<typename T>
void sequent_queue::SequentQueue<T>::clear()
{
	rear = front = 0;
}

template<typename T>
void sequent_queue::SequentQueue<T>::print()
{
	int count  = size();

	cout << "SequentQueue:" << endl;
	cout << "      Size = " << count << endl;
	cout << "      Elements = ";

	if(count > 0)
	{
		count--;
		cout << pop();
	}

	while(count > 0)
	{
		count--;
		cout << ", " << pop();
	}
	cout << endl;
}
