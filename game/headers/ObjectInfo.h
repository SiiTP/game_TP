#pragma once
#include <string>
using std::string;
class ObjectInfo {
public:
    ObjectInfo(string str) {
        objectType = str;
        isStaircase = false;
        isCube = false;
        isCharacter = false;
        characterInStaircase = false;
    }
    bool getIsStaircase() {
        return isStaircase;
    }
    bool getIsCube() {
        return isCube;
    }
    bool getIsCharacter() {
        return isCharacter;
    }
    bool getCharacterInStaircase() {
        return characterInStaircase;
    }

    void setIsStaircase(bool v) {
        isStaircase = v;
    }
    void setIsCube(bool v) {
        isCube = v;
    }
    void setIsCharacter(bool v) {
        isCharacter = v;
    }
    void setCharacterInStaircase(bool v) {
        characterInStaircase = v;
    }
private:
    string objectType;
    bool isStaircase;
    bool isCube;
    bool isCharacter;
    bool characterInStaircase;

};
