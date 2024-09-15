#include "Game.h"
#include "Engine.h"
#include <unistd.h>

namespace Tina
{
    Graphics *& Game::graphics = Engine::graphics;
    Window *& Game::window = Engine::window;
    Input *& Game::input = Engine::input;

    Game::Game() noexcept
    {
    }

    Game::~Game()
    {
    }

    void Game::Draw()
    {
    }

    void Game::Display()
    {
    }

    void Game::OnPause() 
    { usleep(10); }
}