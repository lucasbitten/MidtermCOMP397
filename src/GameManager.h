#pragma once
#ifndef __GameManager__
#define  __GameManager__

#include <string>
#include <vector>
#include <sstream>

class GameManager
{
public:


	static GameManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new GameManager();
			return s_pInstance;
		}

		return s_pInstance;
	}

	GameManager();
	~GameManager();
	static GameManager* s_pInstance;

	int dice1Result = 0;
	int dice2Result = 0;

};

typedef GameManager TheGameManager;


#endif
