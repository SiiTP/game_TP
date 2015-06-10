#pragma once

//простой кубик
#include <memory>
#include "headers/ObjectInfo.h"
#include <QGraphicsRectItem>
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

using std::shared_ptr;

class StaticCube : public QGraphicsRectItem {
    public:
        StaticCube(b2World *world, float x, float y) ;

        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
        static float getSize() {
            return size;
        }
        static float getReverseSize() {
            return 1.0f / size;
        }
        QGraphicsPixmapItem* getCubePicture() {
            return cubePicture;
        }

private:
        float x;
        float y;
        static constexpr float MetrKoefficient = 50.0f;
        b2Body *cubeBody;
        QGraphicsPixmapItem *cubePicture;
        static constexpr float size = 20;
        ObjectInfo *info;
};


