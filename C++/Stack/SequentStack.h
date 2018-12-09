//==================================================================
// 功能：栈
// 定义：只允许在表的末端进行插入和删除的线性表，包括元素有栈顶和栈底
//       栈是FIFO的线性表
// 分类：顺序栈和链式栈
//==================================================================
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
