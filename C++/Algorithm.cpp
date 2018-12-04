//============================================================================
// Name        : Algorithm.cpp
// Author      : felix
// Version     : 1.0.0
// Copyright   :
// Description : Algorithm
//============================================================================
#include <iostream>
#include <string.h>

#include "LinearList/LinearList.cpp"

using namespace std;
using linear_list::LinearList;

int main()
{
	string str_func;

	cout << "please select module..." << endl;
	cin >> str_func;

	// List
	string::size_type index_list_ = str_func.find("List");

	if(index_list_ != str_func.npos)
	{
		LinearList* link_list = new LinearList();
		if(0 == strcasecmp("SeqentList", str_func.c_str()))
		{
			link_list->sequentList();
		}
		if(0 == strcasecmp("SinglyLinkList", str_func.c_str()))
		{
			link_list->singlyLinkList();
		}
		if(0 == strcasecmp("DoublyLinkList", str_func.c_str()))
		{
			link_list->doublyLinkList();
		}
		if(0 == strcasecmp("CyclyLinkList", str_func.c_str()))
		{
			link_list->cycleLinkList();
		}
		delete link_list;
	}
	return 0;
}
