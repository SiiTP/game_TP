//стандартные библиотеки
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <memory>
using std::string;
using std::cout;

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
b2World* WorldSinglton::world = NULL;

int main(int argc, char** argv) {

    b2World* world = WorldSinglton::instance();
    //создание qt мира
    B2_NOT_USED(argc);
    B2_NOT_USED(argv);
    QApplication a(argc,argv);
    QGraphicsScene* scene= new QGraphicsScene(0, 0, worldWidth, worldHeight);
    MyView view;

    QPixmap pict(path+"/project_sprites/backgrounds/background1.jpg");
    view.setBackgroundBrush(QBrush(pict));
    //заполнение статикой
    Staircase *staircase1 = new StaircaseLarge(  world, 50, 240);
    staircase1->render(scene);
    Staircase *staircase2 = new StaircaseMedium( world, 150, 405);
    staircase2->render(scene);
    Staircase *staircase3 = new StaircaseSmall( world, 310, 430);
    staircase3->render(scene);
    Staircase *staircase4 = new StaircaseXlarge( world, 490, 330);
    staircase4->render(scene);
    Staircase *staircase5 = new StaircaseMedium( world, 650, 205);
    staircase5->render(scene);
    Staircase *staircase6 = new StaircaseLarge( world, 770, 380);
    staircase6->render(scene);

    Floor *floor1 = new Floor( world, 30, 350, 100);
    floor1->render(scene);
    Floor *floor2 = new Floor( world, 90, 150, 120);
    floor2->render(scene);
    Floor *floor3 = new Floor( world, 190, 350, 80);
    floor3->render(scene);
    Floor *floor4 = new Floor( world, 350, 390, 40);
    floor4->render(scene);
    Floor *floor5 = new Floor(  world, 350, 170, 40);
    floor5->render(scene);
    Floor *floor6 = new Floor( world, 390, 190, 80);
    floor6->render(scene);
    Floor *floor7 = new Floor( world, 390, 330, 60);
    floor7->render(scene);
    Floor *floor8 = new Floor( world, 530, 130, 40);
    floor8->render(scene);
    Floor *floor9 = new Floor( world, 530, 390, 80);
    floor9->render(scene);
    Floor *floor10 = new Floor( world, 610, 290, 140);
    floor10->render(scene);
    Floor *floor11 = new Floor( world, 690, 150, 60);
    floor11->render(scene);
    Floor *floor12 = new Floor( world, 750, 110, 180);
    floor12->render(scene);
    Floor *floor13 = new Floor(  world, 930, 250, 60);
    floor13->render(scene);

    Wall *wall1 = new Wall(  world, 270, 170, 200);
    wall1->render(scene);
    Wall *wall2 = new Wall(  world, 450, 310, 180);
    wall2->render(scene);
    Wall *wall3 = new Wall(  world, 530, 330, 60);
    wall3->render(scene);
    Wall *wall4 = new Wall(  world, 610, 130, 60);
    wall4->render(scene);
    Wall *wall5 = new Wall(  world, 810, 130, 140);
    wall5->render(scene);
    Character *character1 = new Character(  world, 205, 270);
    scene->addItem(character1);
   // Gun* g = new Gun(  world,105,240,10);
  //  scene->addItem(g);
    Borders *borders = new Borders(  world, worldWidth, worldHeight);
    borders->render(scene);
    //QMatrix matrix(0.5, 0, 0, 0.5, 0, 0);
    //view.setMatrix(matrix);
    MyContactListener *contact = new MyContactListener();
    world->SetContactListener(contact);
    view.setMouseTracking(true);
    view.setScene(scene);
    view.setUser(character1);
    view.show();
    QTimer* qtime =new QTimer(&a);
    qtime->setInterval(40);
    qtime->start();
    QObject::connect(qtime, SIGNAL(timeout()), scene, SLOT(advance()));
    return a.exec();
}


