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
#include "../headers/ObjectInfo.h"
#include "../headers/UserCharacter/Box2dRect.h"
#include "../headers/staticWorld/StaticCube.h"

StaticCube::StaticCube(b2World *world, float x, float y) {
    this->x = x;
    this->y = y;
    //определение тела
    b2BodyDef *cubeDef = new b2BodyDef();
    cubeDef->position.Set(-x / MetrKoefficient, -y / MetrKoefficient);
    setPos(x, y); //отрисовка будет осуществляться в этой позиции

    //оболочка
    b2PolygonShape cubeShape;
    cubeShape.SetAsBox(size / MetrKoefficient / 2, size / MetrKoefficient / 2);

    //физические свойства
    b2FixtureDef *cubeFixt = new b2FixtureDef();
    cubeFixt->shape = &cubeShape;
    cubeFixt->friction = 0.5f;
    cubeFixt->density  = 1.0f;

    //для обработки столкновений
    ObjectInfo *info = new ObjectInfo("cube");
    info->isCube = true;
    cubeFixt->userData = info;
    //__________________________

    //добавление в мир
    cubeBody = world->CreateBody(cubeDef);
    cubeBody->CreateFixture(cubeFixt);

    setBrush(QBrush(QColor(Qt::red)));

    setRect(-size / 2, -size / 2, size, size); //отрисовка, начало сдвигаем в левый верхний угол
}
