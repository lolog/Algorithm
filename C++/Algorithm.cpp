//============================================================================
// Name        : Algorithm.cpp
// Author      : felix
// Version     : 1.0.0
// Copyright   :
// Description : Algorithm
//============================================================================
#include <iostream>
#include <string.h>

#include "LinearList/LinearList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "Matrix/Matrix.cpp"
#include "GeneralList/GList.cpp"
#include "Tree/Tree.cpp"
#include "Heap/Heap.cpp"

using namespace std;
using linear_list::LinearList;
using stack::Stack;
using queue::Queue;
using matrix::Matrix;
using g_list::GList;
using tree::Tree;
using heap::Heap;

int main()
{
	string str_func;

	cout << "please select module..." << endl;
	cin >> str_func;

	// List
	string::size_type index_list_ = str_func.find("List");

	if(index_list_ != str_func.npos)
	{
		LinearList* link_list = new LinearList();
		if(0 == strcasecmp("SeqentList", str_func.c_str()))
		{
			link_list->sequentList();
		}
		if(0 == strcasecmp("SinglyLinkList", str_func.c_str()))
		{
			link_list->singlyLinkList();
		}
		if(0 == strcasecmp("DoublyLinkList", str_func.c_str()))
		{
			link_list->doublyLinkList();
		}
		if(0 == strcasecmp("CyclyLinkList", str_func.c_str()))
		{
			link_list->cycleLinkList();
		}
		delete link_list;
	}

	// Stack
	index_list_ = str_func.find("Stack");
	if(index_list_ != str_func.npos)
	{
		Stack* stack = new Stack();
		if(0 == strcasecmp("SequentStack", str_func.c_str()))
		{
			stack->sequentStack();
		}
		if(0 == strcasecmp("LinkStack", str_func.c_str()))
		{
			stack->linkStack();
		}
		delete stack;
	}

	// Stack
	index_list_ = str_func.find("Queue");
	if(index_list_ != str_func.npos)
	{
		Queue* queue = new Queue();
		if(0 == strcasecmp("SequentQueue", str_func.c_str()))
		{
			queue->sequentQueue();
		}
		if(0 == strcasecmp("SinglyLinkQueue", str_func.c_str()))
		{
			queue->singlyLinkQueue();
		}
		if(0 == strcasecmp("DoublyLinkQueue", str_func.c_str()))
		{
			queue->doublyLinkQueue();
		}
		delete queue;
	}

	// List
	index_list_ = str_func.find("Matrix");
	if(index_list_ != str_func.npos)
	{
		Matrix* matrix = new Matrix();
		if(0 == strcasecmp("SparseMatrix", str_func.c_str()))
		{
			matrix->sparseMatrix();
		}
		delete matrix;
	}

	// List
	index_list_ = str_func.find("General");
	if(index_list_ != str_func.npos)
	{
		GList* glist = new GList();
		if(0 == strcasecmp("GeneralList", str_func.c_str()))
		{
			glist->generalList();
		}
		delete glist;
	}

	// List
	index_list_ = str_func.find("Tree");
	if(index_list_ != str_func.npos)
	{
		Tree* tree = new Tree();
		if(0 == strcasecmp("BinaryTree", str_func.c_str()))
		{
			tree->binaryTree();
		}
		delete tree;
	}

	// Heap
	index_list_ = str_func.find("Heap");
	if(index_list_ != str_func.npos)
	{
		Heap* heap = new Heap();
		if(0 == strcasecmp("LinkHeap", str_func.c_str()))
		{
			heap->linkHeap();
		}
		delete heap;
	}

	return 0;
}
