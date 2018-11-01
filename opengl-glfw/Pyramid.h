#pragma once
#include "Figure.h"
#include <vector>
class Pyramid :	public Figure
{
public:
	void init() override;
	void drawGeometry() override;

private:
	void initPoints() override;
};

