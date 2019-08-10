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
		Scene() = delete;
		Scene(int initialWidth, int initialHeight);

		Scene(const Scene& other) = default;
		Scene(Scene&& other) = default;

		Scene& operator=(const Scene& other) = default;
		Scene& operator=(Scene&& other) = default;

		~Scene() = default;

		template <class L> void pushBack(L&& layer)
		{
			layers.push_back(std::forward<L>(layer));
		}
		void remove(const Layer&& layer);

		LayerIterator begin();
		LayerIterator end();

		void setWidth(size_t w);
		void setHeight(size_t h);

		int const& getWidth() const;
		int const& getHeight() const;

		bool operator==(const Scene& rhs) const;
		bool operator!=(const Scene& rhs) const;
		//		friend std::ostream& operator<<(std::ostream& output, Framework::Scene& pg);
		//
	private:
		LayerCollection layers;
		size_t width, height;
	};

}