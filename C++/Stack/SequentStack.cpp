#include <ostream>
#include <malloc.h>
#include "SequentStack.h"

template<typename T>
sequent_stack::SequentStack<T>::SequentStack()
{
	init(1.5f, defaultSize);
}

template<typename T>
sequent_stack::SequentStack<T>::SequentStack(int capacity)
{
	init(1.5f, capacity);
}

template<typename T>
sequent_stack::SequentStack<T>::~SequentStack()
{
	free(elements);
}

template<typename T>
void sequent_stack::SequentStack<T>::init(float factor, int capacity)
{
	mTop       = 0;
	mFactor    = factor;
	mCapacity  = capacity;
	elements   = (T*) malloc(sizeof(T) * capacity);
}

template<typename T>
void sequent_stack::SequentStack<T>::extendCapacity(int capacity)
{
	T* p_elements = (T*) malloc(sizeof(T) * capacity);
	for(int i=0; i<mTop; i++)
	{
		p_elements[i] = elements[i];
	}
	free(elements);
	elements = p_elements;
}

template<typename T>
void sequent_stack::SequentStack<T>::push(const T e)
{
	if(mTop < mCapacity)
	{
		elements[mTop] = e;
	}
	else
	{
		mCapacity *= mFactor;
		extendCapacity(mCapacity);
		elements[mTop] = e;
	}
	mTop++;
}

template<typename T>
T sequent_stack::SequentStack<T>::pop()
{
	mTop--;
	return elements[mTop];
}

template<typename T>
bool sequent_stack::SequentStack<T>::empty()
{
	return 0 == mTop;
}

template<typename T>
int sequent_stack::SequentStack<T>::size()
{
	return mTop;
}

template<typename T>
bool sequent_stack::SequentStack<T>::clear()
{
	mTop = 0;
	free(elements);

	return true;
}

template<typename T>
void sequent_stack::SequentStack<T>::print()
{
	cout << "SequentStack: " << endl;
	cout << "     Size = " << mTop << endl;
	cout << "     Capacity = " << mCapacity << endl;
	cout << "     Elements = ";
	if(mTop > 0)
	{
		T t = pop();
		cout << t;
	}
	while(mTop > 0)
	{
		T t = pop();
		cout << "," << t;
	}
	cout << endl;
}
