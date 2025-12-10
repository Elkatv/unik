#include <iostream>
#include <string.h>

using namespace std;


class Person {

protected:
    char* full_name;
    int year_of_birth;
    int current_year;

public:
    Person(char* person_name, int year) :
        year_of_birth(year),
        current_year(2025) 
    {
        full_name = (char*)malloc(sizeof(person_name) + 1);
        strcpy(full_name, person_name);
    }
    ~Person() {
        free(full_name);
    }

    void output() {
        cout << "ФИО:" << full_name << endl << "Год рождения:" << year_of_birth << endl;
    }

    int age() {
        return current_year - year_of_birth;
    }
};

class Driver : public Person {

protected:
    int year_driver_license;

public:
    Driver(char* person_name, int year, int drive_license) : 
        Person(person_name, year), 
        year_driver_license(drive_license)
    {}
    ~Driver() {}
    
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


    char name[] = "Иванов Иван Иванович";
    Person a(name, 1980);

    a.output();

    cout << "Возвраст: " << a.age() << endl;
    
    cout << endl;


    Driver b(name, 1980, 2000);

    b.output();

    cout << "Возвраст: " << b.age() << endl;
    cout << "Водительский опыт: " << b.driving_experience() << endl;
    cout << "Возвраст получения прав: " << b.age_obtaning_driver_license() << endl; 

    return 0;
}