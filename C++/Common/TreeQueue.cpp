#include "TreeQueue.h"

namespace tree_queue
{
	template<typename T>
	TreeQueue<T>::TreeQueue()
	{
		ptr   = NULL;
		front = rear = curr = end = NULL;
	}

	template<typename T>
	TreeQueue<T>::TreeQueue(T* t)
	{
		ptr   = t;
		front = rear = curr = end = NULL;
	}

	template<typename T>
	TreeQueue<T>::~TreeQueue()
	{
	}

	template<typename T>
	void TreeQueue<T>::init(int size)
	{
		front = rear = curr = end  = new TreeQueue<T>();
		for(int i=0; i<size; i++)
		{
			extend();
		}
	}

	template<typename T>
	void TreeQueue<T>::extend()
	{
		TreeQueue<T>* p_queue = new TreeQueue<T>();
		p_queue->front = rear;
		rear->rear     = p_queue;
		rear           = p_queue;
	}

	template<typename T>
	void TreeQueue<T>::gc()
	{
		TreeQueue<T>* p_node = NULL;
		while(NULL != front)
		{
			p_node = front->rear;
			delete front;
			front  = p_node;
		}
		front = rear = NULL;
		delete this;
	}

	template<typename T>
	void TreeQueue<T>::push(T* t)
	{
		if(NULL == t)
		{
			return;
		}
		if(NULL == end)
		{
			front = rear = curr = end  = new TreeQueue<T>();
		}
		if(NULL == end->rear)
		{
			extend();
		}
		end->ptr = t;
		end      = end->rear;
	}

	template<typename T>
	void TreeQueue<T>::clear()
	{
		TreeQueue<T>* p_node = front;
		while(NULL != p_node)
		{
			p_node->ptr = NULL;
			p_node      = p_node->rear;
		}
		curr = end = front;
	}
	template<typename T>
	T* TreeQueue<T>::current()
	{
		return curr->ptr;
	}

	template<typename T>
	void TreeQueue<T>::next()
	{
		curr = curr->rear;
	}
}
