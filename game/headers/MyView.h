class MyView: public QGraphicsView {
public:
    void mousePressEvent(QMouseEvent *event){
       std::cout << event->x() << ' ' << event->y() << std::endl;
    }
};
