#include <Box2D/Dynamics/Contacts/b2Contact.h>

//попытка сравнивать типы через шаблоны, не удаляй пока
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
void BeginContact(b2Contact *contact) ;

void EndContact(b2Contact *contact) ;
};
