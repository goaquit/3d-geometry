#pragma once
#include <memory>

class Figure;

using sharedFigure = std::shared_ptr<Figure>;

class FigureFactory
{
public:
	sharedFigure createCube();
	sharedFigure createPyramid();
	sharedFigure createSphere();

	virtual ~FigureFactory() {};
};

