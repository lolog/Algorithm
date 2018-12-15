#include "CyclyLinkList.h"

namespace cycly_link{
	template<typename T>
	CyclyLinkList<T>::CyclyLinkList()
	{
		init(defaultSize);
	}

	template<typename T>
	CyclyLinkList<T>::CyclyLinkList(int capacity)
	{
		init(capacity);
	}

	template<typename T>
	void CyclyLinkList<T>::init(int capacity)
	{
		mCount    = 0;
		mCapacity = capacity;
		tail      = current = NULL;
	}

	template<typename T>
	CyclyLinkList<T>::~CyclyLinkList()
	{
		SinglyNode<int>* p_tail = tail;
		while(tail != NULL)
		{
			p_tail = tail->next;
			delete tail;
			tail   = p_tail;
		}
	}

	template<typename T>
	bool CyclyLinkList<T>::push(T e)
	{
		if(0 == mCount)
		{
			mCount++;
			tail = current  = new SinglyNode<int>(e);
			tail->next      = current;
			return true;
		}
		if(mCount < mCapacity)
		{
			mCount++;
			tail->next = new SinglyNode<int>(e);
			tail       = tail->next;
			tail->next = current;
		}
		return false;
	}

	template<typename T>
	T CyclyLinkList<T>::pop()
	{
		if(0 == mCount)
		{
			cerr << "CyclyLinkList, mCount is zero!";
		}

		mCount--;

		SinglyNode<T>* p_temp = current;
		current = current->next;

		T t     = p_temp->m_data;
		delete p_temp;

		return t;
	}

	template<typename T>
	void CyclyLinkList<T>::print()
	{
		cout << "CyclyLinkList:" << endl;
		cout << "    count = " << mCount << endl;
		if(mCount == 0)
		{
			return;
		}

		cout << "    Element:";
		while(mCount > 0)
		{
			T t = pop();
			cout << ", " <<  t;
		}
	}

}
