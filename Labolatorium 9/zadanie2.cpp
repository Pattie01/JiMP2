#include <iostream>
#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::reference_wrapper;

class Bag{
protected:
    double _money;
    int _volume;
public:
    Bag();
    Bag(double money, int volume);
    virtual int get_volume();
    virtual double get_money();
    void add_to_bag(int minus_volume, double minus_money);
    ~Bag();
};

Bag::Bag() {}
Bag::Bag(double money, int volume) {
    _money = money;
    _volume = volume;
}

int Bag::get_volume() {
    return this->_volume;
}

double  Bag::get_money() {
    return this->_money;
}

void Bag::add_to_bag(int minus_volume, double minus_money) {
    this->_volume-=minus_volume;
    this->_money-=minus_money;
}

Bag::~Bag() {}

class Drink : public Bag{
protected:
    string _drink;
    double _alc_content;
public:
    Drink();
    Drink(double money, int volume, string drink, double alc_content);
    int get_volume();
    double get_money();
    double get_alc_content();
    string get_type();
    ~Drink();
};

Drink::Drink() {}
Drink::Drink(double money, int volume, string drink, double alc_content) {
    _money = money;
    _volume = volume;
    _drink = drink;
    _alc_content = alc_content;
}

int Drink::get_volume() {
    return this->_volume;
}

double Drink::get_money() {
    return this->_money;
}

double Drink::get_alc_content() {
    return this->_alc_content;
}

string Drink::get_type() {
    return this->_drink;
}

Drink::~Drink() {}

double estimate_BAC(string sex, int body_weight, double sd){
    double body_water_constant{};
    double metabolism_constant{};
    int drinking_time = 4;
    std::cout << drinking_time << std::endl;
    if(sex=="female"){
        body_water_constant = 0.49;
        metabolism_constant = 0.017;
    }else{
        body_water_constant = 0.58;
        metabolism_constant = 0.015;
    }
    return (((0.806*sd*1.2)/(body_water_constant*body_weight))-(metabolism_constant*drinking_time));
}

int main(){

    int body_weight{};
    string sex{};
    double BAC{};

    std::cout << "Enter your sex (male/female): ";
    std::cin >> sex;
    std::cout << "Enter your body weight: ";
    std::cin >> body_weight;

    Bag bag(100,5);
    Drink beer(5,0.2,"beer",1.5);
    Drink cider(10,0.8,"cider",5);
    Drink wine(20,1,"wine",6);

    vector<Drink> shelf;
    shelf.emplace_back(beer);
    shelf.emplace_back(cider);
    shelf.emplace_back(wine);

    while(bag.get_volume()>0 and bag.get_money()>0 and BAC <= 0.099){
        int choice = rand()% shelf.size();
        std::cout << "Choice: " << shelf[choice].get_type() << " - volume: " << shelf[choice].get_volume() << " money: " << shelf[choice].get_money() <<std::endl;
        bag.add_to_bag(shelf[choice].get_volume(),shelf[choice].get_money());
        std::cout << bag.get_volume() << std::endl;
        std::cout << bag.get_money() << std::endl;
        BAC+=estimate_BAC(sex,body_weight,shelf[choice].get_alc_content());
        std::cout << "BAC: " << BAC << std::endl;
    }
    return 0;
}