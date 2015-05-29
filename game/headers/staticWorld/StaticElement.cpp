#include "./headers/staticWorld/StaticCube.cpp"
#include "./headers/AllLibraries.h"

class StaticElement {
protected:
    std::vector<StaticCube*> cubes;
public:
    void render(QGraphicsScene *scene) {
        for (size_t i = 0; i < cubes.size(); ++i) {
            float size = cubes[i]->getSize();
            float x = cubes[i]->getX();
            float y = cubes[i]->getY();
            QGraphicsPixmapItem *buf = cubes[i]->getCubePicture();
            buf = scene->addPixmap(QPixmap(generatePath(PATH_PROJECT, PATH_CUBE, F_CUBE2)));
            buf->setPos(x - size / 2,y - size / 2);
        }
    }
};
