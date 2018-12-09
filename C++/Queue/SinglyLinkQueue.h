//===============================================================================
// 功能：队列
// 元素：队尾(rear)、对头(front)
//===============================================================================
#include <iostream>
#include "../Common/DataType.hpp"

#ifndef __SINGLY_LINK_QUEUE__
#define __SINGLY_LINK_QUEUE__

namespace singly_link_queue
{
	using namespace std;

	template<typename T>
	class SinglyLinkQueue
	{
		public:
			SinglyLinkQueue();
			~SinglyLinkQueue();

		public:
			bool push(T t);
			T pop();

			bool empty();
			int size();
			void clear();

			void print();

		private:
			int mSize;

			SinglyNode<T>* front;
			SinglyNode<T>* rear;
	};
}

#endif
