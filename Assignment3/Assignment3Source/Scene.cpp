#include "Scene.h"

Framework::Scene::Scene(int initialWidth, int initialHeight) :
	width(initialWidth), height(initialHeight)
{
}

void Framework::Scene::remove(const Layer&& layer)
{
	layers.remove(layer);
}

Framework::LayerIterator Framework::Scene::begin()
{
	return layers.begin();
}

Framework::LayerIterator  Framework::Scene::end()
{
	return layers.end();
}

void Framework::Scene::setWidth(size_t w)
{
	width = w;
}

void Framework::Scene::setHeight(size_t h)
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

bool Framework::Scene::operator==(const Scene& rhs) const
{
	return (width == rhs.width)
		&& (height == rhs.height)
		&& (layers == rhs.layers);
}

bool Framework::Scene::operator!=(const Scene& rhs) const
{
	return !(*this == rhs);
}

//std::ostream& Framework::operator<<(std::ostream& output, Framework::Scene& s)
//{
//
//	output << s.width << ", " << s.height;
//	output.flush();
//
//	return output;
//}
