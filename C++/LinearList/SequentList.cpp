#include <malloc.h>
#include "SequentList.h"

template<typename T>
squent_list::SeqentList<T>::SeqentList()
{
	init(defaultCapacity);
}

template<typename T>
squent_list::SeqentList<T>::SeqentList(int capacity)
{
	init(capacity);
}

template<typename T>
void squent_list::SeqentList<T>::init(int capacity)
{
	mFactor   = 1.5f;
	mSize     = 0;
	mCapacity = capacity;

	pDatas    = (T*) malloc(capacity * sizeof(T));
}

template<typename T>
void squent_list::SeqentList<T>::extendCapacity(int capacity)
{
	T * p_datas = (T*) malloc(sizeof(T) * capacity);
	for(int i=0; i<mSize; i++) {
		p_datas[i] = pDatas[i];
	}
	free(pDatas);

	pDatas = p_datas;
}

template<typename T>
squent_list::SeqentList<T>::~SeqentList()
{
	delete pDatas;
}

template<typename T>
int squent_list::SeqentList<T>::size() const
{
	return mSize;
}

template<typename T>
int squent_list::SeqentList<T>::capacity() const
{
	return mCapacity;
}

template<typename T>
bool squent_list::SeqentList<T>::add(const T& t)
{
	if(mSize < mCapacity)
	{
		pDatas[mSize] = t;

		mSize++;
	}
	else
	{
		mCapacity = mCapacity * mFactor;
		// extend capacity
		extendCapacity(mCapacity);

		// add element
		pDatas[mSize] = t;

		mSize++;
	}
	return true;
}

template<typename T>
bool squent_list::SeqentList<T>::insert(int index, const T& t)
{
	if(mCapacity == mSize)
	{
		mCapacity = mCapacity * mFactor;
		extendCapacity(mCapacity);
	}
	if(index < mSize)
	{
		T _temp = pDatas[index];
		for(int i=mSize; i>index; i--)
		{
			pDatas[i] = pDatas[i-1];
		}
	}
	mSize++;
	pDatas[index] = t;

	return true;
}

template<typename T>
bool squent_list::SeqentList<T>::remove(const T& t)
{
	bool removed = false;
	for(int i=0; i<mSize; i++)
	{
		if(t == pDatas[i])
		{
			// left remove one position
			for(int j=i; j<mSize-1; j++)
			{
				pDatas[j] = pDatas[j+1];
			}
			mSize     -= 1;
			mCapacity -= 1;

			removed = true;
		}
	}
	return removed;
}

template<typename T>
int squent_list::SeqentList<T>::find(const T& t)
{
	for(int i=0; i<mSize; i++)
	{
		if(t == pDatas[i])
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
bool squent_list::SeqentList<T>::empty() const
{
	return 0 == mSize;
}

template<typename T>
const T& squent_list::SeqentList<T>::get(int index) const
{
	if(index >= mSize)
	{
		return NULL;
	}
	return pDatas[index];
}

template<typename T>
bool squent_list::SeqentList<T>::set(int index, const T& data)
{
	if(index >= mSize)
	{
		return false;
	}

	pDatas[index] = data;

	return true;
}

template<typename T>
void squent_list::SeqentList<T>::print() const
{
	using namespace std;
	cout << "SeqentList-->" << endl;
	cout << "    size     = " << mSize << endl;
	cout << "    Elements : " << endl;
	cout << "             ";
	if(mSize > 0)
	{
		cout << pDatas[0];
	}
	for(int i=1; i<mSize; i++)
	{
		cout << "," << pDatas[i];
	}
}
