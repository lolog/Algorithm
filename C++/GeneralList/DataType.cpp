#include <iostream>
#include <string.h>
#include "DataType.h"

using namespace std;

template<typename T>
GeneralNode<T>::GeneralNode(string _name, int _utype)
{
	init(_name, _utype);
}

template<typename T>
GeneralNode<T>::GeneralNode(string _name, int _utype, T value)
{
	if(1 == _utype)
	{
		cout << "this is data node, otherwise utype = 0" << endl;
		exit(0);
	}
	init(_name, _utype);
	info.value  = value;
}

template<typename T>
GeneralNode<T>::~GeneralNode()
{
}

template<typename T>
void GeneralNode<T>::init(string _name, int _utype)
{
	name         = _name;
	utype        = _utype;
	reference    = 0;

	nextSibling  = NULL;
	info.headSon = NULL;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::ref(int _ref)
{
	utype     = 0;
	reference = _ref;

	return this;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::value(T val)
{
	utype      = 1;
	info.value = val;

	return this;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::tail()
{
	GeneralNode<int>* p_node = NULL;
	// for example, (B, C, D)
	if(0 == utype || NULL == info.headSon || NULL == info.headSon->nextSibling)
	{
		p_node = GeneralNode<int>::createNull();
	}
	else
	{
		p_node = GeneralNode<int>::copy(info.headSon->nextSibling, "Tail");
	}
	return p_node;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::head()
{
	GeneralNode<T>* p_result = NULL;
	// null or element
	// for example, A(0, 1, 2) or F()
	if(0 == utype || isNull() || NULL == info.headSon)
	{
		p_result       = new GeneralNode<T>(name, utype);
		p_result->info = info;
		return this;
	}
	p_result = GeneralNode<T>::_copy(info.headSon);
	// head is not next sibling
	p_result->nextSibling = NULL;
	return p_result;
}

template<typename T>
int GeneralNode<T>::length()
{
	if(0 == utype || isNull() || NULL == info.headSon)
	{
		return 1;
	}
	return _length(info.headSon);
}
template<typename T>
int GeneralNode<T>::_length(GeneralNode<T>* pointer)
{
	if(NULL == pointer)
	{
		return 0;
	}
	return 1 + _length(pointer->nextSibling);
}

template<typename T>
int GeneralNode<T>::depth()
{
	return _depth(this);
}

template<typename T>
int GeneralNode<T>::_depth(GeneralNode<T>* pointer)
{
	if(NULL == pointer)
	{
		return 1;
	}

	int max_depth = 0;
	if(1 == pointer->utype)
	{
		int m_depath = _depth(pointer->info.headSon);

		if(max_depth < m_depath)
		{
			max_depth = m_depath;
		}
		return max_depth + 1;
	}

	GeneralNode<T>* p_node = pointer->nextSibling;
	int m_depth =  _depth(p_node);
	if(max_depth < m_depth)
	{
		max_depth = m_depth;
	}
	return max_depth;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::type(int _utype)
{
	utype        = _utype;

	return this;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::next(GeneralNode<T>* next)
{
	return GeneralNode<T>::_copy(nextSibling);
}

template<typename T>
bool GeneralNode<T>::isNull()
{
	if(0 == strcasecmp("NULL", name.c_str()))
	{
		return true;
	}
	return false;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::createNull()
{
	return new GeneralNode<T>("NULL", 1);
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::copy(GeneralNode<T>* pointer, string name)
{
	GeneralNode<T>* p_node = GeneralNode<T>::_copy(pointer);
	if(NULL == p_node)
	{
		return GeneralNode<T>::createNull();
	}
	if(NULL != p_node->nextSibling)
	{
		GeneralNode<T>* p_result = new GeneralNode<T>(name, 1);
		p_result->info.headSon   = p_node;
		return p_result;
	}
	return p_node;
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::_copy(GeneralNode<T>* pointer)
{
	GeneralNode<T>* p_node = NULL;
	if(NULL != pointer)
	{
		p_node        = new GeneralNode<T>(pointer->name, 1);
		p_node->utype = pointer->utype;

		switch(pointer->utype)
		{
			case 0:
				{
					p_node->info.value    = pointer->info.value;
				}
				break;
			case 1:
				{
					p_node->info.headSon  = _copy(pointer->info.headSon);
				}
				break;
		}

		p_node->nextSibling = _copy(pointer->nextSibling);
	}
	return p_node;
}

template<typename T>
void GeneralNode<T>::print()
{
	cout << "GeneralNode: name = " << name << ", length = " << length() << ", depth = " << depth() << endl;
	cout << "name , utype , value" << endl;
	_print(this);
}

template<typename T>
void GeneralNode<T>::gc()
{
	_gc(nextSibling);
	_gc(info.headSon);
}

template<typename T>
GeneralNode<T>* GeneralNode<T>::_gc(GeneralNode<T>* pointer)
{
	if(NULL != pointer)
	{
		if(1 == pointer->utype)
		{
			pointer->info.headSon = _gc(pointer->info.headSon);
		}
		pointer->nextSibling = _gc(pointer->nextSibling);
		delete pointer;
		pointer = NULL;
	}
	return NULL;
}

template<typename T>
void GeneralNode<T>::_print(GeneralNode<T>* pointer)
{
	if(NULL != pointer)
	{
		string name = pointer->name;
		switch(name.length())
		{
			case 0: name += "      "; break;
			case 1: name += "     "; break;
			case 2: name += "    "; break;
			case 3: name += "   "; break;
			case 4: name += "  "; break;
			case 5: name += " "; break;
			default: ; break;
		}
		switch(pointer->utype)
		{
			case 0: cout << name << ",   " << pointer->utype << "   ,   " << pointer->info.value << endl; break;
			case 1:
				{
					cout << name  << ",   " << pointer->utype << endl;
					_print(pointer->info.headSon);
				};
				break;
		}
		_print(pointer->nextSibling);
	}
}
