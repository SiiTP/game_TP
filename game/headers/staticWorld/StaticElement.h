#include "../ProjectPath.h"
class StaticElement {

public:
    void render(QGraphicsScene *scene);
    virtual ~StaticElement();
protected:
    std::vector<StaticCube*> cubes;
    // ~StaticElement() {}; //делает класс абстрактным
};
