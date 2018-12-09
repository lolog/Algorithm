#include <iostream>
#include "../Common/DataType.hpp"

#ifndef __LINK_STACK__
#define __LINK_STACK__

namespace link_stack
{
	using namespace std;

	template<typename T>
	class LinkStack
	{
		public:
			LinkStack();
			~LinkStack();

		public:
			void push(T t);
			T pop();

			void rpush(T t);
			T rpop();

			bool empty();
			int size();
			bool clear();

			void print();
			void rprint();

		private:
			int mSize;

			DoublyNode<T>* top;
			DoublyNode<T>* buttom;
	};
}

#endif
