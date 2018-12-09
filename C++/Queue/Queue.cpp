#include "Queue.h"
#include "SequentQueue.cpp"
#include "SinglyLinkQueue.cpp"
#include "DoublyLinkQueue.cpp"

queue::Queue::Queue()
{
	p_sequent_queue     = new SequentQueue<int>();
	p_singly_link_queue = new SinglyLinkQueue<int>();
	p_doubly_link_queue = new DoublyLinkQueue<int>();
}

queue::Queue::~Queue()
{
	delete p_sequent_queue;
	delete p_singly_link_queue;
	delete p_doubly_link_queue;
}

void queue::Queue::sequentQueue()
{
	for(int i=0; i<6; i++)
	{
		p_sequent_queue->push(i);
	}
	p_sequent_queue->print();
}

void queue::Queue::singlyLinkQueue()
{
	for(int i=0; i<6; i++)
	{
		p_singly_link_queue->push(i);
	}
	p_singly_link_queue->print();
}

void queue::Queue::doublyLinkQueue()
{
	for(int i=0; i<6; i++)
	{
		p_doubly_link_queue->push(i);
	}
	for(int i=6; i<12; i++)
	{
		p_doubly_link_queue->rpush(i);
	}
	p_doubly_link_queue->print();
}
