#include "GameManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Game.h"
#include "SoundManager.h"

GameManager* GameManager::s_pInstance;

GameManager::GameManager()
{
    TheSoundManager::Instance()->load("../Assets/audio/win.wav",
        "win", sound_type::SOUND_SFX);

    TheSoundManager::Instance()->load("../Assets/audio/Jackpot.wav",
        "jackpot", sound_type::SOUND_SFX);

    TheSoundManager::Instance()->load("../Assets/audio/lost.wav",
        "lost", sound_type::SOUND_SFX);

}

GameManager::~GameManager()
{
}
