#include "Scene.h"

Framework::Scene::Scene(int initialWidth, int initialHeight)
	:width(initialWidth), height(initialHeight)
{
}

Framework::Scene& Framework::Scene::operator=(Scene&& other)
{
	if (&other != this)
	{
		height = other.height;
		other.height = 0;

		width = other.width;
		other.width = 0;

		layers = other.layers;
		other.layers.clear();
	}
	return *this;
}

void Framework::Scene::pushBack(Layer layer)
{
	layers.push_back(layer);
}

void Framework::Scene::remove(const Layer&& layer)
{
	LayerIterator result = std::find(layers.begin(), layers.end(), layer);

	if (result == layers.end())
		throw std::out_of_range("The layer provided does not exist.");
	else
		layers.erase(result);
}

Framework::LayerIterator Framework::Scene::begin()
{
	return layers.begin();
}

Framework::LayerIterator  Framework::Scene::end()
{
	return layers.end();
}

void Framework::Scene::setWidth(int w)
{
	width = w;
}

void Framework::Scene::setHeight(int h)
{
	height = h;
}

int const& Framework::Scene::getWidth() const
{
	return width;
}

int const& Framework::Scene::getHeight() const
{
	return height;
}

bool Framework::operator==(const Scene& lhs, const Scene& rhs)
{
	return lhs.width == rhs.width && lhs.height == rhs.height && lhs.layers == rhs.layers;
}

bool Framework::operator!=(const Scene& lhs, const Scene& rhs)
{
	return !(lhs == rhs);
}

std::ostream& Framework::operator<<(std::ostream& output, Framework::Scene& s)
{

	output << s.width << ", " << s.height;
	output.flush();

	return output;
}
