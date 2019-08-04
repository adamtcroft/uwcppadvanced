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
		Scene& operator=(Scene&& other);

		~Scene() = default;

		void pushBack(Layer layer);
		void remove(const Layer&& layer);

		LayerIterator begin();
		LayerIterator end();

		void setWidth(int w);
		void setHeight(int h);

		int const& getWidth() const;
		int const& getHeight() const;

		friend bool operator==(const Scene& lhs, const Scene& rhs);
		friend bool operator!=(const Scene& lhs, const Scene& rhs);
		friend std::ostream& operator<<(std::ostream& output, Framework::Scene& pg);

	private:
		LayerCollection layers;
		int width, height;
	};

}