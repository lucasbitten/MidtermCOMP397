#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Level2Button.h"
#include "Board.h"


class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	
	// Game Objects
	Board* m_pBoard;
	Label* m_pStartLabel;
	StartButton* m_pStartButton;
	Level2Button* m_pLevel2Button;
	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__START_SCENE__) */