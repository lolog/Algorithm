#include <iostream>
#include "SequentStack.h"
#include "LinkStack.h"

#ifndef __STACK__
#define __STACK__

namespace stack
{
	using namespace std;
	using sequent_stack::SequentStack;
	using link_stack::LinkStack;

	class Stack
	{
		public:
			Stack();
			~Stack();

		public:
			void sequentStack();
			void linkStack();

		private:
			SequentStack<int>* p_sequent_stack;
			LinkStack<int>*    p_link_stack;
	};
}

#endif
