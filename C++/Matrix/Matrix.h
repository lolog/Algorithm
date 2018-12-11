#include "SparseMatrix.h"

#ifndef __MATRIX__
#define __MATRIX__

namespace matrix
{
	using namespace std;
	using sparse_matrix::SparseMatrix;

	class Matrix
	{
		public:
			Matrix();
			~Matrix();

		public:
			void sparseMatrix();

		private:
			SparseMatrix<int>* sparse_matrix_a;
			SparseMatrix<int>* sparse_matrix_b;
	};
}

#endif
