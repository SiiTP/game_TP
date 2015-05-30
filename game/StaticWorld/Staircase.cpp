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
#include "../headers/staticWorld/StaticElement.h"
#include "../headers/staticWorld/Staircase.h"

Staircase::Staircase(b2World *world, float x, float y, float height) {
    this->x = x;
    this->y = y;
    this->height = height;

    //определение тела
    b2BodyDef *staircaseDef = new b2BodyDef();
    staircaseDef->position.Set(-x / MetrKoefficient, -y / MetrKoefficient);
    setPos(x, y); //отрисовка будет осуществляться в этой позиции

    //оболочка
    b2PolygonShape *staircaseShape = new b2PolygonShape();
    staircaseShape->SetAsBox(width / MetrKoefficient / 8, height / MetrKoefficient / 2);

    //физические свойства
    b2FixtureDef *staircaseFixt = new b2FixtureDef();
    staircaseFixt->shape = staircaseShape;
    staircaseFixt->friction = 0.9;
    staircaseFixt->density  = 1;
    staircaseFixt->isSensor = true;

    //для обработки столкновений
    ObjectInfo *info = new ObjectInfo("staircase");
    info->isStaircase = true;
    staircaseFixt->userData = info;
    //__________________________

    //добавление в мир
    staircasePolygon = world->CreateBody(staircaseDef);
    staircasePolygon->CreateFixture(staircaseFixt);

    //setBrush(QBrush(QColor(Qt::cyan)));
    //setRect(-width / 2, -height / 2, width/2, height);
}
