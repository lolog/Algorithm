#include <iostream>
#include "SequentQueue.h"
#include "SinglyLinkQueue.h"
#include "DoublyLinkQueue.h"

#ifndef __QUEUE__
#define __QUEUE__

namespace queue
{
	using namespace std;
	using sequent_queue::SequentQueue;
	using singly_link_queue::SinglyLinkQueue;
	using doubly_link_queue::DoublyLinkQueue;

	class Queue
	{
		public:
			Queue();
			~Queue();

		public:
			void sequentQueue();
			void singlyLinkQueue();
			void doublyLinkQueue();

		private:
			SequentQueue<int>*    p_sequent_queue;
			SinglyLinkQueue<int>* p_singly_link_queue;
			DoublyLinkQueue<int>* p_doubly_link_queue;
	};
}

#endif
