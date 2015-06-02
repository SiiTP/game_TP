
class MyView: public QGraphicsView {
public:
    void mousePressEvent(QMouseEvent *event){
      //std::cout << event->x() << ' ' << event->y() << std::endl;
       if (user != NULL) {
          user.get()->attack(event->x(),event->y(),scene());
       }
       if (user->hasFocus() != true) {
           user.get()->setFocus();
       }
    }
    void setUser(shared_ptr<Character> c) {
        user = c;
    }
private:
    shared_ptr<Character> user;
};
