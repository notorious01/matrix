#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("default constructor") {
	Matrix matrix1;
	REQUIRE(matrix1.stroka_() == 0);
	REQUIRE(matrix1.stolb_() == 0);
}

SCENARIO("constructor with params") {
	Matrix matrix1(3, 3);
	REQUIRE(matrix1.stroka_() == 3);
	REQUIRE(matrix1.stolb_() == 3);
}

SCENARIO("copy constructor") {
	Matrix matrix1 (3, 3);	
	Matrix copy(matrix1);	
	REQUIRE(copy.stroka_() == 3);
	REQUIRE(copy.stolb_() == 3);
}


SCENARIO("operator +") {
	Matrix matrix1 (3, 3);
	Matrix matrix2 (3, 3);
	Matrix matrix3 (3, 3);	
	std::ifstream("matrix1.txt") >> matrix1;
	std::ifstream("matrix2.txt") >> matrix2;
	std::ifstream("matrix1+matrix2.txt") >> matrix3;
	REQUIRE(matrix1 + matrix2 == matrix3);
}

SCENARIO("operator *") {
	Matrix matrix1 (3, 3);
	Matrix matrix2 (3, 3);
	Matrix matrix3 (3, 3);	
	std::ifstream("matrix1.txt") >> matrix1;
	std::ifstream("matrix2.txt") >> matrix2;
	std::ifstream("matrix1 x matrix2.txt") >> matrix3;
	REQUIRE(matrix1 * matrix2 == matrix3);
}

SCENARIO("operator =") {
	Matrix matrix1(3, 3);
	Matrix matrix2 = matrix1;
	REQUIRE(matrix1 == matrix2);
}

SCENARIO("operator ==") {
	Matrix matrix1(3, 3);
	Matrix matrix2(3, 3);
	REQUIRE(matrix1 == matrix2);
}

SCENARIO("scan") {
	Matrix matrix1(3, 3);
	Matrix matrix2(3, 3);
	std::ifstream("matrix1.txt") >> matrix1;
	matrix2.scan("matrix1.txt");
	REQUIRE(matrix1 == matrix2);
}
