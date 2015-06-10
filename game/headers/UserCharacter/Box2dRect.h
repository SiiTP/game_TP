#pragma once
#include <QGraphicsRectItem>
#include <memory>
using std::shared_ptr;
#define RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) / M_PI * 180.0)
const float SCALETOPIXEL = 50;
//const float32 timeStep = 1.0f/60.0f;

const int32 velocityIterations = 6;
const int32 positionIterations = 2;
class MyRect : public QGraphicsRectItem {
public:
    //это userData

    MyRect(b2World* world,float width,float height, float x ,float y,string name, bool isstatic = false);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event){    }
    void advance(int phase);
protected:
    b2Body* body;
    ObjectInfo* info;
private:
    int xx,yy;
    b2World* world;
    string name;
    bool isStatic = false;
};
