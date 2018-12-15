#include "GList.h"
#include "GeneralList.cpp"

namespace g_list{
	GList::GList()
	{
		general_list = new GeneralList<int>();
	}

	GList::~GList()
	{
		delete general_list;
	}

	void GList::generalList()
	{
		// ================================
		// A(0, 1, 2)
		// B(0, 1)
		// C(3, 4)
		// D(2, 4, 5)
		// F(A, B, C, D)
		// ================================
		GeneralNode<int>* A = new GeneralNode<int>("A", 1);
		A->info.headSon        = new GeneralNode<int>("A1", 0, 0);
		A->info.headSon->nextSibling  = new GeneralNode<int>("A2", 0, 1);
		A->info.headSon->nextSibling->nextSibling = new GeneralNode<int>("A3", 0, 2);

		GeneralNode<int>* B = new GeneralNode<int>("B", 1);
		B->info.headSon        = new GeneralNode<int>("B1", 0, 0);
		B->info.headSon->nextSibling  = new GeneralNode<int>("B2", 0, 1);

		GeneralNode<int>* C = new GeneralNode<int>("C", 1);
		C->info.headSon        = new GeneralNode<int>("C1", 0, 3);
		C->info.headSon->nextSibling  = new GeneralNode<int>("C2", 0, 4);

		GeneralNode<int>* D = new GeneralNode<int>("D", 1);
		D->info.headSon        = new GeneralNode<int>("D1", 0, 2);
		D->info.headSon->nextSibling  = new GeneralNode<int>("D2", 0, 4);
		D->info.headSon->nextSibling->nextSibling = new GeneralNode<int>("D3", 0, 5);

		GeneralNode<int>* F = new GeneralNode<int>("F", 1);
		F->info.headSon = A;
		F->info.headSon->nextSibling = B;
		F->info.headSon->nextSibling->nextSibling = C;
		F->info.headSon->nextSibling->nextSibling->nextSibling = D;

		general_list->list(F);

		//	GeneralNode<int>* E = GeneralNode<int>::_copy(F);
		//	E->print();
		//
		//
		//	GeneralList<int>* phead = general_list->head();
		//	phead->print();
		//	delete phead;

		GeneralList<int>* ptail = general_list->tail();
		ptail->print();
		delete ptail;
	}
}
