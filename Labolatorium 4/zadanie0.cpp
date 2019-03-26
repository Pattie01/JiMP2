#include <iostream>

class Ulamek{
public:
    double licznik, mianownik;
    Ulamek();
    void wypiszUlamek(){std::cout<<"Twoj ulamek wyglada nastepujaco: "<<licznik<<"/"<<mianownik<<std::endl;};
    ~Ulamek();
};
Ulamek::Ulamek() {}

Ulamek::~Ulamek() {}

int main(){
    Ulamek ulamek;
    std::cout<<"Podaj licznik: ";
    std::cin>>ulamek.licznik;
    std::cout<<"Podaj mianownik: ";
    std::cin>>ulamek.mianownik;
    if(ulamek.mianownik == 0){
        std::cout<<"Mianownik nie moze byc zerem!"<<std::endl;
    }else{
        ulamek.wypiszUlamek();
    }
    return 0;
}

