#define pathStaticWorld "/headers/staticWorld/"

//стандартные библиотеки
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

//библиотеки от QT
#include <QGraphicsRectItem>
#include <QTransform>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QMouseEvent>

//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "./headers/staticWorld/StaticCube.h"
#include "./headers/MyView.h"

#include "./headers/staticWorld/StaticElement.h"
#include "./headers/staticWorld/Borders.h"
#include "./headers/staticWorld/Floor.h"
#include "./headers/staticWorld/Wall.h"
#include "./headers/staticWorld/Staircase.h"


//параметры мира, должны быть кратны 10, чтобы границы мира были ровными
static const int32 worldWidth  = 900;
static const int32 worldHeight = 500;
static const float32 timeStep = 1.0f / 60.0f;

int main(int argc, char** argv) {
    //создание box2d мира
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    //создание qt мира
    B2_NOT_USED(argc);
    B2_NOT_USED(argv);
    QApplication a(argc,argv);
    QGraphicsScene* scene= new QGraphicsScene(0, 0, worldWidth, worldHeight);
    MyView view;

    //заполнение статикой
    Staircase *staircase1 = new StaircaseSmall(&world, 650, 250);
    staircase1->render(scene);
    Staircase *staircase2 = new StaircaseMedium(&world, 720, 250);
    staircase2->render(scene);
    Staircase *staircase3 = new StaircaseLarge(&world, 790, 250);
    staircase3->render(scene);
    Staircase *staircase4 = new StaircaseXlarge(&world, 860, 250);
    staircase4->render(scene);
    Borders *borders = new Borders(&world, worldWidth, worldHeight);
    borders->render(scene);
    Floor *floor1 = new Floor(&world, 15, 305, 220);
    floor1->render(scene);
    Wall *wall1 = new Wall(&world, 225, 155, 140);
    wall1->render(scene);
    Floor *floor2 = new Floor(&world, 145, 395, 320);
    floor2->render(scene);
    Floor *floor3 = new Floor(&world, 265, 195, 120);
    floor3->render(scene);

    view.setMouseTracking(true);
    view.setScene(scene);
    view.show();
    //QTimer* qtime =new QTimer();
    //qtime->setInterval(60);
    //qtime->start();
    return a.exec();
}


