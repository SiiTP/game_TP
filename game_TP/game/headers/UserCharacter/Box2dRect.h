#ifndef BOX2DRECT_H
#define BOX2DRECT_H

#endif // BOX2DRECT_H
#include <QGraphicsRectItem>
#include <iostream>
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>
#include <string>
#include <QTransform>
#include <QBrush>
 #define RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) / M_PI * 180.0)
const float SCALETOPIXEL = 50;
using namespace std;
class MyRect : public QGraphicsRectItem {
public:
    int xx,yy;
    float32 timeStep = 1.0f/60.0f;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    b2World* world;
    b2Body* body;
    string name;
    bool isStatic = false;
    MyRect(b2World* world) {
        this->world = world;
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(4.0f,6.0f);
        b2Body* body = world->CreateBody(&bodyDef);
        this->body = body;
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(3.0f,3.0f);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;

        body->CreateFixture(&fixtureDef);

        xx = 4*SCALETOPIXEL;
        yy =6*SCALETOPIXEL;
        setAcceptHoverEvents(true);
        setRect(xx,yy,3*SCALETOPIXEL,3*SCALETOPIXEL);
        setBrush(QBrush(QColor(Qt::gray)));
    }
    MyRect(b2World* world,float width,float height, float x ,float y,string name, bool isstatic = false) {
        this->name = name;
        this->world = world;
        b2BodyDef bodyDef;
        if (!isstatic) {
        bodyDef.type = b2_dynamicBody;
        }
        float yy = y/SCALETOPIXEL;
        float xx = x/SCALETOPIXEL;
        bodyDef.position.Set(-xx,-yy);
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
        fixtureDef.friction = 0.5f;

        body->CreateFixture(&fixtureDef);
        setBrush(QBrush(QColor(Qt::gray)));
        setRect(-width/2,-height/2,width,height);
        setAcceptHoverEvents(true);
    }

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event){
        b2Vec2 position = body->GetPosition();
        cout <<name << " " << position.x << ' ' << position.y << endl;
        body->ApplyLinearImpulse(b2Vec2(0,4.0f),body->GetWorldCenter(),true);
        cout <<name << " " << x() << ' ' << y() << endl;
    }
    void advance(int phase){
        if (!phase) return;

       world->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        //cout <<name << " " << position.x*SCALETOPIXEL << ' ' << position.y*SCALETOPIXEL << endl;
      // cout <<name << " " << position.x << ' ' << position.y << endl;
      // cout <<name << " " << x() << ' ' << y() << endl;

        float32 angle = body->GetAngle();
         angle = RADIANS_TO_DEGREES(angle);
        while (angle <= 0){
           angle += 360;
        }
        while (angle > 360){
           angle -= 360;
        }

      // cout <<name<< ' ' << angle << endl;
       //????setTransformOriginPoint(rect().width()/2,rect().height()/2);
       setRotation(angle);
       setPos(-position.x*SCALETOPIXEL,-position.y*SCALETOPIXEL);
    }
};
