#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Matrix
{
private:
	int stolb;
	int stroka;
	int **matrix;
public:
	Matrix();

	Matrix(int _stolb, int _stroka);

	Matrix(const Matrix& result);

	~Matrix();

	int stolb_() const;

	int stroka_() const;

	void search(string filename);

	bool operator == (const Matrix& a) const;

	Matrix operator + (const Matrix& a) const;

	Matrix operator * (const Matrix& a) const;

	Matrix& operator = (const Matrix& res);

	friend ostream& operator << (ostream& outfile, const Matrix& result);

	friend istream& operator >> (istream& infile, const Matrix& result);
};
