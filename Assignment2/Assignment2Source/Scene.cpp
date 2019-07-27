#include "Scene.h"

Framework::Scene::Scene(int initialWidth, int initialHeight)
	:width(initialWidth), height(initialHeight)
{

}

void Framework::Scene::pushBack(Layer&& layer)
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
