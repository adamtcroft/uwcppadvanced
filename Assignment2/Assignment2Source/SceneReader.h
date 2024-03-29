#pragma once
#include "Scene.h"
#include "XmlReader.h"

namespace Framework
{
	class SceneReader
	{
	public:
		SceneReader() = delete;

		SceneReader(const SceneReader& other) = delete;
		SceneReader(SceneReader&& other) = delete;

		SceneReader& operator=(const SceneReader& other) = delete;
		SceneReader& operator=(SceneReader&& other) = delete;

		~SceneReader() = delete;

		static Framework::Scene readScene(Xml::Element& root);

	private:
		static void buildLayer(Scene& parent, Xml::HElement& element);
		static void buildPlacedGraphic(Layer& parent, Xml::HElement& element);
	};
}

