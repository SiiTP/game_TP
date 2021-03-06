#include <./headers/AllLibraries.h>
#include <./headers/Constants.h>
#include <./headers/Pathes.cpp>

//пользовательские файлы
#include "./headers/ObjectInfo.h"
#include "./headers/MyView.h"

#include "./headers/staticWorld/StaticElement.cpp"
#include "./headers/staticWorld/Borders.cpp"
#include "./headers/staticWorld/Floor.cpp"
#include "./headers/staticWorld/Wall.cpp"
#include "./headers/staticWorld/Staircase.cpp"
#include "./headers/UserCharacter/CharacterStatic.cpp"
#include "./headers/MyContactListener.cpp"

int main(int argc, char** argv) {
    //создание box2d мира
    b2Vec2 gravity(0.0f, GRAVITY);
    b2World world(gravity);

    //создание qt мира
    B2_NOT_USED(argc);
    B2_NOT_USED(argv);
    QApplication a(argc,argv);
    QGraphicsScene* scene= new QGraphicsScene(0, 0, worldWidth, worldHeight);
    MyView view;

    QPixmap pict(generatePath(PATH_PROJECT, PATH_BACKGROUND, F_BACKGROUND));
    view.setBackgroundBrush(QBrush(pict));

    //заполнение статикой
    Staircase *staircase1 = new StaircaseLarge(&world, 50, 240);
    staircase1->render(scene);
    Staircase *staircase2 = new StaircaseMedium(&world, 150, 405);
    staircase2->render(scene);
    Staircase *staircase3 = new StaircaseSmall(&world, 310, 430);
    staircase3->render(scene);
    Staircase *staircase4 = new StaircaseXlarge(&world, 490, 330);
    staircase4->render(scene);
    Staircase *staircase5 = new StaircaseMedium(&world, 650, 205);
    staircase5->render(scene);
    Staircase *staircase6 = new StaircaseLarge(&world, 770, 380);
    staircase6->render(scene);

    Floor *floor1 = new Floor(&world, 30, 350, 100);
    floor1->render(scene);
    Floor *floor2 = new Floor(&world, 90, 150, 120);
    floor2->render(scene);
    Floor *floor3 = new Floor(&world, 190, 350, 80);
    floor3->render(scene);
    Floor *floor4 = new Floor(&world, 350, 390, 40);
    floor4->render(scene);
    Floor *floor5 = new Floor(&world, 350, 170, 40);
    floor5->render(scene);
    Floor *floor6 = new Floor(&world, 390, 190, 80);
    floor6->render(scene);
    Floor *floor7 = new Floor(&world, 390, 330, 60);
    floor7->render(scene);
    Floor *floor8 = new Floor(&world, 530, 130, 40);
    floor8->render(scene);
    Floor *floor9 = new Floor(&world, 530, 390, 80);
    floor9->render(scene);
    Floor *floor10 = new Floor(&world, 610, 290, 140);
    floor10->render(scene);
    Floor *floor11 = new Floor(&world, 690, 150, 60);
    floor11->render(scene);
    Floor *floor12 = new Floor(&world, 750, 110, 180);
    floor12->render(scene);
    Floor *floor13 = new Floor(&world, 930, 250, 60);
    floor13->render(scene);

    Wall *wall1 = new Wall(&world, 270, 170, 200);
    wall1->render(scene);
    Wall *wall2 = new Wall(&world, 450, 310, 180);
    wall2->render(scene);
    Wall *wall3 = new Wall(&world, 530, 330, 60);
    wall3->render(scene);
    Wall *wall4 = new Wall(&world, 610, 130, 60);
    wall4->render(scene);
    Wall *wall5 = new Wall(&world, 810, 130, 140);
    wall5->render(scene);
    Character *character1 = new Character(&world, 205, 270);
    scene->addItem(character1);
    Borders *borders = new Borders(&world, worldWidth, worldHeight);
    borders->render(scene);
    //QMatrix matrix(0.5, 0, 0, 0.5, 0, 0);
    //view.setMatrix(matrix);
    MyContactListener *contact = new MyContactListener();
    world.SetContactListener(contact);

    view.setMouseTracking(true);
    view.setScene(scene);
    view.show();
    QTimer* qtime =new QTimer();
    qtime->setInterval(60);
    qtime->start();
    QObject::connect(qtime, SIGNAL(timeout()), scene, SLOT(advance()));
    return a.exec();
}


