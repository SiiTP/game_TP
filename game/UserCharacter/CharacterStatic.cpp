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
       if (info->getCharacterInStaircase()) {
           strategyOfAdvance = new LogicInStaircase();
       } else {
           if (charact->body->GetLinearVelocity().y == 0) {
               strategyOfAdvance = new LogicInFloor();
           } else {
               strategyOfAdvance = new LogicInFlight();
           }
       }
       if (event->key() == 'S') { //движение вниз
           strategyOfAdvance->pressS(charact);
           /*if (info->getCharacterInStaircase() == true) {
               body->SetType(b2_kinematicBody);
               body->SetLinearVelocity(b2Vec2(0, -0.5 * impulsepower));
           }*/
       }
       if (event->key() == 'W') {
           strategyOfAdvance->pressW(charact);
           /*if (info->getCharacterInStaircase() == true) {
               cout << "character is kinematic body\n";
               body->SetType(b2_kinematicBody);
               body->SetLinearVelocity(b2Vec2(0, 0.5 * impulsepower)); //кинематике надо скорость задавать а не импульс
               //body->ApplyLinearImpulse(b2Vec2(0,impulsepower),body->GetWorldCenter(),true);
               charact->bv.x = 0;
           }
           else {

           }*/
       }

       if (event->key() == 'A') {
          strategyOfAdvance->pressA(charact);
          isLeftDirection = LEFT;
       }
       if (event->key() == 'D') {
          strategyOfAdvance->pressD(charact);
          isLeftDirection = RIGHT;
       }
       strategyOfAdvance->action(charact);
}

void Character::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {

}
void Character::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == 'S') {
        strategyOfAdvance->pressSend(charact);
    }
    if (event->key() == 'W') {
        strategyOfAdvance->pressWend(charact);
    }
    if (event->key() == 'A') {
        strategyOfAdvance->pressAend(charact);
    }
    if (event->key() == 'D') {
        strategyOfAdvance->pressDend(charact);
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
    spr.get()->setPos(x(),y());
    if (fabs(body->GetLinearVelocity().y)>precision && info -> getCharacterInStaircase() == false) {
        spr.get()->jump(isLeftDirection);
        //inflight = true;
    } else {
       //inflight = false;
        if (fabs(charact->bv.x) > 0) {
            //cout << bv.x << endl;
            spr.get()->move(isLeftDirection);
        } else {
            spr.get()->stand(isLeftDirection);
        }
    }

}
void Character::setWeapon(EquipmentFactory* fact) {
    factory = fact;
}
