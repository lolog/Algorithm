#include <iostream>

//===============================================================================
// 功能：循环队列
// 定义：队列是一种只能在表的一端进行插入运算,在表的另一端进行删除运算的线性表(头删尾插),存储方式分为顺序队或链队,以循环队列更常见。
// 问题：在循环队列中,空队特征是front = rear, 队满时也会有front = rear; 判断条件将出现二义性。
// 方案：1.标志位法：pop flag=1,push flag=0,可识别front == rear的语义
//       2.队列长度发：使用一个计数器记录队列中元素个数
//       3.空闲单元法:浪费1个单元,则队满特征为： front = (rear +1)%N
//===============================================================================

#ifndef __SEQUENT_QUEUE__
#define __SEQUENT_QUEUE__

namespace sequent_queue
{
	using namespace std;

	const int defaultSize = 5;

	template<typename T>
	class SequentQueue
	{
		public:
			SequentQueue();
			SequentQueue(int capacity);
			~SequentQueue();

		public:
			bool push(T t);
			T pop();

			bool empty();
			int size();
			void clear();

			void print();

		private:
			void init(int capacity);

		private:
			T* elements;

			int front;
			int rear;

			int mCapacity;
	};
}

#endif
