#ifndef USERSINGLTON_H
#define USERSINGLTON_H

#endif // USERSINGLTON_H
#include "CharacterStatic.h"


class MainUser {
public:
    static Character* getuser(){
        if(user == NULL) {
            user = new Character(&world, 205, 270);
        }
    }
private:
    MainUser() {}
    Character* user;
};
