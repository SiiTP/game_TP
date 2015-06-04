#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#endif // LEVELBUILDER_H
class LevelBuilder {
public:
    virtual void build(b2World *, shared_ptr<QGraphicsScene>) = 0;
private:
    virtual void buildBorders   (b2World *, std::shared_ptr<QGraphicsScene>) = 0;
    virtual void buildFloors    (b2World *, std::shared_ptr<QGraphicsScene>) = 0;
    virtual void buildWalls     (b2World *, std::shared_ptr<QGraphicsScene>) = 0;
    virtual void buildStaircases(b2World *, std::shared_ptr<QGraphicsScene>) = 0;
};

class LevelBuilder_1 : public LevelBuilder {
public:
    //LevelBuilder_1() {}
    //~LevelBuilder_1() {}
    void build(b2World *, shared_ptr<QGraphicsScene>);

private:
    void buildBorders   (b2World *world, std::shared_ptr<QGraphicsScene> scene);
    void buildFloors    (b2World *world, std::shared_ptr<QGraphicsScene> scene);
    void buildWalls     (b2World *world, std::shared_ptr<QGraphicsScene> scene);
    void buildStaircases(b2World *world, std::shared_ptr<QGraphicsScene> scene);
};
