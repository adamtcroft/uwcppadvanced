// Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestHarness.h"


int main()
{
	TestResult tr;
	TestRegistry::runAllTests(tr);
    return 0;
}

