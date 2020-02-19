#include "Level2Scene.h"
#include "Game.h"
#include <iostream>
#include "GameManager.h"

Level2Scene::Level2Scene()
{
	start();
}

Level2Scene::~Level2Scene()
{
}

void Level2Scene::draw()
{
	m_pBoard->draw();
	m_pDice1->draw();
	m_pDice2->draw();
	m_pDice3->draw();
	m_pDice4->draw();

	m_pRollButton->draw();
	dice1Label->draw();
	dice2Label->draw();
	dice3Label->draw();
	dice4Label->draw();
	resultLabel->draw();
	resultTextLabel->draw();
}

void Level2Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick();
	resultLabel->setText(std::to_string(GameManager::Instance()->result));
	
	dice1Label->setText(std::to_string(GameManager::Instance()->dice1Result));
	dice2Label->setText(std::to_string(GameManager::Instance()->dice2Result));
	dice3Label->setText(std::to_string(GameManager::Instance()->dice3Result));
	dice4Label->setText(std::to_string(GameManager::Instance()->dice4Result));
	
	m_pDice1->setValue(GameManager::Instance()->dice1Result);
	m_pDice2->setValue(GameManager::Instance()->dice2Result);
	m_pDice3->setValue(GameManager::Instance()->dice3Result);
	m_pDice4->setValue(GameManager::Instance()->dice4Result);
}

void Level2Scene::clean()
{
}

void Level2Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);

				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);

				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;


				/************************************************************************/
			case SDLK_w:

				break;
			case SDLK_s:

				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:

				break;

			case SDLK_s:

				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		default:
			break;
		}
	}
}

void Level2Scene::start()
{
	m_pBoard = new Board();

	m_pDice1 = new Dice(glm::vec2(30, 80));
	m_pDice2 = new Dice(glm::vec2(550, 80));
	m_pDice3 = new Dice(glm::vec2(30, 400));
	m_pDice4 = new Dice(glm::vec2(550, 400));


	m_pRollButton = new RollButton();
	m_pRollButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, 700));

	SDL_Color color = { 255,255,255,255 };

	dice1Label = new Label("0", "Consolas", 50, color);
	dice1Label->setPosition(glm::vec2(120, 320));

	dice2Label = new Label("0", "Consolas", 50, color);
	dice2Label->setPosition(glm::vec2(650, 320));

	dice3Label = new Label("0", "Consolas", 50, color);
	dice3Label->setPosition(glm::vec2(120, 700));

	dice4Label = new Label("0", "Consolas", 50, color);
	dice4Label->setPosition(glm::vec2(650, 700));

	resultLabel = new Label("0", "Consolas", 80, color);
	resultLabel->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
	
	resultTextLabel = new Label("Result:", "Consolas", 60, color);
	resultTextLabel->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.51, Config::SCREEN_HEIGHT * 0.4));
}

glm::vec2 Level2Scene::getMousePosition()
{
	return m_mousePosition;
}

