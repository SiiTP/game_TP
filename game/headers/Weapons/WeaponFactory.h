#ifndef WEAPONPROTOTYPE_H
#define WEAPONPROTOTYPE_H
class EquipmentFactory {
public:
    int getMagazine() { return magazine;}
    int getDelay() { return attackdelay;}
    void setMagazine(unsigned int count) { magazine = count;}
    void setDelay(unsigned int delay) { attackdelay = delay;}
    virtual Equipment* create() =0;
private:
    int magazine;
    int attackdelay;
};
class GunFactory:public EquipmentFactory{
public:
    GunFactory(int magazine,int delay) { setMagazine(magazine); setDelay(delay);}
    Gun* create() {
        return new Gun();
    }
};
#endif // WEAPONPROTOTYPE_H




