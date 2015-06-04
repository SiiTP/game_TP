class Floor : public StaticElement {
public:
    Floor(b2World *world, float beginX, float beginY, float length);
private:
    float beginX;
    float beginY;
    float length;
};
