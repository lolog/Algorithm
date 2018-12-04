#include "LinearList.h"

#include "SequentList.cpp"
#include "SinglyLinkList.cpp"
#include "DoublyLinkList.cpp"
#include "CyclyLinkList.cpp"

linear_list::LinearList::LinearList(void)
{
	m_sequent_list = new SeqentList<int>();
	m_singly_link  = new SinglyLinkList<int>();
	m_doubly_link  = new DoublyLinkList<int>();
	m_cycle_link   = new CyclyLinkList<int>();
}


linear_list::LinearList::~LinearList()
{
	delete m_sequent_list;
	delete m_singly_link;
	delete m_doubly_link;
}

void linear_list::LinearList::sequentList()
{
	for(int i=0; i<20; i++)
	{
		m_sequent_list->add(i);
	}
	m_sequent_list->set(8, 100);
	m_sequent_list->insert(8, 100);
	m_sequent_list->remove(1);
	m_sequent_list->print();
}

void linear_list::LinearList::singlyLinkList()
{
	m_singly_link->addHead(1);
	m_singly_link->addHead(2);
	m_singly_link->addTail(3);
	m_singly_link->addTail(4);
	m_singly_link->addTail(5);
	m_singly_link->del(1);
	m_singly_link->print();
}

void linear_list::LinearList::doublyLinkList()
{
	m_doubly_link->addHead(1);
	m_doubly_link->addHead(2);
	m_doubly_link->addTail(3);
	m_doubly_link->addTail(4);
	m_doubly_link->addTail(5);
	m_doubly_link->print();
	m_doubly_link->del(3);
	m_doubly_link->print();
}

void linear_list::LinearList::cycleLinkList()
{
	m_cycle_link->push(1);
	m_cycle_link->push(2);
	m_cycle_link->push(3);
	m_cycle_link->push(4);
	m_cycle_link->print();
}
