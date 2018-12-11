#include "Matrix.h"
#include "SparseMatrix.cpp"

matrix::Matrix::Matrix()
{
	sparse_matrix_a = new SparseMatrix<int>(10);
	sparse_matrix_b = new SparseMatrix<int>(10);
}

matrix::Matrix::~Matrix()
{
	delete sparse_matrix_a;
	delete sparse_matrix_b;
}

void matrix::Matrix::sparseMatrix()
{
	int a[3][3]= {
		{0, 0, 2},
		{3, 0, 1},
		{0, 4, 0}
	};
	const int* ptr_a[3] = {a[0], a[1], a[2]};

	int b[3][3]= {
		{1, 0, 2},
		{0, 0, 1},
		{2, 5, 0}
	};
	const int* ptr_b[3] = {b[0], b[1], b[2]};

	sparse_matrix_a->matrix(ptr_a, 3, 3);
	sparse_matrix_b->matrix(ptr_b, 3, 3);

	SparseMatrix<int> c = sparse_matrix_a->transpose();
	SparseMatrix<int> d = sparse_matrix_a->add(*sparse_matrix_b);
	c.print();
	d.print();
}
