#ifndef WEAPON_H
#define WEAPON_H
#include <QGraphicsEllipseItem>
#include <Box2D/Box2D.h>
#endif // WEAPON_H

class Equipment {
public:
    virtual void performAction(float beginx,float beginy,float endx,float endy,QGraphicsScene* scene) = 0;
protected:

    b2BodyDef bodydef;
    b2FixtureDef fixturedef;
    b2World* world;
    b2Body* body;
    b2Fixture* fixture;
};



class Gun: public Equipment, QGraphicsEllipseItem {
public:
    Gun() {
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
        info->isCube = true;
        fixtureDef.userData = info;
        fixturedef = fixtureDef;

    }

    int getMagazine() { return magazine;}
    int getDelay() { return attackdelay;}
    int getDamage() { return damage;}
    void setDamage(unsigned int dam) { damage = dam;}
    void setMagazine(unsigned int count) { magazine = count;}
    void setDelay(unsigned int delay) { attackdelay = delay;}
    void advance(int phase){
      // world->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        setPos(-position.x*SCALETOPIXEL,-position.y*SCALETOPIXEL);
    }
    void performAction(float beginx,float beginy,float endx,float endy,QGraphicsScene* scene) {
        std::cout << " HERE WE GO" << beginx << " " <<beginy << " "<< endx  << " "<< endy << std::endl;
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

private:
    static const float gunbulletRadius = 10;
    int magazine;
    int attackdelay;
    int damage;
};

