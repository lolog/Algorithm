#include <iostream>

#ifndef __TREE_QUEUE__
#define __TREE_QUEUE__

namespace tree_queue
{
	using namespace std;
	template<typename T>
	class TreeQueue
	{
		public:
			TreeQueue();
			TreeQueue(T* t);
			~TreeQueue();

		public:
			void init(int size);
			void extend();
			void gc();

			void push(T* t);
			void clear();
			T* current();
			void next();

		private:
			T* ptr;

			TreeQueue<T>* curr;
			TreeQueue<T>* end;

			TreeQueue<T>* front;
			TreeQueue<T>* rear;
	};
}

#endif
