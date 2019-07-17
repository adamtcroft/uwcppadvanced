#pragma once

#include <string>

namespace Tools
{
	class ParseTool
	{
	public:
		ParseTool();
		~ParseTool();

		void trim(std::string& sourceString, std::string const& trimmables);
		void eat(std::istream& sourceStream, std::string const& edibles);
	};
}
