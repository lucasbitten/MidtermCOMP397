#include "Level2Button.h"
#include "Game.h"

Level2Button::Level2Button()
// call super constructor
	:Button(
		"../Assets/textures/Level2Button.png",
		"level2Button",
		START_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

Level2Button::~Level2Button()
{
}

bool Level2Button::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("level2Button", 0);
			Game::Instance()->changeSceneState(LEVEL2_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


