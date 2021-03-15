#include <iostream>

#include <cmath>

using namespace std;

class Matrix {
private:
	int rows, columns;
	int* mat;
public:

	Matrix(Matrix& obj) {
		this->rows = obj.rows;
		this->columns = obj.columns;

		this->mat = new int[rows * columns];
		int i = 0, j = 0;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < columns; j++) {
				this->mat[i * columns + j] = obj.GetById(i, j);
			}
		}
	}

	Matrix(int rows, int columns, int* c) {
		this->rows = rows;
		this->columns = columns;
		this->mat = new int[rows * columns];
		int i = 0, j = 0;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < columns; j++) {
				this->mat[i * columns + j] = c[i * columns + j];
			}
		}
	}

	~Matrix() { delete[] mat; }

	int GetById(int i, int j);
	void MultiplyOnNum(int mult);
	void Reset(int a, int b, int* c);
	void Print(void);
	int Rows() { return rows; }
	int Columns() { return columns; }
	int Add(Matrix matrix2);
	int Sub(Matrix matrix2);
	int Multiply(Matrix matrix2);
};

void Matrix::Reset(int a, int b, int* c) {
	rows = a;
	columns = b;
	int i = 0, j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			mat[i * columns + j] = c[i * columns + j];
		}
	}
}

int Matrix::Multiply(Matrix matrix2) {
	int* arr;
	int a, b = 0;
	int rows2 = matrix2.Rows();
	int columns2 = matrix2.Columns();
	arr = new int[rows * columns2];
	if (columns != rows2) {
		return 0;
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns2; j++) {
				for (a = 0; a < columns; a++) {
					b += mat[i * columns + a] * matrix2.GetById(a, j);
				}
				arr[i * rows + j] = b;
				b = 0;
			}
		}
		Reset(rows, columns2, arr);
	}
	return 1;
}

int Matrix::Add(Matrix matrix2) {
	if (matrix2.Columns() == columns and matrix2.Rows() == rows) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				mat[i * columns + j] += matrix2.GetById(i, j);
			}
		}
		return 1;
	}
	return 0;
}

int Matrix::Sub(Matrix matrix2) {
	if (matrix2.Columns() == columns and matrix2.Rows() == rows) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				mat[i * columns + j] -= matrix2.GetById(i, j);
			}
		}
		return 1;
	}
	return 0;
}

void Matrix::Print(void) {
	printf("\n");
	for (int i = 0; i < rows; i++) {
		printf("  ");
		for (int j = 0; j < columns; j++) {
			printf("|%4d", mat[i * columns + j]);
		}
		printf("|\n");

	}
}

int Matrix::GetById(int i, int j) {
	if (i < rows and j < columns) {
		return mat[i * columns + j];
	}
}

void Matrix::MultiplyOnNum(int mult) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			mat[i * columns + j] *= mult;
		}
	}
}


int main()

{
	int arr[] = { 1,2,3,4,5,6 };
	int arr2[] = { -7,-8,-9,-1,-2,-3 };
	int arr3[] = { 1,2,2,3,4,5 };


	Matrix matrix1(2, 3, arr);
	Matrix matrix2(2, 3, arr2);
	Matrix matrix3(3, 2, arr3);

	printf("  Matrix1: ");
	matrix1.Print();
	int x = matrix1.GetById(1, 2);
	printf("\n  Num that was gotten by function GetById(1, 2): %d\n", x);
	matrix1.MultiplyOnNum(x);
	printf("  First Matrix multiplied on previous num:");
	matrix1.Print();
	printf("  Matrix2: ");
	matrix2.Print();
	matrix1.Add(matrix2);
	printf("  Matrix1+Matrix2: ");
	matrix1.Print();
	matrix1.Sub(matrix2);
	printf("  Matrix1-Matrix2: ");
	matrix1.Print();
	printf("  Matrix3: ");
	matrix3.Print();
	matrix1.Multiply(matrix3);
	printf("  Matrix1*Matrix3: ");
	matrix1.Print();

	Matrix matrix4(matrix3);
	printf("  Matrix4: ");
	matrix4.Print();
	return 0;
}