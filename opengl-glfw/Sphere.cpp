#define _USE_MATH_DEFINES
#include "Sphere.h"
#include <cmath>

void Sphere::init()
{
	initPoints();
	vertexBinding();

	shader.setShaderFile("shaders/vertexDefault.glsl", "shaders/fragmentDefault.glsl");
}

void Sphere::drawGeometry()
{
	drawTrianglesArrays(
		static_cast<int>(vertices.size() / 3),
		GL_TRIANGLE_STRIP
	);
}

void Sphere::initPoints()
{
	for (int i = 0; i <= 40; ++i)
	{
		float lat0 = (float)M_PI * (-0.5f + (float)(i - 1) / 40);
		float z0 = sin(lat0);
		float zr0 = cos(lat0);

		float lat1 = (float)M_PI * (-0.5f + (float)i / 40);
		float z1 = sin(lat1);
		float zr1 = cos(lat1);

		for (int j = 0; j <= 40; ++j)
		{
			float lng = 2 * (float)M_PI * (float)(j - 1) / 40;
			float x = cos(lng);
			float y = sin(lng);

			vertices.push_back(x * zr0);
			vertices.push_back(y * zr0);
			vertices.push_back(z0);     


			color.push_back(0.7f);
			color.push_back(0.1f);
			color.push_back(0.0f);

			vertices.push_back(x * zr1);
			vertices.push_back(y * zr1);
			vertices.push_back(z1);     


			color.push_back(0.6f);
			color.push_back(0.2f);
			color.push_back(0.0f);
		}
	}
}