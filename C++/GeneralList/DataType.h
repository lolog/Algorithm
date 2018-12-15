#include <ostream>
#include <string.h>

#ifndef __GENERAL_DATA_TYPE_
#define __GENERAL_DATA_TYPE_

using namespace std;

//=========================================================
// utype: 0 -> data node, info.ref
//        1 -> list, info.headSon
//=========================================================
template<typename T>
class GeneralNode
{
	public:
		//=====================================
		// null general list, for example: A()
		// utype=0, info.ref=0, next=null
		//=====================================
		GeneralNode(string _name, int _utype);
		GeneralNode(string _name, int _utype, T value);
		~GeneralNode();

	public:
		GeneralNode<T>* type(int _utype);
		GeneralNode<T>* ref(int ref);
		GeneralNode<T>* value(T val);

		GeneralNode<T>* tail();
		GeneralNode<T>* head();

		int length();
		int depth();

		GeneralNode<T>* next(GeneralNode<T>* next);

		// copy(F) = (A, B)
		static GeneralNode<T>* copy(GeneralNode<T>* pointer, string name);
		void print();

		// is Null node
		bool isNull();

	public:
		//======================================
		// note: delete cannot call this method
		// gc this
		//======================================
		void gc();
		static GeneralNode<T>* createNull();

	private:
		void init(string _name, int _utype);

		int _length(GeneralNode<T>* pointer);
		int _depth(GeneralNode<T>* pointer);

		//===================================
		// A(0,1)
		// B(2,3)
		// F(A, B)
		// _copy(F) -> A, B
		//===================================
		static GeneralNode<T>* _copy(GeneralNode<T>* pointer);
		//==================================
		// gc pointer
		//==================================
		GeneralNode<T>* _gc(GeneralNode<T>* pointer);
		//==================================
		// print pointer details
		//==================================
		void _print(GeneralNode<T>* pointer);

	public:
		string name;
		int    utype;
		int    reference;  // reference count

		union
		{
			T value;                 // utype=0, data value
			GeneralNode<T>* headSon; // utype=1, child list
		} info;

		GeneralNode<T>* nextSibling; // next sibling
};

#endif
