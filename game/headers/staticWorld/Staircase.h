//класс лестниц
//высоты лестниц
#define STAIRCASE_SMALL_HEIGHT  100.0f
#define STAIRCASE_MEDIUM_HEIGHT 150.0f
#define STAIRCASE_LARGE_HEIGHT  200.0f
#define STAIRCASE_XLARGE_HEIGHT 300.0f

#include <Box2D/Box2D.h>

class Staircase : public QGraphicsRectItem {
public:
    virtual void render(QGraphicsScene *) = 0;
protected:

    float const width = 60.0f;
    float height;
    float x;
    float y;
    b2Body *staircasePolygon;
    QGraphicsPixmapItem *staircasePicture;
    static constexpr float MetrKoefficient = 50.0f;
    Staircase(b2World *world, float x, float y, float height);
};


class StaircaseSmall : public Staircase{
public:
    StaircaseSmall(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_SMALL_HEIGHT) {}
    void render(QGraphicsScene *scene) ;
};

class StaircaseMedium : public Staircase{
public:
    StaircaseMedium(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_MEDIUM_HEIGHT) {}
    void render(QGraphicsScene *scene) ;
};

class StaircaseLarge : public Staircase{
public:
    StaircaseLarge(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_LARGE_HEIGHT) {}
    void render(QGraphicsScene *scene);
};

class StaircaseXlarge : public Staircase{
public:
    StaircaseXlarge(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_XLARGE_HEIGHT) {}
    void render(QGraphicsScene *scene);
};
