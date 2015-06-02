#include "../ProjectPath.h"
class StaticElement {

public:
    void render(QGraphicsScene *scene);
    ~StaticElement();
protected:
    std::vector<StaticCube*> cubes;
    // ~StaticElement() {}; //делает класс абстрактным
};
