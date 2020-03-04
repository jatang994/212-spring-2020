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
    
}

// Draw function
void Fractal::draw(CM_Renderer *renderer, int steps)
{
   //draw top left to bottom right
   renderer->drawLine(0, 100, 100, 0);
    
    //draw top right to bottom left
   renderer->drawLine(100, 0, 0, 100);
    
   //grid(renderer, 0.0, 100.0, 100.0, 0.0, steps);
}
