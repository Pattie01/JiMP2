#include <iostream>
#include <string>

using std::string;

class Dziecko{
    string _imie;
    string _nazwisko;
    int _wiek;
    string _szkola;
public:
    Dziecko();
    Dziecko(string imie, string nazwisko, int wiek, string szkola);
    ~Dziecko();
    friend class Rodzic;

};

Dziecko::Dziecko() {}
Dziecko::Dziecko(string imie, string nazwisko, int wiek, string szkola) {
    _imie = imie;
    _nazwisko = nazwisko;
    _wiek = wiek;
    _szkola = szkola;
}

Dziecko::~Dziecko() {}

class Rodzic{
public:
    string _imie;
    string _nazwisko;
    int _wiek;
    Dziecko _dziecko;
    Rodzic();
    Rodzic(string imie, string nazwisko, int wiek, Dziecko dziecko);
    ~Rodzic();
    void zmienSzkloe(Rodzic &rodzic);
};

Rodzic::Rodzic() {}
Rodzic::Rodzic(string imie, string nazwisko, int wiek, Dziecko dziecko) {
    _imie = imie;
    _nazwisko = nazwisko;
    _wiek = wiek;
    _dziecko = dziecko;
}
Rodzic::~Rodzic() {}

void Rodzic::zmienSzkloe(Rodzic &rodzic) {
    std::cout << rodzic._dziecko._imie << " " << rodzic._dziecko._nazwisko << " - aktualna szkola - " << rodzic._dziecko._szkola << std:: endl;
    std::cout << "Podaj nazwe nowej szkoly: ";
    std::cin.ignore();
    getline(std::cin,rodzic._dziecko._szkola);
    std::cout << rodzic._dziecko._imie << " " << rodzic._dziecko._nazwisko << " - nowa szkola - " << rodzic._dziecko._szkola << std:: endl;
}

int main() {
    Dziecko dziecko("Anna", "Mazur", 11, "Szkola1");
    Rodzic rodzic("Krystyna", "Mazur", 44, dziecko);
    rodzic.zmienSzkloe(rodzic);
    return 0;
}