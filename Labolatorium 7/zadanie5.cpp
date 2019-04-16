#include <iostream>
#include <cmath>

using std::pow;

class Circle{
protected:
    double x_;
    double y_;
    double r_;
public:
    Circle();
    Circle(double x, double y, double r);
    virtual double area() {return (3.14*pow(r_,2));};
};

Circle::Circle() {}
Circle::Circle(double x, double y, double r) {
    x_ = x;
    y_ = y;
    r_ = r;
}

class Sphere : public Circle{
protected:
    double z_;
public:
    Sphere();
    Sphere(double x, double y, double z, double r);
    double area() { return (4*3.14*pow(r_,2));};
};

Sphere::Sphere() {}
Sphere::Sphere(double x, double y, double z, double r) {
    x_ = x;
    y_ = y;
    z_ = z;
    r_ = r;
}

int main() {
    Circle circle(1,1,2);
    Sphere sphere(0,0,0,2);
    std::cout << "Pole kola: " << circle.area() << std::endl;
    std::cout << "Pole kuli: " << sphere.area() << std::endl;
    return 0;
}