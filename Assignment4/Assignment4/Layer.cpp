#include "Layer.h"

Framework::Layer::Layer(std::string const& initialAlias) :
	alias(initialAlias)
{
}

void Framework::Layer::remove(const PlacedGraphic& pg)
{
	graphics.remove(pg);
}

Framework::Layer::PlacedGraphicIterator Framework::Layer::begin() const
{
	return graphics.begin();
}

Framework::Layer::PlacedGraphicIterator Framework::Layer::end() const
{
	return graphics.end();
}

Framework::PlacedGraphic const& Framework::Layer::getGraphic(const int& index)
{
	if (index > graphics.size())
		throw std::out_of_range("The graphic requested does not exist.");
	else
	{
		PlacedGraphicIterator iterator = graphics.begin();
		std::advance(iterator, index);
		return *iterator;
	}

}

void Framework::Layer::setAlias(const std::string& referenceAlias)
{
	alias = referenceAlias;
}

std::string const& Framework::Layer::getAlias() const
{
	return alias;
}

bool Framework::Layer::operator==(const Framework::Layer& rhs) const
{
	return (graphics == rhs.graphics) && (alias == rhs.alias);
}

bool Framework::Layer::operator!=(const Framework::Layer& rhs) const
{
	return !operator==(rhs);
}
