#include "Board.h"
#include "Game.h"

Board::Board()
{
	TheTextureManager::Instance()->load("../Assets/textures/board.png",
		"board", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("board");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH*0.5,Config::SCREEN_HEIGHT*0.5));
	setIsColliding(false);
	setType(GameObjectType::ISLAND);
	//setVelocity(glm::vec2(0.0f, 0.0f));


}

Board::~Board()
{
}

void Board::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("board", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Board::update()
{
}

void Board::clean()
{
}
