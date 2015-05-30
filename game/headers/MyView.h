
class MyView: public QGraphicsView {
public:
    void mousePressEvent(QMouseEvent *event){
       std::cout << event->x() << ' ' << event->y() << std::endl;
       if (c != NULL) {
           c.attack(event->x(),event->y());
       }
    }
    void setUser(Character* c) {
        user = c;
    }
private:
    Character* user;
};
