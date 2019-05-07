#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;

set<string> XYZ{"informatyka", "ekonomia", "matematyka", "fizyka", "filozofia"}; //globany zbior kierunkow uczelni XYZ

class invalid_argument{
protected:
    string _info;
public:
    invalid_argument(){};
    //invalid_argument(const string &info): _info(info){};
    ~invalid_argument(){};
    string showInfo(){return _info;};
};

class InvalidNameSurname : public invalid_argument{
public:
    InvalidNameSurname(){_info = "Invalid name or surname!";};
    ~InvalidNameSurname(){};
};

class InvalidNameCharacters : public invalid_argument{
public:
    InvalidNameCharacters(){_info = "Invalid name or surname characters!";};
    ~InvalidNameCharacters(){};
};

class InvalidAge : public invalid_argument{
public:
    InvalidAge(){_info = "Invalid age!";};
    ~InvalidAge(){};
};

class InvalidProgram : public  invalid_argument{
public:
    InvalidProgram(){_info = "Invalid program!";};
    ~InvalidProgram(){};
};

class Student{
    string _name;
    string _surname;
    int _age;
    string _fieldOfStudy;
public:
    Student();
    Student(string name, string surname, int age, string fieldOfStudy);
    void setName(string name);
    void setSurname(string surname);
    void setAge(int age);
    void setFieldOfStudy(string fieldOfStudy);
    ~Student();
};

Student::Student() {}

Student::Student(string name, string surname, int age, string fieldOfStudy) {
    _name = name;
    _surname = surname;
    _age = age;
    _fieldOfStudy = fieldOfStudy;
}

void Student::setName(string name){
    _name = name;
    string::iterator it_name = name.begin();                        //iterator na poczatek imienia
    if(islower(*it_name)) throw InvalidNameCharacters();            //czy pierwsza litera jest mala
    for(it_name ; it_name < name.end(); ++it_name){                 //sprawdzanie czy same litery
        if(!isalpha(*it_name)){
            throw InvalidNameCharacters();
        }
    }
}

void Student::setSurname(string surname){
    _surname = surname;
    string::iterator it_surname = surname.begin();
    if(islower(*it_surname)) throw InvalidNameCharacters();
    for(it_surname; it_surname < surname.end(); ++it_surname){
        if(!isalpha(*it_surname)){
            throw InvalidNameCharacters();
        }
    }
}

void Student::setAge(int age){
    _age = age;
    if(age<10 or age>100){
        throw InvalidAge();
    }
}

void Student::setFieldOfStudy(string fieldOfStudy){
    _fieldOfStudy = fieldOfStudy;
    if(XYZ.find(fieldOfStudy) == XYZ.end()){           //sprawdzanie czy kierunek znajduje sie w zbiorze uczleni XYZ
        throw InvalidProgram();
    }
}

Student::~Student() {}

int main() {
    Student student;
    string name, surname, fieldOfStudy;
    int age;
    try{
        std::cout << "Enter a student's name: ";
        std::cin >> name;
        student.setName(name);
        std::cout << "Enter a student's surname: ";
        std::cin >> surname;
        student.setSurname(surname);
        std::cout << "Enter a student's age: ";
        std::cin >> age;
        student.setAge(age);
        std::cout << "Enter a chosen field of study: ";
        std::cin >> fieldOfStudy;
        student.setFieldOfStudy(fieldOfStudy);

    }catch (InvalidNameSurname exep){
        std::cout << "Exception: " << exep.showInfo() << std::endl;
    }catch (InvalidAge exep){
        std::cout << "Exception: " << exep.showInfo() << std::endl;
    }catch (InvalidNameCharacters exep){
        std::cout << "Exception: " << exep.showInfo() << std::endl;
    }catch(InvalidProgram exep){
        std::cout << "Exception: " << exep.showInfo() << std::endl;
    }catch (invalid_argument exep){
        std::cout << "Exception: " << exep.showInfo() << std::endl;
    }catch (...){
        std::cout << "Exception: Unknown exception!!" << std::endl;
    }
    return 0;
}