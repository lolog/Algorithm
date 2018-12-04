//============================================================================
// 功能： 顺序表
// 定义： 节点元素按照其逻辑顺序依次存储到一块连续的存储空间中。
// 占用空间： n * sizeof(T), n - 线性表的长度
// 特点： 1.节点元素的逻辑顺序=存放的物理顺序,即ai存储于第i个物理位置
//       2.物理地址
//          Loc(i) = Loc(0) + i * sizeof(T)
//       3.元素可以顺序访问,也可以随机访问
// 性能： 1.搜索算法为循环遍历,搜索的平均数据比较次数：
//          ACN=∑pi * ci = (1 / n+1) * (1 + 2 + ... + n) = n/2
//          pi - 节点元素搜索的概率,          p1 = p2 = ... = pn = 1/n
//          ci - 找到节点元素i的比较次数, ci = i
//        2.删除元素,需要保持节点元素位置不变,平均数据移动次数：
//          AMN=∑pi * ci = ∑(n-i) * (1 / n+1) = n/2
// 优点：1.不需要为节点间逻辑关系增加额外的存储空间,存储利用率高
//       2.随机访问任一节点元素速度快
// 缺点：1.删除或者中间插入元素时,为了保证元素间逻辑顺序,AMN=n/2,运行效率很低
//       2.当容量不足时,按照factor因子拓展存储空间,如果不能充分利用,会造成空间闲置浪费
//=============================================================================
#include <ostream>

#ifndef __SEQUENTIAL_LIST__
#define __SEQUENTIAL_LIST__

namespace squent_list
{
	const int defaultCapacity = 10;

	template<typename T>
	class SeqentList
	{
		public:
			SeqentList();
			SeqentList(int capacity);
			~SeqentList();

		public:
			int size() const;
			int capacity() const;

			bool add(const T& t);
			bool insert(int index, const T& t);
			bool remove(const T& t);
			int find(const T& t);

			bool empty() const;
			const T& get(int index) const;
			bool set(int index, const T& data);

			void print() const;
		private:
			void init(int capacity);
			void extendCapacity(int capacity);

		private:
			T   *pDatas;

			int mSize;
			int mCapacity;

			float mFactor;
	};
}

#endif
