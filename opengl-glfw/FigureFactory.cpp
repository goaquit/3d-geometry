#include "FigureFactory.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Sphere.h"

SharedFigure FigureFactory::createCube()
{
	SharedFigure cube(new Cube);
	cube->init();
	return cube;
}

SharedFigure FigureFactory::createPyramid()
{
	SharedFigure pyramid(new Pyramid);
	pyramid->init();
	return pyramid;
}

SharedFigure FigureFactory::createSphere()
{
	SharedFigure sphere(new Sphere);
	sphere->init();
	return sphere;
}
