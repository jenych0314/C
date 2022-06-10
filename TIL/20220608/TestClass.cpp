//#include <iostream>
//#include <typeinfo>
//
//using namespace std;
//
//class Shape
//{
//protected:
//    int x, y;
//
//public:
//    void setOrigin(int _x, int _y)
//    {
//        this->x = _x;
//        this->y = _y;
//    }
//    void print()
//    {
//        cout << "Shape (" << x << ", " << y << ")" << endl;
//    }
//};
//
//class Rectangle : public Shape
//{
//private:
//    int width, height;
//
//public:
//    void setWidth(int w)
//    {
//        this->width = w;
//    }
//    void setHeight(int h)
//    {
//        this->height = h;
//    }
//    void print()
//    {
//        cout << "Rectangle (" << x << ", " << y << ")" << endl;
//    }
//};
//
//class Circle : public Shape
//{
//private:
//    int radius;
//
//public:
//    void setRadius(int r)
//    {
//        this->radius = r;
//    }
//    void print()
//    {
//        Shape::print();
//        cout << "Circle (" << radius << ")" << endl;
//    }
//    void move(Shape& s, int dx, int dy)
//    {
//        s.setOrigin(dx, dy);
//    }
//};
//
//int main()
//{
//    Rectangle r;
//    r.setOrigin(1, 1);
//    r.setWidth(3);
//    r.print();
//
//    Shape* ps;
//    cout << "type: " << typeid(ps).name() << endl;
//    ps = &r;
//    cout << "type: " << typeid(ps).name() << endl;
//    ps->setOrigin(10, 10);
//    ps->setWidth(100);
//    ps->print();
//    
//
//    Rectangle* pr;
//    cout << "type: " << typeid(pr).name() << endl;
//    pr = (Rectangle*)ps;
//    cout << "type: " << typeid(pr).name() << endl;
//    pr->setOrigin(8, 8);
//    pr->setWidth(16);
//    pr->print();
//
//    ((Circle*)ps)->setRadius(11);
//    cout << "type: " << typeid(ps).name() << endl;
//    ((Circle*)ps)->print();
//    pr->print();
//    cout << "type: " << typeid(pr).name() << endl;
//
//    Shape& rs = r;
//    cout << "type: " << typeid(rs).name() << endl;
//    rs.setOrigin(5, 5);
//    rs.setWidth(7);
//    rs.print();
//
//    Rectangle& rr = (Rectangle)rs;
//    cout << "type: " << typeid(rr).name() << endl;
//}