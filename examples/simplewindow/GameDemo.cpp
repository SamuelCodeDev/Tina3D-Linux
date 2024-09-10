#include "GameDemo.h"
#include "KeyCodes.h"

namespace Tina
{
    void GameDemo::Init()
    {
    }
    
    void GameDemo::Update()
    {
        if(input->CheckKeyPress(VK_ESCAPE) || input->CheckKeyPress(VK_Q))
            window->Close();
    }

    void GameDemo::Finalize()
    {
    }
    
    void GameDemo::Draw()
    {
    }
}