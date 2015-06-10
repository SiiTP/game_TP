#ifndef LOGIC_H
#define LOGIC_H
struct Characteristics;
class Logic {
public:
    virtual void pressW(Characteristics*) = 0;
    virtual void pressS(Characteristics*) = 0;
    virtual void pressA(Characteristics*) = 0;
    virtual void pressD(Characteristics*) = 0;
    virtual void action(Characteristics*) = 0;
    virtual void pressWend(Characteristics*) = 0;
    virtual void pressSend(Characteristics*) = 0;
    virtual void pressAend(Characteristics*) = 0;
    virtual void pressDend(Characteristics*) = 0;
    Logic() {}
};
class LogicInFloor : public Logic {
public:
    LogicInFloor() : Logic() {}
    void pressW(Characteristics*);
    void pressS(Characteristics*);
    void pressA(Characteristics*);
    void pressD(Characteristics*);
    void action(Characteristics*);

    void pressWend(Characteristics*);
    void pressSend(Characteristics*);
    void pressAend(Characteristics*);
    void pressDend(Characteristics*);
};
class LogicInStaircase : public Logic {
public:
    LogicInStaircase() : Logic() {}
    void pressW(Characteristics*);
    void pressS(Characteristics*);
    void pressA(Characteristics*);
    void pressD(Characteristics*);
    void action(Characteristics*);

    void pressWend(Characteristics*);
    void pressSend(Characteristics*);
    void pressAend(Characteristics*);
    void pressDend(Characteristics*);
};
class LogicInFlight : public Logic {
public:
    LogicInFlight() : Logic() {}
    void pressW(Characteristics*);
    void pressS(Characteristics*);
    void pressA(Characteristics*);
    void pressD(Characteristics*);
    void action(Characteristics*);

    void pressWend(Characteristics*);
    void pressSend(Characteristics*);
    void pressAend(Characteristics*);
    void pressDend(Characteristics*);
};
#endif // LOGIC_H

