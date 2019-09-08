#pragma once
#include <map>
#include "SquarePen.h"
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class PenFactory
	{
	public:
		PenFactory();
		PenFactory(const PenFactory& other) = default;
		PenFactory(PenFactory&& other) noexcept = default;
		PenFactory& operator=(const PenFactory& other) = default;
		PenFactory& operator=(PenFactory&& other) = default;
		~PenFactory() noexcept = default;

		void addPen(std::string const& tip, HPen const& pen);

		HPen createPen(std::string const& tip);

	private:
		std::map<std::string, HPen> myPens;
	};
}
