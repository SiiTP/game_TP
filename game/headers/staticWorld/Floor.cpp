class Floor : public StaticElement {
public:
    Floor(b2World *world, float beginX, float beginY, float length) {
        this->beginX = beginX;
        this->beginY = beginY;
        this->length = length;
        StaticCube *a;
        float size = a->getSize();
        float amountOfCubes = length / size;
        for (int i = 0; i < amountOfCubes; ++i) {
            StaticCube *cube = new StaticCube(world, beginX + i * size, beginY);
            cubes.push_back(cube);
        }
    }
private:
    float beginX;
    float beginY;
    float length;
};
