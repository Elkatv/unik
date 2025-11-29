#include <iostream>
#include <string>

using namespace std;

class Fruit {

private:
    string name_fruit;
    float vitanime_c;

public:
    Fruit(string name, float c) {
        name_fruit = name;
        vitanime_c = c;
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

    Fruit a("Orange", 53.2);

    a.output();
    cout << "Можно съесть в день (кг): " << a.daily_allowance_fruit() << endl;

    Fruit b("Apple", 95);

    b.output();
    cout << "Можно съесть в день (кг): " << b.daily_allowance_fruit() << endl;
    return 0;
}