#include "GeneralList.h"
#include "DataType.cpp"

namespace gereral_list {
	template<typename T>
	GeneralList<T>::GeneralList()
	{
		hlink = GeneralNode<T>::createNull();
	}

	template<typename T>
	GeneralList<T>::GeneralList(GeneralNode<T>* node)
	{
		hlink = node;
	}

	template<typename T>
	GeneralList<T>::~GeneralList()
	{
		hlink->gc();
		hlink = NULL;
	}

	template<typename T>
	void GeneralList<T>::list(GeneralNode<T>* node)
	{
		// gc
		hlink->gc();
		hlink = node;
	}

	template<typename T>
	GeneralList<T>* GeneralList<T>::head()
	{
		GeneralNode<T>* phead = hlink->head();
		return new GeneralList<T>(phead);
	}

	template<typename T>
	GeneralList<T>* GeneralList<T>::tail()
	{
		GeneralNode<int>* p_node = hlink->tail();
		return new GeneralList<T>(p_node);
	}

	template<typename T>
	int GeneralList<T>::length()
	{
		return hlink->length();
	}

	template<typename T>
	int GeneralList<T>::depth()
	{
		return hlink->depth();
	}

	template<typename T>
	void GeneralList<T>::print()
	{
		hlink->print();
	}

}
