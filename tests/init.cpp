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
