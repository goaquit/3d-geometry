#pragma once
#include <memory>

class Figure;

using SharedFigure = std::shared_ptr<Figure>;

class FigureFactory
{
public:
	SharedFigure createCube();
	SharedFigure createPyramid();
	SharedFigure createSphere();

	virtual ~FigureFactory() {};
};

