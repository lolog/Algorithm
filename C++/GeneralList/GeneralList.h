#include <iostream>
#include "DataType.h"

#ifndef __GENERAL_LIST__
#define __GENERAL_LIST__


//===============================================
// ()
// A(0, 1, 2)
// B(0, 1)
// C(3, 4)
// D(2, 4, 5)
// F(A, B, C, D)
//===============================================
namespace gereral_list
{
	using namespace std;

	template<typename T>
	class GeneralList
	{
		public:
			GeneralList();
			GeneralList(GeneralNode<T>* node);
			~GeneralList();

		public:
			void list(GeneralNode<T>* node);

			// head element, for example A
			GeneralList<T>* head();
			// tail list, for example, (B, C, D)
			GeneralList<T>* tail();

			int length();
			int depth();

			void print();

		private:
			GeneralNode<T>* hlink;
	};
}

#endif
