#include "matrix.hpp"

int Matrix::cols_() const
{
	return cols;
}

int Matrix::rows_() const
{
	return rows;
}

Matrix::Matrix(): cols(0), rows(0), Arr(nullptr)
{}

Matrix::Matrix(int _cols, int _rows)
{
	cols = _cols;
	rows = _rows;
	Arr = new int*[rows];
	for (int i = 0; i < rows; ++i){
		Arr[i] = new int[cols];
		for (int j = 0; j < cols; ++j){
			Arr[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& result)
{
	cols = result.cols;
	rows = result.rows;
	Arr = new int*[rows];
	for (int i = 0; i < rows; ++i){
		Arr[i] = new int[cols];
		for (int j = 0; j < cols; ++j){
			Arr[i][j] = result.Arr[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; ++i){
		delete[]Arr[i];
	}
	delete[]Arr;
}

istream& operator >> (istream& infile, Matrix& result)
{
		for (int i = 0; i < result.rows; i++)
			for (int j = 0; j < result.cols; j++)
				infile >> result.Arr[i][j];
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
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				infile >> Arr[i][j];
			}
		}
	}
	infile.close();
}

ostream& operator << (ostream& outfile, const Matrix& result)
{
	for (int i = 0; i < result.rows; i++){
		for (int j = 0; j < result.cols; j++){
			outfile << result.Arr[i][j] << " ";
		}
	}
		outfile << endl;
		return outfile;
}

bool Matrix::operator == (const Matrix& m2) const
{
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (Arr[i][j] == m2.Arr[i][j]){
				return true;
			}
			return false;
		}
	}
}

Matrix Matrix::operator + (const Matrix& m2) const
{
	if ((cols != m2.cols) || (rows != m2.rows)) {
		cout << "Error!";
	}
	else {
		Matrix result(cols, rows);
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j){
				result.Arr[i][j] = Arr[i][j] + m2.Arr[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator * (const Matrix& m2) const
{
	if (m2.rows != cols){
		cout << "Error!";
	}
	else {
		Matrix result(rows, m2.cols);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < m2.cols; j++){
				for (int k = 0; k < cols; k++){
					result.Arr[i][j] += Arr[i][k] * m2.Arr[k][j];
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
	for (int i = 0; i < rows; i++){
		delete[]Arr[i];
	}
	delete[]Arr;
	Arr = new int*[result.rows];
	for (int i = 0; i < result.rows; i++)
	{
		Arr[i] = new int[result.cols];
		for (int j = 0; j < result.cols; j++)
			Arr[i][j] = result.Arr[i][j];
	}
	rows = result.rows;
	cols = result.cols;
	return *this;
}
