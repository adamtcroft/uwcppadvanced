#pragma once
#include <list>
#include "PlacedGraphic.h"

namespace Framework
{

	using PlacedGraphicCollection = std::list<PlacedGraphic>;

	class Layer
	{
	public:
		Layer();
		~Layer();
	};
}