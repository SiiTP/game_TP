//простой кубик
class StaticCube : public QGraphicsRectItem {
    public:
        static const float MetrKoefficient = 30.0f;
        b2Body *cubeBody;
        StaticCube(b2World *world, float x, float y) {

            //определение тела
            b2BodyDef *cubeDef = new b2BodyDef();
            cubeDef->position.Set(-x / MetrKoefficient, -y / MetrKoefficient);
            setPos(x, y); //отрисовка будет осуществляться в этой позиции

            //оболочка
            b2PolygonShape *cubeShape = new b2PolygonShape();
            cubeShape->SetAsBox(size / MetrKoefficient / 2, size / MetrKoefficient / 2);

            //физические свойства
            b2FixtureDef *cubeFixt = new b2FixtureDef();
            cubeFixt->shape = cubeShape;
            cubeFixt->friction = 0.9;
            cubeFixt->density  = 1;

            //добавление в мир
            cubeBody = world->CreateBody(cubeDef);
            cubeBody->CreateFixture(cubeFixt);

            setBrush(QBrush(QColor(Qt::red)));

            setRect(-size / 2, -size / 2, size, size); //отрисовка, начало сдвигаем в левый верхний угол
        }

        StaticCube(){};

        static float getSize() {
            return size;
        }
        static float getReverseSize() {
            return 1.0f / size;
        }
private:
        static const float size = 10;
};

