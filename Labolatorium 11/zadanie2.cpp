#include <iostream>
#include <complex>

using std::complex;

template <typename T>
T sum(T first, T second){
    return first + second;
}

int main() {
    int number1{-3},number2{4};
    double dnumber1{3.5}, dnumber2{4.6};
    complex<double> cnumber1{2.4,5.3}, cnumber2{1.4,6.4};
    std::cout << sum(number1,number2) << std::endl;
    std::cout << sum(dnumber1,dnumber2)<<std::endl;
    std::cout << sum(cnumber1,cnumber2) << std::endl;
    return 0;
}