#include "../ProjectPath.h"
class StaticElement {

public:
    void render(QGraphicsScene *scene);
protected:
    std::vector<StaticCube*> cubes;
    // ~StaticElement() {}; //делает класс абстрактным
};
