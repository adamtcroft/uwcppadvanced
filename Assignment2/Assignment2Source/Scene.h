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
		Scene(int initialWidth, int initialHeight);

		Scene(const Scene& other) = default;
		Scene(Scene&& other) = default;

		Scene& operator=(const Scene& other) = default;
		Scene& operator=(Scene&& other) = default;

		~Scene() = default;

		//insert, remove, iteration support
		
		void pushBack(Layer&& layer);
		void removeLayer();

		LayerIterator begin();
		LayerIterator end();

		void setWidth();
		void setHeight();

		int const& getWidth() const;
		int const& getHeight() const;

	private:
		LayerCollection layers;
		int width, height;
	};

}