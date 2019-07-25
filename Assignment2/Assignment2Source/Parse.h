#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

namespace Parse
{
	static void trim(std::string& sourceString, std::string const& trimmables);
	static void eat(std::istream& sourceStream, std::string const& edibles);
}

static void Parse::trim(std::string& sourceString, std::string const& trimmables=" \n\t")
{
	size_t startTrim = sourceString.find_first_not_of(trimmables);

	if (startTrim > sourceString.length())
	{
		sourceString = sourceString.erase();
		return;
	}

	if (startTrim != 0)
		sourceString = sourceString.substr(startTrim);

	size_t endTrim = sourceString.find_last_not_of(trimmables)+1;
	if (endTrim != 0)
		sourceString = sourceString.substr(0, endTrim);
}

static void Parse::eat(std::istream& sourceStream, std::string const& edibles=" \n\t")
{
	char c = sourceStream.peek();

	if (edibles.find(c) != std::string::npos)
	{
		sourceStream.get();
		eat(sourceStream, edibles);
		return;
	}
	else
		return;
}
