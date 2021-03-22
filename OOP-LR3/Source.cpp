#include <iostream>
#include<time.h>

#include <cmath>

using namespace std;
const int n = 10;

class Matrix {
private:
	int rows, columns;
	int* mat;
public:
	Matrix() { rows = 0; columns = 0; int* mat; }
	Matrix(const Matrix& obj) {
		this->rows = obj.rows;
		this->columns = obj.columns;

		this->mat = new int[rows * columns];
		int i = 0, j = 0;
		for (i = 0; i < rows; i++) {
			for (j = 0; j < columns; j++) {
				this->mat[i * columns + j] = obj.mat[i*columns+j];
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

	void operator =(const Matrix& matrix2){
		rows = matrix2.rows;
		columns = matrix2.columns;
		mat = new int[rows*columns];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				mat[i * columns + j] = matrix2.mat[i*columns+j];
			}
		}
	}


	Matrix operator *(const Matrix& matrix2) {
		int* arr;
		int a, b = 0;
		int rows2 = matrix2.rows;
		int columns2 = matrix2.columns;
		arr = new int[rows * columns2];
		if (columns != rows2) {
			printf_s("\nError in multiplying Matrix");
			exit(1);
		}
		else {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns2; j++) {
					for (a = 0; a < columns; a++) {
						b += mat[i * columns + a] * matrix2.mat[a * columns2 + j];
					}
					arr[i * rows + j] = b;
					b = 0;
				}
			}
			return Matrix(rows, columns2, arr);
		}
	}
	bool operator <=(const Matrix& obj) {
		if (rows * columns <= obj.columns * obj.rows) {
			return true;
		}
		else {
			return false;
		}
	}
	void EnterMatrix();
	int GetById(int i, int j);
	void MultiplyOnNum(int mult);
	void Reset(int a, int b, int* c);
	void Reset(Matrix *obj);
	void Print(void);
	int Rows() { return rows; }
	int Columns() { return columns; }
	int Add(Matrix matrix2);
	int Sub(Matrix matrix2);
	int Multiply(Matrix matrix2);
	int* Mat();
};

static Matrix MatrixArr[n];

void Matrix::EnterMatrix() {
	printf_s("Enter rows: ");
	scanf_s("%d", &rows);
	printf_s("Enter columns: ");
	scanf_s("%d", &columns);
	mat = new int[rows * columns];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			scanf_s("%d", &mat[i*columns + j]);
		}
		printf_s("\n");
	}
}

int* Matrix::Mat() {
	return mat;
}

void Matrix::Reset(Matrix *obj) {
	rows = obj->Rows();
	columns = obj->Columns();
	int i = 0, j = 0;
	delete[] mat;
	mat = new int[rows * columns];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			mat[i * columns + j] = obj->GetById(i,j);
		}
	}
}


void Matrix::Reset(int a, int b, int* c) {
	rows = a;
	columns = b;
	int i = 0, j = 0;
	delete[] mat;
	mat = new int[rows * columns];
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
	if (matrix2.Columns() == columns || matrix2.Rows() == rows) {
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
	if (matrix2.Columns() == columns || matrix2.Rows() == rows) {
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
	if (i < rows || j < columns) {
		return mat[i * columns + j];
	}
	else {
		printf_s("GetById");
		exit(1);
		return 1;
	}
}

void Matrix::MultiplyOnNum(int mult) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			mat[i * columns + j] *= mult;
		}
	}
}

void InsertionSort(Matrix* array, int size) {
	int j;
	Matrix key;
	for (int i = 1; i < size; i++) {
		key.Reset(&array[i]);
		j = i;
		while (j > 0 && key <= array[j - 1]) {
			array[j].Reset(&array[j - 1]);
			j--;
		}
		array[j].Reset(&key);
	}
}

void CreateArray() {
	int rows = 0, columns = 0;
	for (int a = 0; a < n; a++) {
		rows = (rand() % 3) + 1;
		columns = (rand() % 3) + 1;
		int *arr;
		arr = new int[rows * columns];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				arr[i * columns + j] = rand() % 10;
			}
		}
		MatrixArr[a].Reset(rows, columns, arr);
	}
}

void PrintMatrix(){
	for (int i = 0; i < n; i++) {
		printf("\n  Matrix %d:", i + 1);
		MatrixArr[i].Print();
	}
}

int main() {
	CreateArray();
	printf_s("\nGenerated Matrices:\n");
	PrintMatrix();
	Matrix *a = MatrixArr;
	InsertionSort(a, n);
	printf_s("\nSorted Matrices:\n");
	PrintMatrix();
	
	//checking is it possible to multiply two last matrixes
	if (MatrixArr[n - 2].Columns() == MatrixArr[n-1].Rows()) {
		Matrix matrix;
		printf_s("\nSecond last * last: \n");
		matrix = MatrixArr[n -2] * MatrixArr[n-1];
		matrix.Print();
	}
	return 0;
}