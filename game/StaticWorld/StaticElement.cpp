//тандартные библиотеки
#include <iostream>

using std::string;
using std::cout;

//библиотеки от QT
#include <QGraphicsRectItem>

#include <QGraphicsScene>




//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "./headers/ObjectInfo.h"
#include "./headers/UserCharacter/Box2dRect.h"
#include "./headers/staticWorld/StaticCube.h"
#include "./headers/staticWorld/StaticElement.h"

extern QString path;
void StaticElement::render(QGraphicsScene *scene) {
    for (size_t i = 0; i < cubes.size(); ++i) {
        float size = cubes[i]->getSize();
        float x = cubes[i]->getX();
        float y = cubes[i]->getY();
        QGraphicsPixmapItem *buf = cubes[i]->getCubePicture();

        buf = scene->addPixmap(QPixmap(path+"/project_sprites/walls/cube1_20px"));
        buf->setPos(x - size / 2,y - size / 2);
        //std::swap(buf, cubes[i]->getCubePicture());
        //scene->addItem(cubes[i]);
    }
}
StaticElement::~StaticElement() {
    for(int i = 0; i< cubes.size(); ++i) {
        delete cubes[i];
    }
}
