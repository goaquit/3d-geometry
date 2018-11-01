#include "Pyramid.h"
#include "SynchronizationFrameSingleton.h"

void Pyramid::init()
{
	initPoints();
	vertexBinding();

	shader.setShaderFile("shaders/vertexDefault.glsl", "shaders/fragmentDefault.glsl");
}

void Pyramid::drawGeometry()
{
	const auto delta = static_cast<float>(SynchronizationFrameSingleton::Instance().deltaTime());

	rotate(0.5f * delta, {0.0f,1.0f,0.0f});

	drawTrianglesArrays(static_cast<int>( vertices.size() ) / 3);
}

void Pyramid::initPoints()
{
	vertices = {
		-1.0f, 0.0f, 1.0f,
		-1.0f, 0.0f, -1.0f,
		1.0f, 0.0f, -1.0f,

		1.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 1.0f,
		-1.0f, 0.0f, 1.0f,	

		-1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		-1.0f, 0.0f, -1.0f,

		-1.0f, 0.0f, -1.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, -1.0f,

		1.0f, 0.0f, -1.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 1.0f,

		1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		-1.0f, 0.0f, 1.0f,
	};

	color = {
			0.5f,  0.7f,  0.0f,
			0.5f,  0.7f,  0.0f,
			0.2f,  1.0f,  0.1f,

			0.2f,  1.0f,  0.1f,			
			0.2f,  1.0f,  0.1f,
			0.5f,  0.7f,  0.0f,

			0.5f,  0.7f,  0.0f,
			0.3f,  0.9f,  0.0f,
			0.2f,  1.0f,  0.1f,

			0.5f,  0.7f,  0.0f,
			0.3f,  0.9f,  0.0f,
			0.2f,  1.0f,  0.1f,

			0.5f,  0.7f,  0.0f,
			0.3f,  0.9f,  0.0f,
			0.2f,  1.0f,  0.1f,

			0.5f,  0.7f,  0.0f,
			0.3f,  0.9f,  0.0f,
			0.2f,  1.0f,  0.1f,
	};
}