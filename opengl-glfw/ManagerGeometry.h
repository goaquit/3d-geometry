#pragma once
#include "Figure.h"
#include <vector>

#include <glm/glm.hpp>

class ManagerGeometry
{
public:
	void createFigure();
	void draw(const glm::mat4 &viewMatrix);
	void clear();

	void changePerspective(int width, int height);


private:
	std::vector<std::shared_ptr<Figure>> figures;
};

