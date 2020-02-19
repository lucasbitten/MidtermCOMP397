#include "Game.h"
#include "Dice.h"

Dice::Dice(glm::vec2 pos)
{
	TheTextureManager::Instance()->load("../Assets/textures/DicesImage.png",
		"dice", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("dice");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::DICE);
	//setVelocity(glm::vec2(0.0f, 0.0f));
	m_pPositionToDraw = pos;
	value = 0;
	//TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);


	
}

Dice::~Dice()
{
}

void Dice::draw()
{

	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	
	TheTextureManager::Instance()->drawFrame("dice", m_pPositionToDraw.x, m_pPositionToDraw.y, 200, 200, 0, value, TheGame::Instance()->getRenderer(), 0, 255, SDL_FLIP_NONE);

	
}

void Dice::update()
{
}

void Dice::clean()
{
}


void Dice::setValue(int _value)
{
	value = _value;
}

int Dice::getValue()
{
	return value;
}
