#pragma once
#include <string>

namespace Canvas
{
	using PlacedGraphicCollection = std::list;

	class Scene
	{
	public:
		//ctors
		//dtor
		//insert, remove, iteration support
		//setter/getter for alias
	private:
		PlacedGraphicCollection graphics;
		std::string alias;
	};
}