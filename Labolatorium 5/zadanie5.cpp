#include <iostream>
#include <vector>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using std::vector;

class Martian{
public:
    Martian();
    ~Martian();
    static int number_of_aliens;
    static bool alines_attack();
};
int Martian::number_of_aliens = 0;

Martian::Martian() {
    Martian::number_of_aliens++;
}
Martian::~Martian() {
    Martian::number_of_aliens--;
}
bool Martian::alines_attack() {
    int chance_of_defeat = (rand()%100)-20;
    return(Martian::number_of_aliens > 5 and chance_of_defeat > 50);
}

int main() {
    srand(time(0));
    vector<Martian *> aliens;
    while(true){
        aliens.push_back(new Martian());

        if(Martian::number_of_aliens <= 5){
            std::cout << "Aliens are hiding" << std::endl;
        }

        for(int i=0; i<Martian::number_of_aliens; ++i){
            if(Martian::alines_attack()){
                delete aliens[i];
                aliens.erase(aliens.begin()+i);
                std::cout << "Aliens attack. How many martians: " << Martian::number_of_aliens << std::endl;
            }
        }
    }

    return 0;
}