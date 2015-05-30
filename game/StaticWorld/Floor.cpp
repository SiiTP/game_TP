//тандартные библиотеки
#include <iostream>


using std::string;
using std::cout;

//библиотеки от QT
#include <QGraphicsRectItem>
#include <QGraphicsScene>

//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "../headers/staticWorld/StaticCube.h"
#include "../headers/staticWorld/StaticElement.h"
#include "../headers/staticWorld/Floor.h"

Floor::Floor(b2World *world, float beginX, float beginY, float length)
{
        this->beginX = beginX;
        this->beginY = beginY;
        this->length = length;
        StaticCube *a;
        float size = a->getSize();
        float amountOfCubes = length / size;
        for (int i = 0; i < amountOfCubes; ++i) {
            StaticCube *cube = new StaticCube(world, beginX + i * size, beginY);
            cubes.push_back(cube);
        }
}
