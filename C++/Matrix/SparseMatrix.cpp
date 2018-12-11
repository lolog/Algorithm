#include <malloc.h>
#include "SparseMatrix.h"

template<typename T>
sparse_matrix::SparseMatrix<T>::SparseMatrix(int capacity)
{
	rows      = columns      = mIterms = 0;
	mCapacity = capacity;
	matrixs   = (Tuple<T>*) malloc(sizeof(Tuple<T>) * mCapacity);
}

template<typename T>
sparse_matrix::SparseMatrix<T>::~SparseMatrix()
{
	free(matrixs);
	matrixs = NULL;
}

template<typename T>
void sparse_matrix::SparseMatrix<T>::matrix (const T** mt, int row, int column)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			T t = mt[i][j];
			if(0 != t)
			{
				matrixs[mIterms] = Tuple<T>(i, j, t);
				mIterms++;
			}
		}
	}

	rows    = row;
	columns = column;
}

template<typename T>
sparse_matrix::SparseMatrix<T> sparse_matrix::SparseMatrix<T>::transpose()
{
	int rowSize[columns]  = {0};  // row size
	int rowStart[columns] = {0};  // row started position for non-zero element

	SparseMatrix<T> trix(mCapacity);
	trix.columns = rows;
	trix.rows    = columns;
	trix.mIterms = mIterms;

	if(mIterms > 0)
	{
		// row size after transpose
		for(int i=0; i<mIterms; i++)
		{
			rowSize[matrixs[i].column]++;
		}
		// row start after transpose
		for(int i=1; i<columns; i++)
		{
			rowStart[i] = rowSize[i-1] + rowStart[i-1];
		}
		for(int i=0; i<mIterms; i++)
		{
			int col   = matrixs[i].column;
			int index = rowStart[col];

			trix.matrixs[index] = Tuple<T>(matrixs[i].column, matrixs[i].row, matrixs[i].value);

			rowStart[col]++;
		}
	}

	return trix;
}

template<typename T>
sparse_matrix::SparseMatrix<T> sparse_matrix::SparseMatrix<T>::add (SparseMatrix<T>& other)
{
	SparseMatrix<T> result(mIterms + other.mIterms);

	if(rows != other.rows || columns != other.columns)
	{
		return result;
	}

	result.rows    = 3;
	result.columns = 3;

	int i = 0,
	    j = 0;

	while(i < mIterms && j < other.mIterms)
	{
		Tuple<T> a = matrixs[i];
		Tuple<T> b = other.matrixs[j];

		int index_a = a.row * columns + a.column;
		int index_b = b.row * columns + b.column;

		int m_iterms = result.mIterms;
		// add
		if(index_a == index_b)
		{
			result.matrixs[m_iterms] = Tuple<T>(a.row, a.column, a.value + b.value);
			i++;
			j++;
		}
		// insert a
		else if(index_a < index_b)
		{
			result.matrixs[m_iterms] = Tuple<T>(a.row, a.column, a.value);
			i++;
		}
		else
		{
			result.matrixs[m_iterms] = Tuple<T>(b.row, b.column, b.value);
			j++;
		}
		result.mIterms = ++m_iterms;

	}

	for(; i<mIterms; i++)
	{
		Tuple<T> a   = matrixs[i];
		int m_iterms = result.mIterms;

		result.matrixs[m_iterms] = Tuple<T>(a.row, a.column, a.value);
		result.mIterms           = ++m_iterms;
	}

	for(; j<other.mIterms; j++)
	{
		Tuple<T> b   = other.matrixs[j];
		int m_iterms = result.mIterms;

		result.matrixs[m_iterms] = Tuple<T>(b.row, b.column, b.value);
		result.mIterms           = ++m_iterms;
	}

	return result;
}

template<typename T>
void sparse_matrix::SparseMatrix<T>::print()
{
	cout << "SparseMatrix: " << endl;
	cout << "     row = " << rows << ", column = " << columns << endl;

	int index = 0;
	for(int i=0; i<rows; i++)
	{
		cout << "     |";
		if(matrixs[index].row == i && index < mIterms)
		{
			for(int j=0; j<columns; j++)
			{
				if(index < mIterms && matrixs[index].column == j && matrixs[index].row == i)
				{
					cout << " " << matrixs[index].value;
					index++;
				}
				else {
					cout << " 0";
				}
			}
		}
		else
		{
			for(int j=0; j<columns; j++)
			{
				cout << " 0";
			}
		}
		cout << " |" << endl;
	}
}
