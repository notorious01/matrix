#include "matrix.hpp"

Matrix::Matrix() : str(0), col(0), matrix{nullptr}
{
	
}

//--------------------------------------------------------------------

Matrix::Matrix(int m, int n) : str(m), col(n)
{
	matrix = new int *[m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n]();
}

//--------------------------------------------------------------------

Matrix::Matrix(Matrix &matr)
{
	matrix = new int*[matr.str];
	for (int i = 0; i < matr.str; i++)
	{
		matrix[i] = new int[matr.col];
		for (int j = 0; j < matr.col; j++)
			matrix[i][j] = matr.matrix[i][j];
	}
	str = matr.str;
	col = matr.col;
}

//--------------------------------------------------------------------

Matrix::~Matrix()
{
	for (int i = 0; i < str; i++) 
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

//--------------------------------------------------------------------


int Matrix::rows()
{
	return str;
}

int Matrix::columns()
{
	return col;
}

void Matrix::random()
{
	srand(time(NULL));
	for (int i = 0; i < str; i++)
	for (int j = 0; j < col; j++)
		matrix[i][j] = rand() % 5;
}

//--------------------------------------------------------------------
ostream& operator << (ostream& ost,const Matrix& m)
{
	for (int i = 0; i < m.str; i++)
	{
		for (int j = 0; j < m.col; j++)
			ost << setw(3) << m.matrix[i][j];
		ost << "\n";
	}
	ost << "\n\n\n";
	return ost;
}

//--------------------------------------------------------------------

void Matrix::writing(const char* filename)
{
	ofstream fout(filename);
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
			fout << setw(5) << matrix[i][j];
		fout << endl;
	}
}

//--------------------------------------------------------------------

void Matrix::reading(const char* filename)
{
	ifstream fin(filename);
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
			fin >> matrix[i][j];
	}
}

//--------------------------------------------------------------------

Matrix Matrix::operator +(const Matrix &sum)const
{
	if (str != sum.str || col != sum.col)
	{
		cout << "Addition is impossible" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		Matrix temp(str, col);
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < col; j++)
				temp.matrix[i][j] = matrix[i][j] + sum.matrix[i][j];
		}
		return temp;
	}
}

//--------------------------------------------------------------------

Matrix& Matrix::operator =(const Matrix &matr)
{	
	for (int i = 0; i < str; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = new int*[matr.str];
	for (int i = 0; i < matr.str; i++)
	{
		matrix[i] = new int[matr.col];
		for (int j = 0; j < matr.col; j++)
		{
			matrix[i][j] = matr.matrix[i][j];
		}
	}
	str = matr.str;
	col = matr.col;
	return *this;
}

//--------------------------------------------------------------------

Matrix Matrix::operator *(const Matrix &mult)const
{	
	if (str != mult.col)
	{	
		cout << "Multiplication is impossible" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		Matrix temp(str, col);
		for (int i = 0; i < str; i++)
		for (int j = 0; j < col; j++)
		{
			temp.matrix[i][j] = 0;
			for (int k = 0; k < str; k++)
				temp.matrix[i][j] += matrix[k][j] * mult.matrix[i][k];
		};
		return temp;
	}
}

//--------------------------------------------------------------------

bool Matrix::operator==(const Matrix& obj)const
{
	bool same = true;
	if (str != obj.str || col != obj.col)
	{
		cout << "Objects are not comparable" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < str; i++)
			for (int j = 0; j < col; j++)
				if (matrix[i][j] != obj.matrix[i][j])
					same = false;
	}
	return same;
}

//--------------------------------------------------------------------

istream& operator >> (istream& ist, const Matrix& m)
{
	for (int i = 0; i < m.str; i++)
	for (int j = 0; j < m.col; j++)
		ist >> m.matrix[i][j];
	return ist;
}
