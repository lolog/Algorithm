#include <ostream>
#include "DataType.hpp"

#ifndef __CYCLY_LINK_LIST__
#define __CYCLY_LINK_LIST__

namespace cycly_link
{
	using namespace std;

	const int defaultSize = 3;

	template<typename T>
	class CyclyLinkList
	{
		public:
			CyclyLinkList();
			CyclyLinkList(int capacity);
			~CyclyLinkList();

		public:
			bool push(T e);
			T pop();
			void print();
		private:
			void init(int capacity);

		private:
			int mCount;
			int mCapacity;

			SinglyNode<int>* tail;
			SinglyNode<int>* current;
	};
}

#endif
