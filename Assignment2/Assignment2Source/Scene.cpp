#include "Scene.h"

Framework::Scene::Scene(int initialWidth, int initialHeight)
	:width(initialWidth), height(initialHeight)
{

}

void Framework::Scene::pushBack(Layer&& layer)
{
	layers.push_back(layer);
}

Framework::LayerIterator Framework::Scene::begin()
{
	return layers.begin();
}

Framework::LayerIterator  Framework::Scene::end()
{
	return layers.end();
}
