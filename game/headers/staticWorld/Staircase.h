//класс лестниц
//высоты лестниц
#define STAIRCASE_SMALL_HEIGHT  100.0f
#define STAIRCASE_MEDIUM_HEIGHT 150.0f
#define STAIRCASE_LARGE_HEIGHT  200.0f
#define STAIRCASE_XLARGE_HEIGHT 300.0f

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
    static const float MetrKoefficient = 30.0f;

    Staircase(b2World *world, float x, float y, float height) {
        this->x = x;
        this->y = y;
        this->height = height;

        //определение тела
        b2BodyDef *staircaseDef = new b2BodyDef();
        staircaseDef->position.Set(-x / MetrKoefficient, -y / MetrKoefficient);
        setPos(x, y); //отрисовка будет осуществляться в этой позиции

        //оболочка
        b2PolygonShape *staircaseShape = new b2PolygonShape();
        staircaseShape->SetAsBox(width / MetrKoefficient / 2, height / MetrKoefficient / 2);

        //физические свойства
        b2FixtureDef *stairCaseFixt = new b2FixtureDef();
        stairCaseFixt->shape = staircaseShape;
        stairCaseFixt->friction = 0.9;
        stairCaseFixt->density  = 1;

        //добавление в мир
        staircasePolygon = world->CreateBody(staircaseDef);
        staircasePolygon->CreateFixture(stairCaseFixt);

        setBrush(QBrush(QColor(Qt::cyan)));
        setRect(-width / 2 - 4, -height / 2 - 4, width + 6, height + 6);
    }
};


class StaircaseSmall : public Staircase{
public:
    StaircaseSmall(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_SMALL_HEIGHT) {
    }
    void render(QGraphicsScene *scene) {
        scene->addItem(this);
        QGraphicsPixmapItem *staircasePicture = scene->addPixmap(QPixmap("/home/ivan/TP_GameProject_CPP/project_sprites/staircase_small.png"));
        staircasePicture->setPos(x - width / 2, y - height / 2);
    }
};

class StaircaseMedium : public Staircase{
public:
    StaircaseMedium(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_MEDIUM_HEIGHT) {
    }
    void render(QGraphicsScene *scene) {
        scene->addItem(this);
        QGraphicsPixmapItem *staircasePicture =
                scene->addPixmap(QPixmap("/home/ivan/TP_GameProject_CPP/project_sprites/staircase_medium.png"));
        staircasePicture->setPos(x - width / 2, y - height / 2);
    }
};

class StaircaseLarge : public Staircase{
public:
    StaircaseLarge(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_LARGE_HEIGHT) {
    }
    void render(QGraphicsScene *scene) {
        scene->addItem(this);
        QGraphicsPixmapItem *staircasePicture =
                scene->addPixmap(QPixmap("/home/ivan/TP_GameProject_CPP/project_sprites/staircase_large.png"));
        staircasePicture->setPos(x - width / 2, y - height / 2);
    }
};

class StaircaseXlarge : public Staircase{
public:
    StaircaseXlarge(b2World *world, float x, float y) :
    Staircase(world, x, y, STAIRCASE_XLARGE_HEIGHT) {
    }
    void render(QGraphicsScene *scene) {
        scene->addItem(this);
        QGraphicsPixmapItem *staircasePicture =
                scene->addPixmap(QPixmap("/home/ivan/TP_GameProject_CPP/project_sprites/staircase_xlarge.png"));
        staircasePicture->setPos(x - width / 2, y - height / 2);
    }
};
