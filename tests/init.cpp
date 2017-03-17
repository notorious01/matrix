#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matr;
	REQUIRE(matr.rows() == 0);
	REQUIRE(matr.columns() == 0);
}

SCENARIO("with params", "[init]")
{
	int init = 10;
	Matrix temp(init, init);
	REQUIRE(temp.rows() == 10);
	REQUIRE(temp.columns() == 10);
}

SCENARIO("copy", "[init]")
{
	int init = 10;
	Matrix temp(init, init);
	Matrix copy(temp);
	REQUIRE(copy.rows() == 10);
	REQUIRE(copy.columns() == 10);
}


SCENARIO("addition", "[init]")
{
	int init = 5;
	Matrix first(init, init);
	Matrix second(first), third(first);
	std::ifstream("A.txt") >> first;
	std::ifstream("B.txt") >> second;
	std::ifstream("A+B.txt") >> third;
	REQUIRE(first + second == third);
}


SCENARIO("reading", "[init]")
{
	int init = 5;
	Matrix first(init, init);
	Matrix second(first);
	std::ifstream("A.txt") >> first;
	second.reading("A.txt");
	REQUIRE(second == first);
}



SCENARIO("multiplication", "[init]")
{
	int init = 5;
	Matrix first(init, init);
	Matrix second(first), third(first);
	std::ifstream("A.txt") >> first;
	std::ifstream("B.txt") >> second;
	std::ifstream("A*B.txt") >> third;
	REQUIRE(first * second == third);
}

SCENARIO("comparing", "[init]") {
	Matrix first(5,5);
	Matrix second(first);
	bool same;
	//Матрица из файле "A.txt" равна матрице из файла "C.txt"
	std::ifstream("A.txt") >> first;
	std::ifstream("C.txt") >> second;
	if (second == first)
		same = true;
	REQUIRE(same == true);
}

SCENARIO("writing", "[init]")
{
	int init = 5;
	Matrix first(init, init);
	Matrix second(first);
	std::ifstream("A.txt") >> first;
	first.writing("D.txt");
	//"D.txt" is empty
	second.reading("D.txt");
	REQUIRE(second == first);
}


SCENARIO("assignment", "[init]") {
	int init = 5;
	Matrix first(init, init);
	Matrix second;
	std::ifstream("A.txt") >> first;
	second = first;
	REQUIRE(second == first);
}

SCENARIO("self assignment") {
	Matrix a{ 3, 3 };
	a = a;
	REQUIRE( a == a );
	std::cout << a;
}

