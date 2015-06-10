//тандартные библиотеки
#include <iostream>
#include <memory>


using std::string;
using std::cout;
using std::shared_ptr;

//библиотеки от QT
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>


//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "../headers/ObjectInfo.h"
#include "../headers/UserCharacter/Box2dRect.h"
#include "../headers/WorldSinglton.h"
#include "../headers/Weapons/weapon.h"
#include "../headers/Weapons/WeaponFactory.h"
#include "../headers/UserCharacter/CharacterStatic.h"
#include "../headers/MyContactListener.h"

static const float timeStep = 1.0f / 60.0f;
MyRect::MyRect(b2World* world,float width,float height, float x ,float y,string name, bool isstatic) {
    this->name = name;
    this->world = world;
    b2BodyDef bodyDef;
    if (!isstatic) {
        bodyDef.type = b2_dynamicBody;
    }
    float yy = y/SCALETOPIXEL;
    float xx = x/SCALETOPIXEL;
    bodyDef.position.Set(-xx,-yy);
    bodyDef.fixedRotation = true; //отключение вращения
    setPos(x,y);
    b2Body* body = world->CreateBody(&bodyDef);
    this->body = body;
    b2PolygonShape dynamicBox;
    yy = height/SCALETOPIXEL/2;
    xx = width/SCALETOPIXEL/2;
    dynamicBox.SetAsBox(xx,yy);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.9f;
    //для обработки столкновений
    info = new ObjectInfo("character");
    info->setIsCharacter(true);
    fixtureDef.userData = info;
    //__________________________

    body->CreateFixture(&fixtureDef);
    setBrush(QBrush(QColor(Qt::gray)));
    setRect(-width/2,-height/2,width,height);
    setAcceptHoverEvents(true);
}

void MyRect::advance(int phase){
    if (!phase) return;

    world->Step(timeStep, velocityIterations, positionIterations);
    b2Vec2 position = body->GetPosition();

    setPos(-position.x*SCALETOPIXEL,-position.y*SCALETOPIXEL);
}
