#pragma once
#include "Figure.h"
#include <vector>

class Cube : public Figure
{
public:
	void init() override;

protected:
	void initPoints() override;	
};

