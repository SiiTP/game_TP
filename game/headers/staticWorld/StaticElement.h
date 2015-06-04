//#include "../ProjectPath.h"
#pragma once
#include "./headers/staticWorld/StaticCube.h"
class StaticElement {
public:
    void render(QGraphicsScene *scene);
    virtual ~StaticElement();
protected:
    std::vector<StaticCube*> cubes;
};
