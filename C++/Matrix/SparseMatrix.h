//============================================================================
// 功能：稀疏矩阵
// 定义：非零元素的个数远小于零元素的个数,而且元素分布没有规律
// 条件：δ = t/(m * n), δ -稀疏因子. t - 非零元素个数, m - 矩阵行, n - 矩阵列
//       δ < 0.05
// 二维数组：优点是转置、访问、运算简便,
//       但是对于稀疏矩阵的存取、计算等比较耗时和浪费空间
//============================================================================
#include <iostream>
#include "../Common/DataType.hpp"

#ifndef __SPARSE_MATRIX__
#define __SPARSE_MATRIX__

namespace sparse_matrix
{
	using namespace std;

	const int defaultSize = 10;

	template<typename T>
	class SparseMatrix
	{
		public:
			SparseMatrix(int capacity);
			~SparseMatrix();

		public:
			void matrix (const T** mt, int row, int column);

			SparseMatrix<T> transpose();
			SparseMatrix<T> add (SparseMatrix<T>& other);

			void print();

		private:
			int rows;
			int columns;

			int mIterms;
			int mCapacity;

			Tuple<T>* matrixs;
	};
}

#endif
