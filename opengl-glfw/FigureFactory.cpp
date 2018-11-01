#include "FigureFactory.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Sphere.h"

sharedFigure FigureFactory::createCube()
{
	sharedFigure cube(new Cube);
	cube->init();
	return cube;
}

sharedFigure FigureFactory::createPyramid()
{
	sharedFigure pyramid(new Pyramid);
	pyramid->init();
	return pyramid;
}

sharedFigure FigureFactory::createSphere()
{
	sharedFigure sphere(new Sphere);
	sphere->init();
	return sphere;
}
