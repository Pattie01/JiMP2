#include <iostream>
#include <ostream>
#include <cmath>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

class Point {
    double x_, y_;
public:
    Point();
    Point(double x, double y);
    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);
};

Point::Point():x_(0),y_(0){}

Point::Point(double x, double y){
    x_ = x;
    y_ = y;
}

Point::~Point(){}

double Point::GetX() const{return x_;}
double Point::GetY() const{return y_;}

void Point::SetX(double x){x_ = x;}
void Point::SetY(double y){y_ = y;}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

class Square{
    Point P1_, P2_, P3_, P4_;
public:
    Square();
    Square(Point P1, Point P2, Point P3, Point P4);
    double Circumference();
    double Area();
    ~Square();
};

Square::Square(){}

Square::Square(Point P1, Point P2, Point P3, Point P4) {
    P1_ = P1;
    P2_ = P2;
    P3_ = P3;
    P4_ = P4;
}
Square::~Square() {}

double Square::Circumference() {
    return P1_.Distance(P2_)*4;
}

double Square::Area() {
    return P1_.Distance(P2_)*P3_.Distance(P4_);
}

int main(){
    Point P1(1,1), P2(7,1), P3(7,7), P4(1,7);
    Square square(P1,P2,P3,P4);
    std::cout<<"Obwod kwadratu o podanych wspolrzednych wierzcholkow wynosi: "<<square.Circumference()<<std::endl;
    std::cout<<"Pole tego kwadratu jest rowne: "<<square.Area()<<std::endl;
    return 0;
}