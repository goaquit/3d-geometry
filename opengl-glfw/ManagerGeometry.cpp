#include "ManagerGeometry.h"
#include "FigureFactory.h"

void ManagerGeometry::createFigure()
{
	FigureFactory factory;

	auto cube(factory.createCube());
	cube->position({ 1.0f,0.0f,0.0f });

	auto pyramid(factory.createPyramid());
	pyramid->scale(0.5f);
	pyramid->position({ -1.0f,-0.5f,-0.5f });

	auto sphere(factory.createSphere());
	sphere->position({ 2.0f,0.0f,-1.0f });

	figures.push_back(cube);
	figures.push_back(pyramid);
	figures.push_back(sphere);
}

void ManagerGeometry::draw(const glm::mat4 &viewMatrix)
{
	for (auto &figure : figures)
	{
		figure->changeView(viewMatrix);
		figure->draw();
	}
}

void ManagerGeometry::clear()
{
	for (auto &figure : figures)
	{
		figure->cleanUp();
	}

	figures.clear();
}

void ManagerGeometry::changePerspective(int width, int height)
{
	const auto aspect = static_cast<float>(width) / static_cast<float>(height);
	GLfloat fov = 45.0f;
	const auto projection = glm::perspective(fov, aspect, 0.1f, 100.0f);

	for (auto &figure : figures)
	{
		figure->changeProjection(projection);
		figure->draw();
	}
}
