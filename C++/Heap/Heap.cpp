#include "Heap.h"

#include "../Common/DataType.hpp"
#include "LinkHeap.cpp"

namespace heap
{
	Heap::Heap()
	{
		link_heap = new LinkHeap<int>();
	}

	Heap::~Heap()
	{
		delete link_heap;
	}

	void Heap::linkHeap()
	{
		//==============================
		//          10
		//     11        12
		//  13    14  15    16
		//17   30
		//==============================
		link_heap->insert(10);
		link_heap->insert(13);
		link_heap->insert(15);
		link_heap->insert(12);
		link_heap->insert(14);
		link_heap->insert(11);
		link_heap->insert(16);
		link_heap->insert(17);
		link_heap->insert(18);

		cout << "element 11 is exist = " << link_heap->find(11) << endl;
		link_heap->print();
		link_heap->del(13);
		link_heap->print();
	}
}
