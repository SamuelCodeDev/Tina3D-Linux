#include "SimpleWindow.h"
#include "KeyCodes.h"

namespace Tina
{
    void SimpleWindow::Init()
    {
    }
    
    void SimpleWindow::Update()
    {
        if(input->CheckKeyPress(VK_ESCAPE) || input->CheckKeyPress(VK_Q))
            window->Close();
    }

    void SimpleWindow::Finalize()
    {
    }
    
    void SimpleWindow::Draw()
    {
    }
}