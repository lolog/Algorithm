#include<iostream>

#ifndef __SEQUENT_STACK__
#define __SEQUENT_STACK__

namespace sequent_stack
{
	using namespace std;

	const int defaultSize = 5;

	template<typename T>
	class SequentStack
	{
		public:
			SequentStack();
			SequentStack(int capacity);
			~SequentStack();

		public:
			void push(const T e);
			T pop();
			bool empty();
			int size();
			bool clear();

			void print();

		private:
			void init(float factor, int capacity);
			void extendCapacity(int capacity);

		private:
			T* elements;

			int mTop;
			float mFactor;
			int mCapacity;
	};
}

#endif
