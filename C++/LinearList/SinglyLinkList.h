//============================================================================
// 功能： 单链表,亦或线性链表
// 结构： 链表由节点组成,每个节点包含了数据域和指针域(或链域)
// 占用空间： n * sizeof(T), n - 线性表的长度
// 特点： 1.动态扩容
//       2.节点元素逻辑位置与数据元素顺序没有必然关系
// 性能： 1.链表需要指针域维护节点元素间的关系,因此比顺序表占用更大的存储空间
//        2.增加head和tail辅助节点,节省插入或者寻找尾节点耗时时间
//        3.插入时间复杂度为：O(1)
//        4.删除元素平均寻找次数
//          AMN=∑pi * ci=∑i * 1/n = (1 + ..., n-1) * 1/n = (n-1)/2
// 缺点：只能从头到尾遍历节点元素,只保存后继节点元素
// 优点：相对于顺序表,容易扩容
//============================================================================

#include<iostream>
#include "DataType.hpp"

#ifndef __SINGLY_LINK_LIST__
#define __SINGLY_LINK_LIST__

namespace singly_list
{
	using namespace std;

	template <typename Type>
	class SinglyLinkList
	{
		public:
			SinglyLinkList();
			~SinglyLinkList();

		public:
			void addHead(Type e);
			void addTail(Type e);

			bool del(Type e);

			int size();

			bool contains(Type e);
			void print();

		private:
			int m_count;

			SinglyNode<Type> *head;
			SinglyNode<Type> *tail;
	};
}

#endif
