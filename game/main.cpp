//стандартные библиотеки
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <memory>
using std::string;
using std::cout;
using std::shared_ptr;

//библиотеки от QT
#include <QGraphicsRectItem>
#include <QTransform>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QMouseEvent>
#include <QBrush>

//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "./headers/ObjectInfo.h"
#include "./headers/UserCharacter/Box2dRect.h"
#include "./headers/UserCharacter/UserSinglton.h"
#include "./headers/staticWorld/StaticCube.h"
#include "./headers/staticWorld/StaticElement.h"
#include "./headers/staticWorld/Borders.h"
#include "./headers/staticWorld/Floor.h"
#include "./headers/staticWorld/Wall.h"
#include "./headers/staticWorld/Staircase.h"

#include "./headers/Weapons/weapon.h"
#include "./headers/Weapons/WeaponFactory.h"
#include "./headers/UserCharacter/CharacterStatic.h"
#include "./headers/MyContactListener.h"
#include "./headers/MyView.h"
#include "./headers/WorldSinglton.h"

//параметры мира, должны быть кратны 10, чтобы границы мира были ровными
static const int32 worldWidth  = 1000;
static const int32 worldHeight = 500;

extern const  QString path = "/home/ivan/TP_GameProject_CPP";


int main(int argc, char** argv) {

    b2World* world = WorldSinglton::instance();
    //создание qt мира
    B2_NOT_USED(argc);
    B2_NOT_USED(argv);
    QApplication a(argc,argv);
    shared_ptr<QGraphicsScene> scene(new QGraphicsScene(0, 0, worldWidth, worldHeight));
    MyView view;

    QPixmap pict(path+"/project_sprites/backgrounds/background1.jpg");
    view.setBackgroundBrush(QBrush(pict));
    //заполнение статикой
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
    shared_ptr<Character> character1 ( new Character(  world, 205, 270));
    scene.get()->addItem(character1.get());
   // Gun* g = new Gun(  world,105,240,10);
  //  scene->addItem(g);
    shared_ptr<Borders >borders ( new Borders(  world, worldWidth, worldHeight));
    borders.get()->render(scene.get());
    //QMatrix matrix(0.5, 0, 0, 0.5, 0, 0);
    //view.setMatrix(matrix);
    shared_ptr<MyContactListener>contact ( new MyContactListener());
    world->SetContactListener(contact.get());
    view.setMouseTracking(true);
    view.setScene(scene.get());
    view.setUser(character1);
    view.show();
    shared_ptr<QTimer> qtime (new QTimer(&a));
    qtime.get()->setInterval(40);
    qtime.get()->start();
    QObject::connect(qtime.get(), SIGNAL(timeout()), scene.get(), SLOT(advance()));
    return a.exec();
}


