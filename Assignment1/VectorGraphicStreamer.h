#pragma once
#include <sstream>
#include "VectorGraphic.h"

namespace VG
{
	class VectorGraphicStreamer
	{
	public:
		VectorGraphicStreamer();
		~VectorGraphicStreamer();

		//static VG::VectorGraphic fromXml(std::stringstream& ss);

	private:
		std::stringstream stream;
	};
}
