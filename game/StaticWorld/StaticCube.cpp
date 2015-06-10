//тандартные библиотеки
#include <iostream>
#include <memory>
using std::string;
using std::cout;
using std::shared_ptr;

//библиотеки от QT
#include <QGraphicsRectItem>
#include <QGraphicsScene>

//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "./headers/ObjectInfo.h"
#include "./headers/UserCharacter/Box2dRect.h"
#include "./headers/staticWorld/StaticCube.h"

StaticCube::StaticCube(b2World *world, float x, float y) {
    this->x = x;
    this->y = y;
    //определение тела
    shared_ptr<b2BodyDef >cubeDef ( new b2BodyDef());
    cubeDef.get()->position.Set(-x / MetrKoefficient, -y / MetrKoefficient);
    setPos(x, y); //отрисовка будет осуществляться в этой позиции

    //оболочка
    b2PolygonShape cubeShape;
    cubeShape.SetAsBox(size / MetrKoefficient / 2, size / MetrKoefficient / 2);

    //физические свойства
    shared_ptr<b2FixtureDef> cubeFixt ( new b2FixtureDef());
    cubeFixt.get()->shape = &cubeShape;
    cubeFixt.get()->friction = 0.5f;
    cubeFixt.get()->density  = 1.0f;

    //для обработки столкновений
    info = new ObjectInfo("cube");
    info->setIsCube(true);
    cubeFixt->userData = info;
    //__________________________

    //добавление в мир
    cubeBody = world->CreateBody(cubeDef.get());
    cubeBody->CreateFixture(cubeFixt.get());

    setBrush(QBrush(QColor(Qt::red)));

    setRect(-size / 2, -size / 2, size, size); //отрисовка, начало сдвигаем в левый верхний угол
}
