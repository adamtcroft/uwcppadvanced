#pragma once
#include "Scene.h"
#include "XmlReader.h"

namespace Framework
{
	class SceneReader
	{
	public:
		SceneReader();
		~SceneReader();

		static Framework::Scene readScene(Xml::Element& root);

	private:
		static void buildLayer(Scene& parent, Xml::HElement& element);
		static void buildPlacedGraphic(Layer& parent, Xml::HElement& element);
	};
}

