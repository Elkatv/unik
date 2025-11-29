#include <iostream>
#include <string>

using namespace std;


class Person {

protected:
    string full_name;
    int year_of_birth;
    int current_year;

public:
    Person(string person_name, int year) :
        full_name(person_name),
        year_of_birth(year),
        current_year(2025)
    {}

    void output() {
        cout << "ФИО:" << full_name << endl << "Год рождения:" << year_of_birth << endl;
    }

    int age() {
        return current_year - year_of_birth;
    }
};

class Driver : public Person{

protected:
    int year_driver_license;

public:
    Driver(string person_name, int year, int drive_license) : 
        Person(person_name, year), 
        year_driver_license(drive_license)
    {}
    
    void output() {
        cout << "ФИО:" << full_name << endl << "Год рождения:" << year_of_birth << endl << "Год получения водительских прав: " << year_driver_license << endl;
    }

    int driving_experience() {
        return current_year - year_driver_license;
    }

    int age_obtaning_driver_license() {
        return  year_driver_license - year_of_birth;
    } 

};


int main() {
    Person a("Иванов Иван Иванович", 1980);

    a.output();

    cout << "Возвраст: " << a.age() << endl;


    cout << endl;


    Driver b("Иванов Иван Иванович", 1980, 2000);

    b.output();

    cout << "Возвраст: " << b.age() << endl;
    cout << "Водительский опыт: " << b.driving_experience() << endl;
    cout << "Возвраст получения прав: " << b.age_obtaning_driver_license() << endl; 

    return 0;
}