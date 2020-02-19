#pragma once
#ifndef __LEVEL_2_SCENE__
#define __LEVEL_2_SCENE__

#include "Scene.h"
#include "Dice.h"
#include "RollButton.h"
#include "Label.h"
#include "Board.h"

class Level2Scene : public Scene
{
public:
	Level2Scene();
	~Level2Scene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

	Label* dice1Label;
	Label* dice2Label;
	Label* dice3Label;
	Label* dice4Label;
	Label* resultTextLabel;
	Label* resultLabel;
private:
	// game objects


	Board* m_pBoard;
	Dice* m_pDice1;
	Dice* m_pDice2;
	Dice* m_pDice3;
	Dice* m_pDice4;

	RollButton* m_pRollButton;



	// private data member
	glm::vec2 m_mousePosition;


};

#endif /* defined (__LEVEL_2_SCENE__) */
