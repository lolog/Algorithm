#include "Stack.h"
#include "SequentStack.cpp"
#include "LinkStack.cpp"

stack::Stack::Stack()
{
	p_sequent_stack =  new SequentStack<int>();
	p_link_stack    = new LinkStack<int>();
}

stack::Stack::~Stack()
{
	delete p_sequent_stack;
	delete p_link_stack;
}

void stack::Stack::sequentStack()
{
	for(int i=0; i<8; i++) {
		p_sequent_stack->push(i);
	}
	p_sequent_stack->print();
}

void stack::Stack::linkStack()
{
	for(int i=0; i<8; i++) {
		p_link_stack->push(i);
	}
	p_link_stack->print();

	for(int i=10; i<18; i++) {
		p_link_stack->rpush(i);
	}
	p_link_stack->rprint();

	p_link_stack->clear();
	p_link_stack->print();
}
