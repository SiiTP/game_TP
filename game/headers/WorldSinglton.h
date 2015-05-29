#ifndef WORLDSINGLTON_H
#define WORLDSINGLTON_H

#endif // WORLDSINGLTON_H


class singleWorld {
public:
    static Character* getuser(){
        if(world == NULL) {
            b2Vec2 gravity(0.0f, -15.0f);
            world = new world(gravity);
        }
    }
private:
    singleWorld() {}
    std::shared_ptr<b2World* world;
};
