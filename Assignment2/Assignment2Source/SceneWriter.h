#pragma once
#include "Scene.h"
#include "XmlReader.h"
#include "Element.h"
#include <memory>

namespace Framework
{
	class SceneWriter
	{
	public:
		SceneWriter() = delete;
		~SceneWriter() = delete;

		static Xml::HElement writeScene(Scene& scene);

	private:
		static void buildSceneChildren(LayerIterator iterator, Xml::HElement result);
	};
}

