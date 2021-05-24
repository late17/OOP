#include <iostream>
#include<time.h>

#include <cmath>


class Matrix {
private:
	static Matrix* instance;
	static int count;
	int rows, columns;
	int* mat;
	Matrix() { rows = 0; columns = 0; int* mat=NULL; }
public:



	static Matrix& getInstance()

	{

		if (count == 0)

		{

			instance = new Matrix();

		}

		return *instance;

	};
	~Matrix() { delete[] mat; }
	void EnterMatrix();
	int GetById(int i, int j);
	void MultiplyOnNum(int mult);
	void Reset(int a, int b, int* c);
	void Print(void);
	int Rows() { return rows; }
	int Columns() { return columns; }
	int* Mat();
};


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
			scanf_s("%d", &mat[i * columns + j]);
		}
		printf_s("\n");
	}
}

int* Matrix::Mat() {
	return mat;
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




int Matrix::count = 0;

Matrix* Matrix::instance = 0;

int main() {
	Matrix& Inctance = Matrix::getInstance();
	Inctance.EnterMatrix();
	Inctance.Print();
	return 0;
}