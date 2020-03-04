#include "Fractal.h"
#include "CM_Renderer.h"
#include <iostream>

Fractal::Fractal()
{

}
Fractal::~Fractal()
{

}

void grid(CM_Renderer *renderer, float top, float right, float bottom, float left, int steps) {
    if (!steps) return;

    // Get to center of box defined by coords
    int centerx = left + ((right - left) / 2);
    int centery = top + ((bottom - top) / 2);

    renderer->drawLineF(centerx, bottom, centerx, top);
    renderer->drawLineF(left, centery, right, centery);
    // Top left
    grid(renderer, top, centerx, centery, left, steps-1);

    // Top Right
    grid(renderer, top, right, centery, centerx, steps-1);

    // Bottom left
    grid(renderer, centery, centerx, bottom, left, steps-1);

    // Bottom right
    grid(renderer, centery, right, bottom, centerx, steps-1);
}

// Draw function
void Fractal::draw(CM_Renderer *renderer, int steps)
{
    //draw top left to bottom right
    grid(renderer, 0.0, 100.0, 100.0, 0.0, steps);
    //draw top right to bottom left
//    renderer->drawLine(100, 0, 0, 100);
}
