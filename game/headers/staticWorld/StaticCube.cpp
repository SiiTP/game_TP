//простой кубик
class StaticCube : public QGraphicsRectItem {
    public:
        StaticCube(b2World *world, float x, float y) {
            this->x = x;
            this->y = y;
            //определение тела
            b2BodyDef *cubeDef = new b2BodyDef();
            cubeDef->position.Set(-x / MetrKoefficient, -y / MetrKoefficient);
            setPos(x, y); //отрисовка будет осуществляться в этой позиции

            //оболочка
            b2PolygonShape cubeShape;
            cubeShape.SetAsBox(size / MetrKoefficient / 2, size / MetrKoefficient / 2);

            //физические свойства
            b2FixtureDef *cubeFixt = new b2FixtureDef();
            cubeFixt->shape = &cubeShape;
            cubeFixt->friction = 0.5f;
            cubeFixt->density  = 1.0f;

            //для обработки столкновений
            ObjectInfo *info = new ObjectInfo("cube");
            info->isCube = true;
            cubeFixt->userData = info;
            //__________________________

            //добавление в мир
            cubeBody = world->CreateBody(cubeDef);
            cubeBody->CreateFixture(cubeFixt);

            setBrush(QBrush(QColor(Qt::red)));

            setRect(-size / 2, -size / 2, size, size); //отрисовка, начало сдвигаем в левый верхний угол
        }

        StaticCube(){};

        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
        static float getSize() {
            return size;
        }
        static float getReverseSize() {
            return 1.0f / size;
        }
        QGraphicsPixmapItem* getCubePicture() {
            return cubePicture;
        }

private:
        float x;
        float y;
        static const float MetrKoefficient = 50.0f;
        b2Body *cubeBody;
        QGraphicsPixmapItem *cubePicture;
        static const float size = 20;
};


