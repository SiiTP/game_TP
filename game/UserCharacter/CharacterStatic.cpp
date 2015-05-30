//тандартные библиотеки
#include <iostream>

using std::string;
using std::cout;

//библиотеки от QT
#include <QGraphicsRectItem>




//библиотеки от box2D
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>

//пользовательские файлы
#include "../headers/ObjectInfo.h"
#include "../headers/UserCharacter/Box2dRect.h"
#include "../headers/Weapons/weapon.h"
#include "../headers/Weapons/WeaponFactory.h"
#include "../headers/UserCharacter/CharacterStatic.h"
extern QString path;
Sprite::Sprite(QGraphicsRectItem* item) : drawitem(item) {

    moveSpritesPath =path+"/project_sprites/sprite/NormalGear/";
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
void Sprite::move(bool isLeft) {
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

void Sprite::jump(bool isLeft) {
    if (qgp == NULL) {
        qgp = drawitem->scene()->addPixmap(jumpmap[0]);

    }
    if (isLeft == true) {
        qgp->setPixmap(jumpmap[0]);
    }else {
        qgp->setPixmap(jumpmap[1]);
    }
}

void Sprite::setPos(int x, int y) {
    if (qgp == NULL) {
        qgp = drawitem->scene()->addPixmap(def[0]);
    }
    qgp->setPos(x-20,y-40);
}
void Sprite::stand(bool isLeft) {
    if (qgp == NULL) {
        qgp = drawitem->scene()->addPixmap(def[0]);
    }
    if (isLeft == true) {
        qgp->setPixmap(def[0]);
    }else {
        qgp->setPixmap(def[1]);
    }
}
void Sprite::fire() {

}




void Character::keyPressEvent(QKeyEvent *event) {

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

void Character::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {

}
void Character::keyReleaseEvent(QKeyEvent *event) {
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


void Character::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    std::cout << event->pos().x() << ' ' << event->pos().y() << std::endl;
    setFocus();
}

void Character::attack(float x,float y,QGraphicsScene* scene) {
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

void Character::advance(int phase) {
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
void Character::setWeapon(EquipmentFactory* fact) {
    factory = fact;
}
