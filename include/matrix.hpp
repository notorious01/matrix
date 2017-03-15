#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Matrix
{
private:
	int **matrix;
	int str, col;

public:
	Matrix();
	Matrix(int, int);
	Matrix(Matrix &matr);
	~Matrix();
	int rows();
	int columns();
	
	friend ostream& operator << (ostream&,const Matrix&);
	void writing(const char*);
	void reading(const char*);
	void random();
	Matrix operator +(const Matrix&)const;
	Matrix operator *(const Matrix&)const;
	Matrix& operator =(const Matrix &);
	bool operator==(const Matrix&)const;
	friend istream& operator >> (istream& ist, const Matrix& m);

	
};
