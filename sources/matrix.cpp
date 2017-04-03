#include "matrix.hpp"

int Matrix::stolb_() const
{
	return stolb;
}

int Matrix::stroka_() const
{
	return stroka;
}

Matrix::Matrix(): stolb(0), stroka(0), matrix(nullptr)
{}

Matrix::Matrix(int _stolb, int _stroka)
{
	stolb = _stolb;
	stroka = _stroka;
	matrix = new int*[stroka];
	for (int i = 0; i < stroka; ++i){
		matrix[i] = new int[stolb];
		for (int j = 0; j < stolb; ++j){
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& result)
{
	stolb = result.stolb;
	stroka = result.stroka;
	matrix = new int*[stroka];
	for (int i = 0; i < stroka; ++i){
		matrix[i] = new int[stolb];
		for (int j = 0; j < stolb; ++j){
			matrix[i][j] = result.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < stroka; ++i){
		delete[]matrix[i];
	}
	delete[]matrix;
}

istream& operator >> (istream& infile, Matrix& result)
{
		for (int i = 0; i < result.stroka; i++)
			for (int j = 0; j < result.stolb; j++)
				infile >> result.matrix[i][j];
		return infile;
}

void Matrix::scan(string filename) const 
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
		cout << "Error! Please, try again!" << endl;
	else
	{
		for (int i = 0; i < stroka; i++){
			for (int j = 0; j < stolb; j++){
				infile >> matrix[i][j];
			}
		}
	}
	infile.close();
}

ostream& operator << (ostream& outfile, const Matrix& result)
{
	for (int i = 0; i < result.stroka; i++){
		for (int j = 0; j < result.stolb; j++){
			outfile << result.matrix[i][j] << " ";
		}
	}
		outfile << endl;
		return outfile;
}

bool Matrix::operator == (const Matrix& m2) const
{
	for (int i = 0; i < stroka; i++){
		for (int j = 0; j < stolb; j++){
			if (matrix[i][j] == m2.matrix[i][j]){
				return true;
			}
			return false;
		}
	}
}

Matrix Matrix::operator + (const Matrix& m2) const
{
	if ((stolb != m2.stolb) || (stroka != m2.stroka)) {
		cout << "Error!";
	}
	else {
		Matrix result(stolb, stroka);
		for (int i = 0; i < stroka; ++i){
			for (int j = 0; j < stolb; ++j){
				result.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator * (const Matrix& m2) const
{
	if (m2.stroka != stolb){
		cout << "Error!";
	}
	else {
		Matrix result(stroka, m2.stolb);
		for (int i = 0; i < stroka; i++){
			for (int j = 0; j < m2.stolb; j++){
				for (int k = 0; k < stolb; k++){
					result.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];
				}
			}
		}
		return result;
	}
}

Matrix& Matrix::operator = (const Matrix& result)
{
	if (&result == this){
		return *this;
	}
	for (int i = 0; i < stroka; i++){
		delete[]matrix[i];
	}
	delete[]matrix;
	matrix = new int*[result.stroka];
	for (int i = 0; i < result.stroka; i++)
	{
		matrix[i] = new int[result.stolb];
		for (int j = 0; j < result.stolb; j++)
			matrix[i][j] = result.matrix[i][j];
	}
	stroka = result.stroka;
	stolb = result.stolb;
	return *this;
}
