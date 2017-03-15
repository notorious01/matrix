#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init", "[init]") {
	Matrix matr;
	REQUIRE(matr.rows() == 0);
	REQUIRE(matr.columns() == 0);
}
