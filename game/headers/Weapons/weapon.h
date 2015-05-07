#ifndef WEAPON_H
#define WEAPON_H
#include <QGraphicsEllipseItem>
#include <Box2D/Box2D.h>
#endif // WEAPON_H

class Weapon {
public:
    int getMagazine() { return magazine;}
    int getDelay() { return attackdelay;}
    int getDamage() { return damage;}
    void setDamage(unsigned int dam) { damage = dam;}
    void setMagazine(unsigned int count) { magazine = count;}
    void setDelay(unsigned int delay) { attackdelay = delay;}
    virtual void attack() = 0;
protected:
    b2Fixture* fixture;
    b2Body* body;
    b2World* world;
private:
    int magazine;
    int attackdelay;
    int damage;
};




class Gun: public Weapon, public QGraphicsEllipseItem {
public:
    Gun(b2World* world,float x, float y, float bulletsize) {
        this->world = world;
        radius = bulletsize;
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;

        float yy = y/SCALETOPIXEL;
        float xx = x/SCALETOPIXEL;
        bodyDef.position.Set(-xx,-yy);
        setPos(x,y);
        body = world->CreateBody(&bodyDef);
        b2CircleShape dynamicCircle;
        radius = bulletsize/SCALETOPIXEL/2;

        dynamicCircle.m_radius = radius;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicCircle;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.5f;

        fixture = body->CreateFixture(&fixtureDef);
        setBrush(QBrush(QColor(Qt::gray)));
        //setRect(-bulletsize/2,-bulletsize/2,bulletsize,bulletsize);
        setRect(-bulletsize/2,-bulletsize/2,bulletsize,bulletsize);
        setAcceptHoverEvents(true);
    }
    void advance(int phase){
        world->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        setPos(-position.x*SCALETOPIXEL,-position.y*SCALETOPIXEL);
    }

    void attack() { }
private:
    float radius;
};
