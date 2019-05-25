#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

//klasa StudyYear
class StudyYear{
    int _study_year;
public:
    StudyYear();
    StudyYear(int study_year);
    ~StudyYear();
    int get_study_year(){ return this->_study_year; };
    void operator--(int){this->_study_year--;};
    void operator++(int){this->_study_year++;};
    bool operator<(StudyYear &control){ return this->_study_year < control._study_year; };
    bool operator>(StudyYear &control){ return this->_study_year > control._study_year; };
    bool operator==(StudyYear &control){ return this->_study_year == control._study_year; };
    friend std::istream &operator>>(std::istream &input, StudyYear &studyYear);
    friend std::ostream &operator<<(std::ostream &output, const StudyYear &studyYear);
    explicit operator int(){return this->_study_year;};
};

StudyYear::StudyYear() {}
StudyYear::StudyYear(int study_year) {
    _study_year = study_year;
}
StudyYear::~StudyYear() {}

std::istream &operator>>(std::istream &input, StudyYear &studyYear){
    std::cout << "Enter study year:" << std::endl;
    input >> studyYear._study_year;
    return input;
}

std::ostream &operator<<(std::ostream &output, StudyYear &studyYear){
    output << "Year " << studyYear.get_study_year();
    return output;
}


//Klasa Student
class Student{
    string _id;
    string _first_name;
    string _last_name;
    string _program;
    StudyYear _year;
public:
    Student();
    Student(string id, string first_name, string last_name, string program, int year);
    ~Student();
    string get_id(){ return this->_id; };
    string get_first_name(){ return this->_first_name; };
    string get_last_name(){ return this->_last_name; };
    string get_program(){ return this->_program; };
    StudyYear get_year(){ return this->_year;};
    friend std::istream &operator>>(std::istream &input, Student &student);
    friend std::ostream &operator<<(std::ostream &output, const Student &student);

};

Student::Student() {}
Student::Student(string id, string first_name, string last_name, string program, int year) {
    _id = id;
    _first_name = first_name;
    _last_name = last_name;
    _program = program;
    _year = StudyYear(year);
}
Student::~Student() {}

std::istream &operator>>(std::istream &input, Student &student){
    std::cout << "Enter your id number: ";
    input >> student._id;
    std::cout << "Enter you first name: ";
    input >> student._first_name;
    std::cout << "Enter your last name: ";
    input >> student._last_name;
    std::cout << "Enter your program: ";
    input >> student._program;
    std::cout << "Enter your year: ";
    input >> student._year;
    return input;
}

std::ostream &operator<<(std::ostream &output, Student &student){
    output << "[ ";
    output << "Name: " << student.get_first_name() << "\t";
    output << "Surname: " << student.get_last_name() << "\t";
    output << "ID: " << student.get_id() << "\t";
    output << "Year: " << student.get_year().get_study_year() << "\t" ;
    output << "Program: " << student.get_program();
    output << " ]\n" ;
    return output;
}

//kalsa StudentRepository
class StudentRepository{
    vector<Student> repository;
public:
    StudentRepository();
    ~StudentRepository();
    vector<Student> get_repository(){ return this->repository; };
    void add_student(Student &student){this->repository.push_back(student);};
    Student operator[](int id){ return this->repository.at(id); };
};

StudentRepository::StudentRepository() {}
StudentRepository::~StudentRepository() {}


int main() {
    Student student_1{"28979","Jan","Kowalski","Infromatyka",3};
    std::cout << student_1;
    Student student_2;
    std::cin >> student_2;
    std::cout << student_2;
    Student student_3{"1111125","Monika","Kot","Inzynieria Biomedyczna",2};

    StudentRepository repositroy;
    repositroy.add_student(student_1);
    repositroy.add_student(student_2);
        repositroy.add_student(student_3);

    std::cout << "Student Repository: " << std::endl;
    for(auto elem : repositroy.get_repository()){
        std::cout << elem;
    }
    return 0;
}