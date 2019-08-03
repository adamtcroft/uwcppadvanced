#include "Layer.h"
#include "PlacedGraphic.h"

Framework::Layer::Layer(std::string initialAlias)
	:alias(initialAlias)
{

}

void Framework::Layer::pushBack(PlacedGraphic& pg)
{
	graphics.push_back(pg);
}

void Framework::Layer::remove(PlacedGraphic& pg)
{
	auto result = std::find(graphics.begin(), graphics.end(), pg);

	if (result == graphics.end())
		throw std::out_of_range("The graphic provided does not exist.");
	else
		graphics.erase(result);
}

Framework::PlacedGraphicCollection::iterator Framework::Layer::begin()
{
	return graphics.begin();
}

Framework::PlacedGraphicCollection::iterator Framework::Layer::end()
{
	return graphics.end();
}

Framework::PlacedGraphic const& Framework::Layer::getGraphic(const int& index) 
{
	PlacedGraphicIterator iterator = graphics.begin();
	std::advance(iterator, index);
	return *iterator;
}

void Framework::Layer::setAlias(const std::string& referenceAlias)
{
	alias = referenceAlias;
}

 std::string const& Framework::Layer::getAlias() const
{
	return alias;
}

bool Framework::operator==(const Framework::Layer& lhs, const Framework::Layer& rhs)
{
	return lhs.graphics == rhs.graphics && lhs.alias == rhs.alias;
}

bool Framework::operator!=(const Framework::Layer& lhs, const Framework::Layer& rhs)
{
	return !(lhs == rhs);
}

std::ostream& Framework::operator<<(std::ostream& output, Framework::Layer& layer)
{
	output << layer.alias;
	output.flush();

	return output;
}
