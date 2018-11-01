#pragma once
#include "Figure.h"

class Sphere : public Figure
{
public:
	virtual void init() override;
	virtual void drawGeometry() override;

protected:
	virtual void initPoints() override;
};

