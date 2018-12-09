//============================================================================
// 功能： 双向链表
// 结构： 链表由节点组成,每个节点包含了数据域和指针域(或链域)
// 占用空间： n * sizeof(T), n - 线性表的长度
// 特点： 1.动态扩容
//       2.节点元素逻辑位置与数据元素顺序没有必然关系
// 性能： 1.链表需要指针域维护节点元素间的关系,因此比顺序表占用更大的存储空间
//        2.增加head和tail辅助节点,节省插入或者寻找尾节点耗时时间
//        3.插入时间复杂度为：O(1)
//        4.删除元素平均寻找次数
//          AMN=∑pi * ci=∑i * 1/2n = (1 + ..., n-1) * 1/n = (n-1)/4
// 缺点： 需要多用一个prev节点指针维护前后节点关系
// 优点：1.相对于顺序表,容易扩容
//       2.相对于单向链表来说,可以双向访问,遍历的时间复杂度为O(n/4)
//============================================================================

#include<iostream>
#include "../Common/DataType.hpp"

#ifndef __DOUBLY_LINK_LIST__
#define __DOUBLY_LINK_LIST__

namespace doubly_list
{
	using namespace std;

	template <typename Type>
	class DoublyLinkList
	{
		public:
			DoublyLinkList();
			~DoublyLinkList();

		public:
			void addHead(Type e);
			void addTail(Type e);

			bool del(Type e);

			int size();

			bool contains(Type e);
			void print();

		private:
			int m_count;

			DoublyNode<Type> *head;
			DoublyNode<Type> *tail;
	};
}

#endif
