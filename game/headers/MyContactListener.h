#include <Box2D/Dynamics/Contacts/b2Contact.h>
/*template <class T1, class T2>
struct Same_types {
    enum {value = 0};
};
template <class T>
struct Same_types<T, T> {
    enum {value = 1};
//    Same_types(T type1, T type2) {
//        value = 1;
//    }

//    bool same_types() {
//        return value;
//    }
};*/

class MyContactListener : public b2ContactListener {
public:
void BeginContact(b2Contact *contact) {
   b2Fixture *objA = contact->GetFixtureA();
   b2Fixture *objB = contact->GetFixtureB();
   ObjectInfo *infoA = (ObjectInfo*)objA->GetUserData();
   ObjectInfo *infoB = (ObjectInfo*)objB->GetUserData();
   //cout << "type of object A : " << infoA->objectType << endl;
   //cout << "type of object B : " << infoB->objectType << endl;
   if (infoA->isStaircase && infoB->isCharacter) {
       cout << "collision staircase + character\n";
       b2Body *body1 = objA->GetBody();
       const b2Vec2 vec1 = body1->GetPosition();
       cout << "staircasePosition : (" << vec1.x * 50 << " : " << vec1.y * 50 << ")\n";
       b2Body *body2 = objB->GetBody();
       const b2Vec2 vec2 = body2->GetPosition();
       cout << "CharacterPosition : (" << vec2.x * 50 << " : " << vec2.y * 50 << ")\n";
       infoB->characterInStaircase = true;

   }

//    cout << "type of object A : " << (char *)objA->GetUserData() << endl;
//    cout << "type of object B : " << (char *)objB->GetUserData() << endl;
//   if (objA->IsSensor()) {
//       b2Body *charact = objB->GetBody();
//       charact->SetType(b2_kinematicBody);
//        cout << "contact with staircase\n";
//        charact->SetAwake(true);
//    }
}

void EndContact(b2Contact *contact) {
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
//    if ((char *)objA->GetUserData() == "staircase" && (char *)objB->GetUserData() == "character") {
//        b2Body *charact = objB->GetBody();
//        charact->SetType(b2_dynamicBody);
//    }
}
};
