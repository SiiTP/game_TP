#pragma once
#ifndef WORLDSINGLTON_H
#define WORLDSINGLTON_H

#endif // WORLDSINGLTON_H
#include <Box2D/Dynamics/b2World.h>
//singleton for world
class WorldSinglton {
public:
    static b2World* instance() {
 static b2World world(b2Vec2(0.0f,-15.0f));
        return &world;
    }
private:
    WorldSinglton() {}

};

