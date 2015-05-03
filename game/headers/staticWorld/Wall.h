class Wall : public StaticElement {
public:
    Wall(b2World *world, float beginX, float beginY, float height) {
        this->beginX = beginX;
        this->beginY = beginY;
        this->height = height;
        StaticCube *a;
        float size = a->getSize();
        float amountOfCubes = height / size;
        for (int i = 0; i < amountOfCubes; ++i) {
            StaticCube *cube = new StaticCube(world, beginX, beginY  + i * size);
            cubes.push_back(cube);
        }
    }
private:
    float beginX;
    float beginY;
    float height;
};
