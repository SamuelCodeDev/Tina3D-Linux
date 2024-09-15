#include "Engine.h"

namespace Tina
{
    Graphics * Engine::graphics = nullptr;
    Window * Engine::window = nullptr;
    Game * Engine::game = nullptr;
    Input * Engine::input = nullptr;
    
    Engine::Engine() noexcept
    {
        window = new Window();
        graphics = new Graphics();
    }

    Engine::~Engine() noexcept
    {
        delete game;
        delete graphics;
        delete input;
        delete window;
    }

    int32 Engine::Start(Game* game)
    {
        this->game = game;

        window->Create();

        WM_DELETE_WINDOW = XInternAtom(window->GetDisplay(), "WM_DELETE_WINDOW", False);
        XSetWMProtocols(window->GetDisplay(), window->GetWindow(), &WM_DELETE_WINDOW, 1);
        
        input = new Input();
        graphics->Initialize(window);

        return Loop();
    }

    int32 Engine::Loop() noexcept
    {
        XEvent event{};
        game->Init();
        input->SetEvent(&event);
        input->SetDisplay(window->GetDisplay());

        do
        {
            XNextEvent(window->GetDisplay(), &event);
            game->Update();
            game->Draw();
        } while (!XPending(window->GetDisplay()) && !Quit(&event));

        game->Finalize();

        return 0;
    }
}