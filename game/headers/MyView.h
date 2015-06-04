
class MyView: public QGraphicsView {
public:
    void mousePressEvent(QMouseEvent *event){
      //std::cout << event->x() << ' ' << event->y() << std::endl;
       if (user != NULL) {
          user->attack(event->x(),event->y(),scene());
       }
       if (user->hasFocus() != true) {
           user->setFocus();
       }
    }
    void setUser(Character* c) {
        user = c;
    }
private:
    Character* user;
};
