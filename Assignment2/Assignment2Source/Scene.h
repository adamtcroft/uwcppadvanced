#pragma once

#include <string>
#include <list>

#include "Layer.h"

namespace Canvas
{
	using LayerCollection = std::list<Layer>;
	using LayerIterator = LayerCollection::iterator;

	class Scene
	{
	public:
		Scene() = default;
		Scene(const Scene& other) = default;
		Scene(Scene&& other) = default;
		Scene& operator=(const Scene& other) = default;
		Scene& operator=(Scene&& other) = default;
		~Scene() = default;

		//insert, remove, iteration support
		//setter/getter for width/height
	private:
		LayerCollection layers;
		int width, height;
	};
}