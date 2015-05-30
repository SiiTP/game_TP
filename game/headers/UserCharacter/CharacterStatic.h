
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <vector>
#include <QTimer>
#include <QDateTime>
#include <QDir>
#include <iostream>
#define LEFT 1
#define RIGHT 0

//спрайт персонажа
class Sprite {
public:
    Sprite(QGraphicsRectItem* item) : drawitem(item) {

        moveSpritesPath = "/home/ivan/QTProjects/TPproject/project_sprites/sprite/NormalGear/";
        QDir qd(moveSpritesPath);
        QStringList qls;

        qls.append("?.png");
        for (int i = 0 ; i< qd.entryList(qls).size(); ++i) {
            moveSpriteRight.push_back(QPixmap(moveSpritesPath+qd.entryList(qls)[i]));
        }

        qls[0] = "??.png";
        for (int i = 0 ; i< qd.entryList(qls).size(); ++i) {
            moveSpriteLeft.push_back(QPixmap(moveSpritesPath+qd.entryList(qls)[i]));
        }

        qls[0] = "d*.png";

        def[0] = QPixmap(moveSpritesPath+qd.entryList(qls)[0]);
        def[1] = QPixmap(moveSpritesPath+qd.entryList(qls)[1]);

        qls[0] = "j*.png";

        jumpmap[0] = QPixmap(moveSpritesPath+qd.entryList(qls)[0]);
        jumpmap[1] = QPixmap(moveSpritesPath+qd.entryList(qls)[1]);

        qgp = NULL;


    }

     void move(bool isLeft) {
            if (lastchange == 0) {
                lastchange = QDateTime::currentMSecsSinceEpoch();
            }
            else if ((QDateTime::currentMSecsSinceEpoch() -lastchange) > 40) {


            if (qgp == NULL) {
                qgp = drawitem->scene()->addPixmap(def[0]);

            }

            //qgp->setPos(drawitem->x()-20,drawitem->y()-40);
            if (isLeft == true) {
                qgp->setPixmap(moveSpriteLeft[currentFrame]);
            }
            else {
                qgp->setPixmap(moveSpriteRight[currentFrame]);
            }
            currentFrame++;

            if (currentFrame == 9 ) {
                currentFrame = 1;
            }
            lastchange = QDateTime::currentMSecsSinceEpoch();
        }

    }
    void jump(bool isLeft) {
        if (qgp == NULL) {
            qgp = drawitem->scene()->addPixmap(jumpmap[0]);

        }
        if (isLeft == true) {
            qgp->setPixmap(jumpmap[0]);
        }else {
            qgp->setPixmap(jumpmap[1]);
        }
    }
    void setPos(int x, int y) {
        if (qgp == NULL) {
            qgp = drawitem->scene()->addPixmap(def[0]);
        }
        qgp->setPos(x-20,y-40);
    }

    void stand(bool isLeft) {
        if (qgp == NULL) {
            qgp = drawitem->scene()->addPixmap(def[0]);
        }
        if (isLeft == true) {
            qgp->setPixmap(def[0]);
        }else {
            qgp->setPixmap(def[1]);
        }
    }
    void fire() {

    }

    ~Sprite() {
   }

private:
    QGraphicsRectItem* drawitem;

    int currentFrame = 1;

    std::vector<QPixmap> moveSpriteRight;
    std::vector<QPixmap> moveSpriteLeft;

    QPixmap def[2];
    QPixmap jumpmap[2];

    QGraphicsPixmapItem* qgp;
    QString moveSpritesPath;
    long lastchange = 0;


};


// Наследуется от класса, который рисует квадрат, что является основой персонажа,
// поверх чего рисуется спрайт
class Character: public MyRect{
public:
    Character(b2World* world,float x,float y) :MyRect(world,50,78,x,y,"character1") {
        setFlag(QGraphicsItem::ItemIsFocusable,true);
        setFocus();
        spr = new Sprite(this);
        factory= new GunFactory();
    }
    //обработка нажатия кнопок
     void keyPressEvent(QKeyEvent *event) {

        float32 impulsepower = 6.0f*jumpPower;
        if (inflight == false) {
            if (event->key() == 'S') { //движение вниз
                if (info->characterInStaircase == true) {
                    body->SetType(b2_kinematicBody);
                    body->SetLinearVelocity(b2Vec2(0, -0.5 * impulsepower));
                }
            }
            if (event->key() == 'W') {

                if (info->characterInStaircase == true) {
                    cout << "character is kinematic body\n";
                    body->SetType(b2_kinematicBody);
                    body->SetLinearVelocity(b2Vec2(0, 0.5 * impulsepower)); //кинематике надо скорость задавать а не импульс
                    //body->ApplyLinearImpulse(b2Vec2(0,impulsepower),body->GetWorldCenter(),true);
                    bv.x = 0;
                }
                else {
                    cout << "character is dynamic body\n";
                    body->SetType(b2_dynamicBody);
                    body->ApplyLinearImpulse(b2Vec2(0,impulsepower),body->GetWorldCenter(),true);
                    bv.x = 0;
                }

            }else {

                if (event->key() == 'A') {
                    bv.x = 6.0f*speed;
                    isLeftDirection = LEFT;
                    body->SetLinearVelocity(bv);
                }
                if (event->key() == 'D') {
                    isLeftDirection = RIGHT;
                    bv.x = -6.0f*speed;
                    body->SetLinearVelocity(bv);
                }
            }
        }
    }
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) {

    }
    //обработка отжатых кнопок
    void keyReleaseEvent(QKeyEvent *event) {
        switch (event->key()) {
            case 'D':
            case 'A':
                if (inflight == false) {
                    body->SetLinearVelocity(b2Vec2(0,body->GetLinearVelocity().y));
                    bv.x = 0;
                }
                break;
            case 'W':
                 break;
        }

    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event) {
        std::cout << event->pos().x() << ' ' << event->pos().y() << std::endl;
        setFocus();
    }
    //метод для стрельбы
    // х,у - координаты мыши,
    // сцена - куда отрисовывать
    void attack(float x,float y,QGraphicsScene* scene) {
        //std::cout << x << " " << y << std::endl;
        Equipment* eq = factory->create();
        float currentx = -body->GetWorldCenter().x*SCALETOPIXEL;
        if (isLeftDirection) {//shoot left/right
            currentx -= 25;
        }else {
            currentx += 25;
        }
        float currenty = -body->GetWorldCenter().y*SCALETOPIXEL - 20;//top left/right character


        eq->performAction(currentx,currenty,x+50,y,scene);//50 - offset for left mouse

    }
    //метод для обработки каждого кадра системы
    void advance(int phase) {
        MyRect::advance(phase);
        spr->setPos(x(),y());
        if (info -> characterInStaircase == false) {
            body->SetType(b2_dynamicBody); //если не на лестнице персонаж
        }
        if (fabs(body->GetLinearVelocity().y)>precision && info -> characterInStaircase == false) {
            spr->jump(isLeftDirection);
            inflight = true;
        }
        else {
            inflight = false;
            if (fabs(bv.x) > 0) {
                //cout << bv.x << endl;
                spr->move(isLeftDirection);
            }else {
                spr->stand(isLeftDirection);
            }
        }

    }
    //По дефолту в конструкторе Gun, установка фабрики для оружия
    void setWeapon(EquipmentFactory* fact) {
        factory = fact;
    }

private:
    static const float precision = 0.02;
    bool isLeftDirection;
    b2Vec2 bv;
    float speed = 1;
    bool inflight;
    float32 jumpPower = 1;
    Sprite* spr;
    EquipmentFactory* factory;
};





