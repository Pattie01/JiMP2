#include <iostream>
#include <string.h>

using std::string;


class PESEL{
    char *_number;
public:
    PESEL();
    PESEL(char *number);
    bool validatePESEL(const char *number );
    ~PESEL();
};

PESEL::PESEL() {}

PESEL::PESEL(char *number) {
    this->_number = number;
    if(!validatePESEL(number)) {
        string info = "Invalid PESEL number!";
        throw info;
    }
    std::cout << "Your's PESEL number: " << number << std::endl;
}

bool PESEL::validatePESEL(const char *number) {
    return ((9*((number[0]-'0')+(number[4]-'0')+(number[8]-'0'))+7*((number[1]-'0')+(number[5]-'0')+(number[9]-'0'))
    +3*((number[2]-'0')+(number[6]-'0'))+((number[3]-'0')+(number[7]-'0')))%10==(number[10]-'0'));
}

PESEL::~PESEL() {}


int main() {
    try {
        PESEL mojPesel{"9612050464"};
    }catch (string exep){
        std::cout << exep << std::endl;
    }catch (...){
        std::cout << "Unknown exception!" << std::endl;
    }
    return 0;
}