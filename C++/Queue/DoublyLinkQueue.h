#include <iostream>
#include "../Common/DataType.hpp"

#ifndef __DOUBLY_LINK_QUEUE__
#define __DOUBLY_LINK_QUEUE__

namespace doubly_link_queue
{
	using namespace std;

	template<typename T>
	class DoublyLinkQueue
	{
		public:
			DoublyLinkQueue();
			~DoublyLinkQueue();

		public:
			bool push(T t);
			T pop();

			bool rpush(T t);
			T rpop();

			bool empty();
			int size();
			void clear();

			void print();

		private:
			int mSize;

			DoublyNode<T>* front;
			DoublyNode<T>* rear;
	};
}

#endif
