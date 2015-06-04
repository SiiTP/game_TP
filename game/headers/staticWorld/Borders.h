#include "headers/staticWorld/StaticElement.h"

class Borders : public StaticElement {
public:
    Borders(b2World *world, float width, float height);
    //~Borders() {};
private:
    float widthBorders;
    float heightBorders;
};
