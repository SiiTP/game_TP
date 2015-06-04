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
#include "./headers/ObjectInfo.h"
#include "./headers/UserCharacter/Box2dRect.h"
#include "./headers/Weapons/weapon.h"
#include "./headers/Weapons/WeaponFactory.h"
#include "./headers/UserCharacter/CharacterStatic.h"
#include "./headers/MyContactListener.h"

void MyContactListener::BeginContact(b2Contact *contact) {
   b2Fixture *objA = contact->GetFixtureA();
   b2Fixture *objB = contact->GetFixtureB();
   ObjectInfo *infoA = (ObjectInfo*)objA->GetUserData();
   ObjectInfo *infoB = (ObjectInfo*)objB->GetUserData();

   //лестницы создавались раньше персонажа, поэтому лестница - всегда объект А, позже сделаю полноценную проверку
   if (infoA->isStaircase && infoB->isCharacter) {
       cout << "collision staircase + character\n";

       //эхо печать, кстати по фикстуру можно само тело получать__________________
       b2Body *body1 = objA->GetBody();
       const b2Vec2 vec1 = body1->GetPosition();
       cout << "staircasePosition : (" << vec1.x * 50 << " : " << vec1.y * 50 << ")\n";
       b2Body *body2 = objB->GetBody();
       const b2Vec2 vec2 = body2->GetPosition();
       cout << "CharacterPosition : (" << vec2.x * 50 << " : " << vec2.y * 50 << ")\n";
       //_________________________________________________________________________

       infoB->characterInStaircase = true;

   }
}

void MyContactListener::EndContact(b2Contact *contact) {
    //cout << "End contact" << endl;
    b2Fixture *objA = contact->GetFixtureA();
    b2Fixture *objB = contact->GetFixtureB();
    ObjectInfo *infoA = (ObjectInfo*)objA->GetUserData();
    ObjectInfo *infoB = (ObjectInfo*)objB->GetUserData();
    //cout << "type of object A : " << infoA->objectType << endl;
    //cout << "type of object B : " << infoB->objectType << endl;
    if (infoA->isStaircase && infoB->isCharacter) {
        cout << "END collision staircase + character\n";
        b2Body *body1 = objA->GetBody();
        const b2Vec2 vec1 = body1->GetPosition();
        cout << "staircasePosition : (" << vec1.x * 50 << " : " << vec1.y * 50 << ")\n";
        b2Body *body2 = objB->GetBody();
        const b2Vec2 vec2 = body2->GetPosition();
        cout << "CharacterPosition : (" << vec2.x * 50 << " : " << vec2.y * 50 << ")\n";
        infoB->characterInStaircase = false;
    }
}
