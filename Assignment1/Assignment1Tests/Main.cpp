#include "TestHarness.h"
#include <iostream>
#include <cstdlib>
#include "..\Point.h"

struct Pint
{
	float x;
	float y;

	constexpr float getX() const {
		return x;
	}

	constexpr float getY() const {
		return y;
	}
};
int main()
{
	// random number generator used in some tests
	srand(::time_t(NULL));

    TestResult tr;
    TestRegistry::runAllTests(tr);

	// force console screen to hold
	char ch;
	std::cin >> ch;

	//constexpr Pint myPint{ 4,5 };
	//constexpr int p = myPint.getX();

	//constexpr VG::Point myPoint{ 4,5 };

	//constexpr VG::Point myPoint{ 4,5 };
	//constexpr int i = VG::Point{ 4, 5 }.getX();

    return 0;
}
