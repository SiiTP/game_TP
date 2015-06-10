#pragma once
#include <memory>
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

#include "./headers/UserCharacter/Logic.h"
#include "./headers/ObjectInfo.h"
#include "./headers/UserCharacter/Box2dRect.h"
#include "./headers/Weapons/weapon.h"
#include "./headers/Weapons/WeaponFactory.h"

#define LEFT 1
#define RIGHT 0

using std::shared_ptr;

struct Characteristics {
    b2Body *body;
    b2Vec2 bv;
    float speed = 1;
    float32 jumpPower = 1;

};
//спрайт персонажа
//На входе дается квадрат персонажа, поверх которого орисовывается спрайт
//Персонаж на действия пользователя вызывает методы спрайта, который сам определяет как отрисовывать
class Sprite {
public:
    Sprite(QGraphicsRectItem* item);

     void move(bool isLeft);
    void jump(bool isLeft) ;
    void setPos(int x, int y);

    void stand(bool isLeft);
    void fire() ;

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
    long long lastchange = 0;


};


// Наследуется от класса, который рисует квадрат, что является основой персонажа,
// поверх чего рисуется спрайт
//Pattern: Adapter ??
//?Для выстрела необходимо положение персонажа+ положение мыши
//?Метод attack принимает положение мыши + сцену, куда рисовать, затем
//?высчитывает свои координаты и передает в класс оружия
class Character: public MyRect{
public:
    Character(b2World* world,float x,float y) :MyRect(world,50,78,x,y,"character1") {
        setFlag(QGraphicsItem::ItemIsFocusable,true);
        setFocus();
        spr = shared_ptr<Sprite>(new Sprite(this));
        factory= new GunFactory(1,1);
        charact = new Characteristics();
        charact->body = this->body;
        charact->jumpPower = 1;
        charact->speed = 1;
        strategyOfAdvance = new LogicInFlight();
    }
    //обработка нажатия кнопок
     void keyPressEvent(QKeyEvent *event);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    //обработка отжатых кнопок
    void keyReleaseEvent(QKeyEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //метод для стрельбы
    // х,у - координаты мыши,
    // сцена - куда отрисовывать
    void attack(float x,float y,QGraphicsScene* scene);
    //метод для обработки каждого кадра системы
    void advance(int phase);
    //По дефолту в конструкторе Gun, установка фабрики для оружия
    void setWeapon(EquipmentFactory* fact);

private:
    static constexpr float precision = 0.02;
    bool isLeftDirection;
    bool inflight;
    shared_ptr<Sprite> spr;
    EquipmentFactory* factory;
    Characteristics *charact;
    Logic *strategyOfAdvance;
};





