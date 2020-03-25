#ifndef FRACTAL_H
#define FRACTAL_H

class CM_Renderer;

class Fractal
{
public:
    Fractal();
    ~Fractal();

    void draw(CM_Renderer* renderer, int steps);
};

#endif // FRACTAL_H
