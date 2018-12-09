#include "LinkStack.h"

template<typename T>
link_stack::LinkStack<T>::LinkStack()
{
	mSize  = 0;
	top    = NULL;
	buttom = NULL;
}

template<typename T>
link_stack::LinkStack<T>::~LinkStack()
{
	clear();
}

template<typename T>
void link_stack::LinkStack<T>::push(T t)
{
	if(top == NULL || buttom == NULL)
	{
		top    = new DoublyNode<T>(t);
		buttom = top;

		top->next    = buttom;
		buttom->prev = top;
	}
	else
	{
		DoublyNode<T>* p_node = new DoublyNode<T>(t, buttom);

		buttom->next = p_node;
		buttom       = p_node;
	}

	mSize++;
}

template<typename T>
T link_stack::LinkStack<T>::pop()
{
	T t = buttom->m_data;

	DoublyNode<T>* p_node = buttom->prev;
	delete buttom;

	if(mSize == 1)
	{
		top = buttom = NULL;
	}
	else
	{
		buttom = p_node;
	}

	mSize--;

	return t;
}

template<typename T>
void link_stack::LinkStack<T>::rpush(T t)
{
	if(top == NULL || buttom == NULL)
	{
		top    = new DoublyNode<T>(t);
		buttom = top;

		top->next    = buttom;
		buttom->prev = top;
	}
	else
	{
		DoublyNode<T>* p_node = new DoublyNode<T>(t, NULL, top);

		p_node->prev = p_node;
		top          = p_node;
	}

	mSize++;
}

template<typename T>
T link_stack::LinkStack<T>::rpop()
{
	T t = top->m_data;

	DoublyNode<T>* p_node = top->next;
	delete top;

	if(mSize == 1)
	{
		top = buttom = NULL;
	}
	else
	{
		top = p_node;
	}

	mSize--;

	return t;
}

template<typename T>
bool link_stack::LinkStack<T>::empty()
{
	return 0 == mSize;
}

template<typename T>
int link_stack::LinkStack<T>::size()
{
	return mSize;
}

template<typename T>
bool link_stack::LinkStack<T>::clear()
{
	DoublyNode<T>* p_node = NULL;
	while(top != NULL)
	{
		p_node = top->next;
		delete top;
		top    = p_node;
	}

	mSize  = 0;
	top    = NULL;
	buttom = NULL;

	return true;
}

template<typename T>
void link_stack::LinkStack<T>::print()
{
	cout << "LinkStack:" << endl;
	cout << "     Size = " << mSize << endl;
	cout << "     Elements = ";

	if(mSize > 0)
	{
		cout << pop();
	}
	else
	{
		cout << "None" << endl;
	}
	while(mSize > 0)
	{
		cout << "," << pop();
	}
	cout << endl;
}

template<typename T>
void link_stack::LinkStack<T>::rprint()
{
	cout << "LinkStack:" << endl;
	cout << "     Size[R] = " << mSize << endl;
	cout << "     Elements[R]= ";

	if(mSize > 0)
	{
		cout << rpop();
	}
	else
	{
		cout << "None" << endl;
	}
	while(mSize > 0)
	{
		cout << "," << rpop();
	}
	cout << endl;
}
