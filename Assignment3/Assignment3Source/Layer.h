#pragma once
#include <list>
#include <string>
#include "PlacedGraphic.h"

namespace Framework
{

	class Layer
	{
		using PlacedGraphicCollection = std::list<PlacedGraphic>;
		using PlacedGraphicIterator = PlacedGraphicCollection::const_iterator;

	public:
		Layer() = delete;
		explicit Layer(std::string const& initialAlias);

		Layer(const Layer& other) = default;
		Layer(Layer&& other) = default;

		Layer& operator=(const Layer& other) = default;
		Layer& operator=(Layer&& other) = default;

		~Layer() = default;

		template<class C> void pushBack(C&& placedGraphic);
		//void pushBack(PlacedGraphic& pg);
//		void remove(const PlacedGraphic& pg);

//		PlacedGraphicIterator begin() const;
//		PlacedGraphicIterator end() const;

		PlacedGraphic const& getGraphic(size_t index); //REMOVE??

//		void setAlias(const std::string& referenceAlias); //REMOVE??
		std::string const& getAlias() const;

		friend std::ostream& operator<<(std::ostream& output, Framework::Layer& layer);

	private:
		PlacedGraphicCollection graphics;
		std::string alias;
	};

//		bool operator==(const Layer& rhs) const;
//		bool operator!=(const Layer& rhs) const;
}
