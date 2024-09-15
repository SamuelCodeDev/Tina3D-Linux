#include "SimpleWindow.h"

#ifdef _WIN32

#include "Resources.h"

auto APIENTRY WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow) -> int
{
    using namespace Tina;

    #ifdef _DEBUG

    try
    {
        Engine* engine = new Engine();
        engine->window->Mode(WINDOWED);
        engine->window->Size(800, 600);
        engine->window->Color(0, 122, 204);
        engine->window->Title("Triangle");
        engine->window->Icon(IDI_ICON);
        engine->window->Cursor(IDC_CURSOR);
        engine->window->LostFocus(Engine::Pause);
        engine->window->InFocus(Engine::Resume);

        int32 exit = engine->Start(new SimpleWindow());

        delete engine;

        return exit;
    }
    catch (Error & e)
    {
        MessageBox(nullptr, e.ToString().data(), "Triangle", MB_OK);
        return 0;
    }

    #elif NDEBUG
    
    Engine* engine = new Engine();
    engine->window->Mode(WINDOWED);
    engine->window->Size(800, 600);
    engine->window->Color(0, 122, 204);
    engine->window->Title("Triangle");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->LostFocus(Engine::Pause);
    engine->window->InFocus(Engine::Resume);

    int32 exit = engine->Start(new SimpleWindow());

    delete engine;

    return exit;

    #endif
}

#else

#include <iostream>

auto main(int argc, char** argv) -> int
{
    using namespace Tina;

    #ifdef _DEBUG

    try
    {
        Engine* engine = new Engine();
        engine->window->Size(800, 600);
        engine->window->Title("Triangle");

        int32 exit = engine->Start(new SimpleWindow());

        delete engine;

        return exit;
    }
    catch (Error & e)
    {
        std::cerr << e.ToString() << '\n';
        return 0;
    }

    #elif NDEBUG
    
    Engine* engine = new Engine();
    engine->window->Size(800, 600);
    engine->window->Title("Triangle");

    int32 exit = engine->Start(new SimpleWindow());

    delete engine;

    return exit;

    #endif
}

#endif