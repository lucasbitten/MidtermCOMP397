#pragma once
#ifndef __DICE__
#define __DICE__
#include "DisplayObject.h"

class Dice : public DisplayObject
{
public:
	Dice(glm::vec2 positionToDraw);
	~Dice();

	void draw() override;
	void update() override;
	void clean() override;

	int value;

	void setValue(int value);
	int getValue();

private:

	glm::vec2 m_pPositionToDraw;

	
};

#endif /* defined (__DICE__) */