#pragma once

#include <string>
#include <list>

#include "Layer.h"

namespace Framework
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

		void setWidth();
		void setHeight();

		int getWidth();
		int getHeight();

	private:
		LayerCollection layers;
		int width, height;
	};
}