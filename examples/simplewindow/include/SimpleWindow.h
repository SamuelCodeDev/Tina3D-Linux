#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include "All.h"

namespace Tina
{
    class SimpleWindow : public Game
    {
    private:

    public:
        void Init() override;
		void Update() override;
		void Finalize() override;
		void Draw() override;
    };
}

#endif