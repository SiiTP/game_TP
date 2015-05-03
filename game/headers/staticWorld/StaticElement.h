class StaticElement {
protected:
    std::vector<StaticCube*> cubes;
public:
    void render(QGraphicsScene *scene) {
        for (size_t i = 0; i < cubes.size(); ++i) {
            scene->addItem(cubes[i]);
        }
    }
    // ~StaticElement() {}; //делает класс абстрактным
};
