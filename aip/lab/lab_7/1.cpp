#include <iostream>
#include <string>

using namespace std;

class Fruit {

private:
    char* name_fruit;
    float vitanime_c;

public:
    Fruit(char* name, float c) :
        vitanime_c(c)
    {
        name_fruit = (char*)malloc(sizeof(name) + 1);
        strcpy(name_fruit, name);
    }

    void output() {
        cout << "Название: " << name_fruit << endl << "Содержание витамина С (мг/100г): " << vitanime_c << endl;
    }

    float daily_allowance_fruit() {
        int daily_allowance = 95;
        return daily_allowance / (vitanime_c * 10);
    }
};


int main() {
    char name1[] = "Orange";
    Fruit a(name1, 53.2);

    a.output();
    cout << "Можно съесть в день (кг): " << a.daily_allowance_fruit() << endl;

    char name2[] = "Orange";
    Fruit b(name2, 95);

    b.output();
    cout << "Можно съесть в день (кг): " << b.daily_allowance_fruit() << endl;
    return 0;
}