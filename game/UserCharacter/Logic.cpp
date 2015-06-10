#include "headers/UserCharacter/CharacterStatic.h"
#include "headers/UserCharacter/Logic.h"
#include <iostream>
using std::cout;

void LogicInFloor::pressW(Characteristics *charact) {
    cout << "Press W in FLOOR\n";
    cout << "character is dynamic body\n";
    charact->body->SetType(b2_dynamicBody);
    charact->bv.x = charact->body->GetLinearVelocity().x;
    charact->bv.y = 0;
    charact->body->SetLinearVelocity(charact->bv);
    charact->body->ApplyLinearImpulse(b2Vec2(0, 6.0f * charact->jumpPower),charact->body->GetWorldCenter(),true);
}
void LogicInFloor::pressS(Characteristics *charact) {
    cout << "Press S in FLOOR\n";
}
void LogicInFloor::pressA(Characteristics *charact) {
    cout << "Press A in FLOOR\n";
    charact->bv.x = 6.0f * charact->speed;
    charact->body->SetLinearVelocity(charact->bv);
}
void LogicInFloor::pressD(Characteristics *charact) {
    cout << "Press D in FLOOR\n";
    charact->bv.x = -6.0f * charact->speed;
    charact->body->SetLinearVelocity(charact->bv);
}
void LogicInFloor::action(Characteristics *charact) {

}
void LogicInFloor::pressWend(Characteristics *charact) {
    cout << "UNPress W in FLOOR\n";
}
void LogicInFloor::pressSend(Characteristics *charact) {
    cout << "UNPress S in FLOOR\n";
}
void LogicInFloor::pressAend(Characteristics *charact) {
    cout << "UNPress A in FLOOR\n";
    charact->bv.x = 0;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
    charact->bv.y = 0;
}
void LogicInFloor::pressDend(Characteristics *charact) {
    cout << "UNPress D in FLOOR\n";
    charact->bv.x = 0;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
    charact->bv.y = 0;
}

void LogicInStaircase::pressW(Characteristics *charact) {
    cout << "Press W in STAIRCASE\n";
    //charact->body->SetType(b2_kinematicBody);
    charact->body->SetLinearVelocity(b2Vec2(charact->body->GetLinearVelocity().x, 3 * charact->jumpPower));
}
void LogicInStaircase::pressS(Characteristics *charact) {
    cout << "Press S in STAIRCASE\n";
    //charact->body->SetType(b2_kinematicBody);
    charact->body->SetLinearVelocity(b2Vec2(charact->body->GetLinearVelocity().x, -3 * charact->jumpPower));
}
void LogicInStaircase::pressA(Characteristics *charact) {
    cout << "Press A in STAIRCASE\n";
    charact->bv.x = 6.0f * charact->speed;
    charact->body->SetLinearVelocity(charact->bv);
}
void LogicInStaircase::pressD(Characteristics *charact) {
    cout << "Press D in STAIRCASE\n";
    charact->bv.x = -6.0f * charact->speed;
    charact->body->SetLinearVelocity(charact->bv);
}
void LogicInStaircase::action(Characteristics *charact) {

}
void LogicInStaircase::pressWend(Characteristics *charact) {
    cout << "UNPress W in Staircase\n";
}
void LogicInStaircase::pressSend(Characteristics *charact) {
    cout << "UNPress S in Staircase\n";
}
void LogicInStaircase::pressAend(Characteristics *charact) {
    cout << "UNPress A in Staircase\n";
    charact->bv.x = 0;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
    charact->bv.y = 0;
}
void LogicInStaircase::pressDend(Characteristics *charact) {
    cout << "UNPress D in Staircase\n";
    charact->bv.x = 0;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
    charact->bv.y = 0;
}

void LogicInFlight::pressW(Characteristics *charact) {
    cout << "Press W in FLIGHT\n";
    charact->body->SetType(b2_dynamicBody);
}
void LogicInFlight::pressS(Characteristics *charact) {
    cout << "Press S in FLIGHT\n";
    charact->body->SetType(b2_dynamicBody);
}
void LogicInFlight::pressA(Characteristics *charact) {
    cout << "Press A in FLIGHT\n";
    charact->bv.x = 1.5f * charact->speed;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
}
void LogicInFlight::pressD(Characteristics *charact) {
    cout << "Press D in FLIGHT\n";
    charact->bv.x = -1.5f * charact->speed;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
}
void LogicInFlight::action(Characteristics *charact) {

}
void LogicInFlight::pressWend(Characteristics *charact) {
    cout << "UNPress W in Flight\n";
}
void LogicInFlight::pressSend(Characteristics *charact) {
    cout << "UNPress S in Flight\n";
}
void LogicInFlight::pressAend(Characteristics *charact) {
    cout << "UNPress A in Flight\n";
    charact->bv.x = 0;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
    charact->bv.y = 0;
}
void LogicInFlight::pressDend(Characteristics *charact) {
    cout << "UNPress D in Flight\n";
    charact->bv.x = 0;
    charact->bv.y = charact->body->GetLinearVelocity().y;
    charact->body->SetLinearVelocity(charact->bv);
    charact->bv.y = 0;
}

