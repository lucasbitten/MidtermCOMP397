#include "RollButton.h"
#include "Game.h"
#include "GameManager.h"

RollButton::RollButton()
// call super constructor
	:Button(
		"../Assets/textures/rollButton.png",
		"rollButton",
		ROLL_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

RollButton::~RollButton()
{
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playSound("button", 0);

			GameManager::Instance()->dice1Result = Util::RandomRange(1, 6);
			GameManager::Instance()->dice2Result = Util::RandomRange(1, 6);
			GameManager::Instance()->dice3Result = Util::RandomRange(1, 6);
			GameManager::Instance()->dice4Result = Util::RandomRange(1, 6);

			const int result1 = GameManager::Instance()->dice1Result;
			const int result2 = GameManager::Instance()->dice2Result;
			const int result3 = GameManager::Instance()->dice3Result;
			const int result4 = GameManager::Instance()->dice4Result;


			if(result1 < result2 && result1 < result3 && result1 < result4)
			{
				GameManager::Instance()->result = result2 + result3 + result4;
			} else if (result2 < result1 && result2 < result3 && result2 < result4)
			{
				GameManager::Instance()->result = result1 + result3 + result4;
			}
			else if (result3 < result1 && result3 < result2 && result3 < result4)
			{
				GameManager::Instance()->result = result1 + result2 + result4;
			}
			else if (result4 < result1 && result4 < result2 && result4 < result3)
			{
				GameManager::Instance()->result = result1 + result2 + result3;
			}

			
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


