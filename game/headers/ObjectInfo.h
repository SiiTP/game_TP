class ObjectInfo {
public:
    string objectType;
    bool isStaircase;
    bool isCube;
    bool isCharacter;
    bool characterInStaircase;
    ObjectInfo(string str) {
        objectType = str;
        isStaircase = false;
        isCube = false;
        isCharacter = false;
        characterInStaircase = false;
    }
};
