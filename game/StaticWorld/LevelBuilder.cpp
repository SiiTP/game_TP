#include <QGraphicsScene>

//библиотеки от box2D
#include <memory>
using std::shared_ptr;

#include <iostream>
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>
#include "headers/staticWorld/LevelBuilder.h"
#include "headers/staticWorld/Borders.h"
#include "headers/staticWorld/Floor.h"
#include "headers/staticWorld/Wall.h"
#include "headers/staticWorld/Staircase.h"

static const int32 worldWidth  = 1000;
static const int32 worldHeight = 500;

void LevelBuilder_1::buildBorders(b2World *world, shared_ptr<QGraphicsScene> scene) {
    shared_ptr<Borders>borders ( new Borders(  world, worldWidth, worldHeight));
    borders.get()->render(scene.get());
}
void LevelBuilder_1::buildFloors(b2World *world, std::shared_ptr<QGraphicsScene> scene) {
    shared_ptr<Floor>floor1 (new Floor( world, 30, 350, 100));
    floor1.get()->render(scene.get());
    shared_ptr<Floor>floor2 ( new Floor( world, 90, 150, 120));
    floor2.get()->render(scene.get());
    shared_ptr<Floor>floor3 ( new Floor( world, 190, 350, 80));
    floor3.get()->render(scene.get());
    shared_ptr<Floor>floor4 ( new Floor( world, 350, 390, 40));
    floor4.get()->render(scene.get());
    shared_ptr<Floor>floor5 ( new Floor(  world, 350, 170, 40));
    floor5.get()->render(scene.get());
    shared_ptr<Floor>floor6 ( new Floor( world, 390, 190, 80));
    floor6.get()->render(scene.get());
    shared_ptr<Floor>floor7 ( new Floor( world, 390, 330, 60));
    floor7.get()->render(scene.get());
    shared_ptr<Floor>floor8 ( new Floor( world, 530, 130, 40));
    floor8.get()->render(scene.get());
    shared_ptr<Floor>floor9 ( new Floor( world, 530, 390, 80));
    floor9.get()->render(scene.get());
    shared_ptr<Floor>floor10 (new Floor( world, 610, 290, 140));
    floor10.get()->render(scene.get());
    shared_ptr<Floor>floor11 ( new Floor( world, 690, 150, 60));
    floor11.get()->render(scene.get());
    shared_ptr<Floor>floor12 ( new Floor( world, 750, 110, 180));
    floor12.get()->render(scene.get());
    shared_ptr<Floor>floor13 ( new Floor(  world, 930, 250, 60));
    floor13.get()->render(scene.get());
}
void LevelBuilder_1::buildWalls(b2World *world, std::shared_ptr<QGraphicsScene> scene) {
    shared_ptr<Wall>wall1  (new Wall(  world, 270, 170, 200));
    wall1.get()->render(scene.get());
    shared_ptr<Wall>wall2 ( new Wall(  world, 450, 310, 180));
    wall2.get()->render(scene.get());
    shared_ptr<Wall>wall3 ( new Wall(  world, 530, 330, 60));
    wall3.get()->render(scene.get());
    shared_ptr<Wall>wall4 ( new Wall(  world, 610, 130, 60));
    wall4.get()->render(scene.get());
    shared_ptr<Wall>wall5 ( new Wall(  world, 810, 130, 140));
    wall5.get()->render(scene.get());
}
void LevelBuilder_1::buildStaircases(b2World *world, std::shared_ptr<QGraphicsScene> scene) {
    shared_ptr<Staircase> staircase1(new StaircaseLarge(  world, 50, 240));
    staircase1.get()->render(scene.get());
    shared_ptr<Staircase> staircase2(new StaircaseMedium( world, 150, 405));
    staircase2.get()->render(scene.get());
    shared_ptr<Staircase >staircase3( new StaircaseSmall( world, 310, 430));
    staircase3.get()->render(scene.get());
    shared_ptr<Staircase> staircase4(new StaircaseXlarge( world, 490, 330));
    staircase4.get()->render(scene.get());
    shared_ptr<Staircase> staircase5( new StaircaseMedium( world, 650, 205));
    staircase5.get()->render(scene.get());
    shared_ptr<Staircase> staircase6 ( new StaircaseLarge( world, 770, 380));
    staircase6.get()->render(scene.get());
}

void LevelBuilder_1::build(b2World *world, shared_ptr<QGraphicsScene> scene) {
    buildStaircases(world, scene);
    buildWalls(world, scene);
    buildFloors(world, scene);
    buildBorders(world, scene);

}