class Borders : public StaticElement {
public:
    Borders(b2World *world, float width, float height) {
        widthBorders = width;
        heightBorders = height;
        StaticCube *a;
        float size = a->getSize();
        float revSize = a->getReverseSize();
        //заполнение идет по часовой стрелке с начала координат
        for (int i = 0; i < width * revSize - 1; ++i) {
            //upBorder
            cubes.push_back(new StaticCube(world,   size * i + size / 2,   size / 2           ));
        }
        for (int i = 1; i < height * revSize - 1; ++i) {
            //rightBorder
            cubes.push_back(new StaticCube(world,   width - size / 2,      size * i + size / 2));
        }
        for (int i = width * revSize - 2; i >= 0; --i) {
            //downBorder
            cubes.push_back(new StaticCube(world,   size * i + size / 2,   height - size / 2  ));
        }
        for (int i = height * revSize - 2; i > 0 ; --i) {
            //leftBorder
            cubes.push_back(new StaticCube(world,   size / 2,              size * i + size / 2));
        }
    }
    //~Borders() {};
private:
    float widthBorders;
    float heightBorders;
};
