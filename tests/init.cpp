#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("default constructor") {
	Matrix matrix;
	REQUIRE(matrix.stroka_() == 0);
	REQUIRE(matrix.stolb_() == 0);
}

SCENARIO("constructor with params") {
	Matrix matrix(3, 3);
	REQUIRE(matrix.stroka_() == 3);
	REQUIRE(matrix.stolb_() == 3);
}

SCENARIO("copy constructor") {
	Matrix matrix (3, 3);	
	Matrix copy(matrix);	
	REQUIRE(copy.stroka_() == 3);
	REQUIRE(copy.stolb_() == 3);
}


SCENARIO("operator +") {
	Matrix matrix1 (3, 3);
	Matrix matrix2 (3, 3);
	Matrix matrix3 (3, 3);	
	std::ifstream("m1.txt") >> matrix1;
	std::ifstream("m2.txt") >> matrix2;
	std::ifstream("m1+m2.txt") >> matrix3;
	REQUIRE(matrix1 + matrix2 == matrix3);
}

SCENARIO("operator *") {
	Matrix matrix1 (3, 3);
	Matrix matrix2 (3, 3);
	Matrix matrix3 (3, 3);	
	std::ifstream("m1.txt") >> matrix1;
	std::ifstream("m2.txt") >> matrix2;
	std::ifstream("m1 x m2.txt") >> matrix3;
	REQUIRE(matrix1 * matrix2 == m3);
}

SCENARIO("operator =") {
	Matrix m1(3, 3);
	Matrix m2 = m1;
	REQUIRE(m1 == m2);
}

SCENARIO("operator ==") {
	Matrix m1(3, 3);
	Matrix m2(3, 3);
	REQUIRE(m1 == m2);
}

SCENARIO("scan") {
	Matrix m1(3, 3);
	Matrix m2(3, 3);
	std::ifstream("m1.txt") >> m1;
	m2.scan("m1.txt");
	REQUIRE(m1 == m2);
}
