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
    Gun() ;

    int getDamage() { return damage;}
    void setDamage(unsigned int dam) { damage = dam;}

    void advance(int phase);

    void performAction(float beginx,float beginy,float endx,float endy,QGraphicsScene* scene);

private:
    static constexpr float gunbulletRadius = 10;
    int damage;
};

