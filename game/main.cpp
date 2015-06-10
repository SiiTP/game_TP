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
#include "./headers/staticWorld/LevelBuilder.h"

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
    LevelBuilder *builder = new LevelBuilder_1();
    builder->build(world, scene);

    shared_ptr<Character> character1 (new Character(world, 205, 270));
    scene.get()->addItem(character1.get());
   // Gun* g = new Gun(  world,105,240,10);
  //  scene->addItem(g);

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


