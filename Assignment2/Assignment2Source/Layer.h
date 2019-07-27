#pragma once
#include <list>
#include "PlacedGraphic.h"

namespace Framework
{
	using PlacedGraphicCollection = std::list<PlacedGraphic>;
	using PlacedGraphicIterator = PlacedGraphicCollection::iterator;

	class Layer
	{
	public:
		Layer() = default;
		Layer(std::string&& initialAlias);

		Layer(const Layer& other) = default;
		Layer(Layer&& other) = default;

		Layer& operator=(const Layer& other) = default;
		Layer& operator=(Layer&& other) = default;

		~Layer() = default;

		void addGraphic();
		void removeGraphic();

		void setAlias(std::string& referenceAlias);
		std::string const& getAlias() const;

		friend bool operator==(const Layer& lhs, const Layer& rhs);
		friend bool operator!=(const Layer& lhs, const Layer& rhs);

		//insert, remove, iteration

	private:
		PlacedGraphicCollection graphics;
		std::string alias;
	};
}
