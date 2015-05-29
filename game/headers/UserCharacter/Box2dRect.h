 #define RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) / M_PI * 180.0)
const float SCALETOPIXEL = 50;
//const float32 timeStep = 1.0f/60.0f;

const int32 velocityIterations = 6;
const int32 positionIterations = 2;
using namespace std;
class MyRect : public QGraphicsRectItem {
public:
    //это userData
    ObjectInfo *info = new ObjectInfo("character");

    MyRect(b2World* world) {
    }
    MyRect(b2World* world,float width,float height, float x ,float y,string name, bool isstatic = false) {
        this->name = name;
        this->world = world;
        b2BodyDef bodyDef;
        if (!isstatic) {
            bodyDef.type = b2_dynamicBody;
        }
        float yy = y/SCALETOPIXEL;
        float xx = x/SCALETOPIXEL;
        bodyDef.position.Set(-xx,-yy);
        bodyDef.fixedRotation = true; //отключение вращения
        setPos(x,y);
        b2Body* body = world->CreateBody(&bodyDef);
        this->body = body;
        b2PolygonShape dynamicBox;
        yy = height/SCALETOPIXEL/2;
        xx = width/SCALETOPIXEL/2;
        dynamicBox.SetAsBox(xx,yy);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.5f;
        //для обработки столкновений
        info->isCharacter = true;
        fixtureDef.userData = info;
        //__________________________

        body->CreateFixture(&fixtureDef);
        setBrush(QBrush(QColor(Qt::gray)));
        setRect(-width/2,-height/2,width,height);
        setAcceptHoverEvents(true);
    }

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event){

    }
    void advance(int phase){
        if (!phase) return;

        world->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();

        setPos(-position.x*SCALETOPIXEL,-position.y*SCALETOPIXEL);
    }
protected:
    b2Body* body;
private:
    int xx,yy;

    b2World* world;

    string name;
    bool isStatic = false;
};
