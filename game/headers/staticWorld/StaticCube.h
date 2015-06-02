//простой кубик
#include <memory>
using std::shared_ptr;
class ObjectInfo;
class StaticCube : public QGraphicsRectItem {
    public:
        StaticCube(b2World *world, float x, float y) ;

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
        static constexpr float MetrKoefficient = 50.0f;
        b2Body *cubeBody;
        QGraphicsPixmapItem *cubePicture;
        static constexpr float size = 20;
        shared_ptr<ObjectInfo> info;
};


