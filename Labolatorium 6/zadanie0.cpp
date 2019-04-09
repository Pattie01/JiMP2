#include <iostream>
#include <cmath>

using std::ostream;
using std::istream;
using std::pow;

class Complex{
    double Re;
    double Im;
public:
    Complex();
    Complex(double real, double imag);
    friend Complex operator+ (const Complex &complex1, const Complex &complex2);
    friend Complex operator- (const Complex &complex1, const Complex &complex2);
    friend Complex operator* (const Complex &complex1, const Complex &complex2);
    friend Complex operator/ (const Complex &complex1, const Complex &complex2);
    friend ostream & operator<< (ostream &out_stream, const Complex &complex);
    friend istream & operator>> (istream &in_stream, Complex &complex);
};

Complex::Complex() {}

Complex::Complex(double real, double imag) {
    Re = real;
    Im = imag;
}

Complex operator+ (const Complex &complex1, const Complex &complex2){
    Complex sum_out(complex1.Re+complex2.Re,complex1.Im+complex2.Re);
    return sum_out;
}

Complex operator- (const Complex &complex1, const Complex &complex2){
    Complex sub_out(complex1.Re-complex2.Re,complex1.Im-complex2.Re);
    return sub_out;
}

Complex operator* (const Complex &complex1, const Complex &complex2){
    Complex multi_out(complex1.Re*complex2.Re-complex1.Im*complex2.Im,complex1.Re*complex2.Im+complex1.Im*complex2.Re);
    return multi_out;
}

Complex operator/ (const Complex &complex1, const Complex &complex2){
    double divider = pow(complex2.Re,2)+pow(complex2.Im,2);
    Complex div_out((complex1.Re*complex2.Re+complex1.Im*complex2.Im)/divider,(complex1.Im*complex2.Re-complex1.Re*complex2.Im)/divider);
    return div_out;
}

ostream & operator<< (ostream &out_stream, const Complex &complex){
    return out_stream << complex.Re << "+" << complex.Im << "i";
}

istream & operator >> (istream &in_stream, Complex &complex){
    return  in_stream >> complex.Re >> complex.Im;
}

int main() {
    Complex number1(4,7), number2(1,3);
    Complex sum, sub, multi, div;
    Complex my_complex_number;

    sum = number1 + number2;
    sub = number1 - number2;
    multi = number1 * number2;
    div = number1 / number2;

    std::cout << "Suma liczb zespolona " << number1 << " oraz " << number2 << " wynosi: " << sum << std::endl;
    std::cout << "Roznica liczb zespolona " << number1 << " oraz " << number2 << " wynosi: " << sub << std::endl;
    std::cout << "Iloczyn liczb zespolona " << number1 << " oraz " << number2 << " wynosi: " << multi << std::endl;
    std::cout << "Iloraz liczb zespolona " << number1 << " oraz " << number2 << " wynosi: " << div << std::endl;

    std::cout << "Podaj czesc rzeczywista i urojona liczby zespolonej: ";
    std::cin >> my_complex_number;
    std::cout << "Liczba zespolona wprowadzona za pomoca przeciazonego operatora '>>': " << my_complex_number;
    return 0;
}