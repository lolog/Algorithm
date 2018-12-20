#include "LinkHeap.h"

#ifndef __HEAP__
#define __HEAP__

namespace heap
{
	using namespace std;
	using link_heap::LinkHeap;

	class Heap
	{
		public:
			Heap();
			~Heap();

		public:
			void linkHeap();

		private:
			LinkHeap<int>* link_heap;
	};
}

#endif
