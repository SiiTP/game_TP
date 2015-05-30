#ifndef WEAPONPROTOTYPE_H
#define WEAPONPROTOTYPE_H

#endif // WEAPONPROTOTYPE_H


class EquipmentFactory {
public:
    virtual Equipment* create() =0;
};
class GunFactory:public EquipmentFactory{
public:
    GunFactory() {}
    Gun* create() {
        return new Gun();
    }
};

