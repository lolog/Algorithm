#include <iostream>
#include <string.h>

#include "SequentList.h"
#include "SinglyLinkList.h"
#include "DoublyLinkList.h"
#include "CyclyLinkList.h"

#ifndef __LINEAR_LIST__
#define __LINEAR_LIST__

namespace linear_list
{
	using squent_list::SeqentList;
	using singly_list::SinglyLinkList;
	using doubly_list::DoublyLinkList;
	using cycly_link::CyclyLinkList;

	class LinearList
	{
		public:
			LinearList();
			~LinearList();

		public:
			void sequentList();
			void singlyLinkList();
			void doublyLinkList();
			void cycleLinkList();

		private:
			SeqentList<int>*     m_sequent_list;
			SinglyLinkList<int>* m_singly_link;
			DoublyLinkList<int>* m_doubly_link;

			CyclyLinkList<int>* m_cycle_link;
	};
}

#endif
