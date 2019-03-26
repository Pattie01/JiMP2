#include <iostream>
#include <ostream>
#include <cmath>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

class Point {
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
private:
    double x_, y_;
};

Point::Point():x_(0),y_(0){std::cout << "Konstruktor bezparametrowy" << std::endl;}

Point::Point(double x, double y){
    std::cout << "Konstruktor parametrowy" << std::endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){std::cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!" << std::endl;}

double Point::GetX() const{return x_;}
double Point::GetY() const{return y_;}

void Point::SetX(double x){x_ = x;}
void Point::SetY(double y){y_ = y;}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{(*out) << "(" << GetX() << ";" << GetY() << ")";}

int main(){
    Point P1(1,3), P2(1,9);
    std::cout<<"Odleglosc pomiedzy punktami P1("<<P1.GetX()<<","<<P1.GetY()<<") i P2("<<P2.GetX()<<","<<P2.GetY()<<") wynosi: "<<P1.Distance(P2)<<std::endl;
    return 0;
}