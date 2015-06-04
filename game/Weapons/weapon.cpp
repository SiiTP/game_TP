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
#include "../headers/WorldSinglton.h"
#include "../headers/Weapons/weapon.h"
#include "../headers/Weapons/WeaponFactory.h"

Gun::Gun(){
        world = WorldSinglton::instance();
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;

        bodydef = bodyDef;
        b2CircleShape* dynamicCircle = new b2CircleShape();
        dynamicCircle->m_radius = gunbulletRadius/SCALETOPIXEL/2;
        b2FixtureDef fixtureDef;
        fixtureDef.shape = dynamicCircle;
        fixtureDef.density = 1.11f;
        fixtureDef.friction = 0.5f;
        ObjectInfo *info = new ObjectInfo("bullet");
        info->setIsCube(true);
        fixtureDef.userData = info;
        fixturedef = fixtureDef;

}
void Gun::advance(int phase){
    b2Vec2 position = body->GetPosition();
    setPos(-position.x*SCALETOPIXEL,-position.y*SCALETOPIXEL);
}

void Gun::performAction(float beginx,float beginy,float endx,float endy,QGraphicsScene* scene) {
    float yy = beginy/SCALETOPIXEL;
    float xx = beginx/SCALETOPIXEL;
    bodydef.position.Set(-xx,-yy);
    setPos(beginx,beginy);
    body = world->CreateBody(&bodydef);
    fixture = body->CreateFixture(&fixturedef);

    b2Vec2 vector = b2Vec2(-(endx-beginx)/SCALETOPIXEL,-(endy-beginy)/SCALETOPIXEL);
    body->ApplyLinearImpulse(vector,body->GetWorldCenter(),true);
    //body->SetLinearVelocity(vector);
    setBrush(QBrush(QColor(Qt::gray)));

    setRect(-gunbulletRadius/2,-gunbulletRadius/2,gunbulletRadius,gunbulletRadius);
    scene->addItem(this);
}
