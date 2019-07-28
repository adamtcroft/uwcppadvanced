#pragma once
#include <list>
#include <string>
#include "PlacedGraphic.h"

namespace Framework
{
	using PlacedGraphicCollection = std::list<PlacedGraphic>;
	using PlacedGraphicIterator = PlacedGraphicCollection::iterator;

	class Layer
	{
	public:
		Layer() = delete;
		Layer(std::string&& initialAlias);

		Layer(const Layer& other) = default;
		Layer(Layer&& other) = default;

		Layer& operator=(const Layer& other) = default;
		Layer& operator=(Layer&& other) = default;

		~Layer() = default;

		void pushBack(PlacedGraphic& pg);
		void remove(PlacedGraphic& pg);

		PlacedGraphic const& getGraphic(const int& index);

		void setAlias(const std::string& referenceAlias);
		std::string const& getAlias() const;

		friend bool operator==(const Layer& lhs, const Layer& rhs);
		friend bool operator!=(const Layer& lhs, const Layer& rhs);
		friend std::ostream& operator<<(std::ostream& output, Framework::Layer& layer);

		//insert, remove, iteration

	private:
		PlacedGraphicCollection graphics;
		std::string alias;
	};
}
