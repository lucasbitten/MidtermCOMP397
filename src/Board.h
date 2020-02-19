#pragma once
#ifndef __BOARD__
#define __BOARD__
#include "DisplayObject.h"

class Board : public DisplayObject
{
public:
	Board();
	~Board();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__Board__) */