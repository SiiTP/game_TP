class StaticElement {

public:
    void render(QGraphicsScene *scene) {
        for (size_t i = 0; i < cubes.size(); ++i) {
            float size = cubes[i]->getSize();
            float x = cubes[i]->getX();
            float y = cubes[i]->getY();
            QGraphicsPixmapItem *buf = cubes[i]->getCubePicture();
            buf = scene->addPixmap(QPixmap("/home/ivan/QTProjects/TPproject/project_sprites/walls/cube1_20px"));
            buf->setPos(x - size / 2,y - size / 2);
            //std::swap(buf, cubes[i]->getCubePicture());
            //scene->addItem(cubes[i]);
        }
    }
protected:
    std::vector<StaticCube*> cubes;
    // ~StaticElement() {}; //делает класс абстрактным
};
