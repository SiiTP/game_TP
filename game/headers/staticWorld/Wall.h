#include "./headers/staticWorld/StaticElement.h"

class Wall : public StaticElement {
public:
    Wall(b2World *world, float beginX, float beginY, float height);
private:
    float beginX;
    float beginY;
    float height;
};
