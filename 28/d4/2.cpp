#include <iostream>

using namespace std;

class Parking_place {
protected:
    bool condition;
    bool type;
    bool canopy;

public:
    Parking_place(bool c, bool t, bool ca) :
        condition(c),
        type(t),
        canopy(ca)
    {}

    void output() {
        if (condition) {
            cout << "Место занято" << endl;
        } else {
            cout << "Место свободно" << endl;
        }

        if (type) {
            cout << "Место для инвалидов" << endl;
        } else {
            cout << "Обычное место" << endl;
        }

        if (canopy) {
            cout << "Навес есть" << endl;
        } else {
            cout << "Навеса нет" << endl;
        }
    }

    void occupy_place() {
        condition = false;
    }

    void free_place() {
        condition = true;
    }

    bool is_condition() {
        return condition;
    }

    bool is_type() {
        return type;
    }

    bool is_canopy() {
        return canopy;
    }
};

int count_free_places(Parking_place places[], int count);

int main() {
    Parking_place p1(true, true, false),
                  p2(true, false, true),
                  p3(true, true, false),
                  p4(false, false, true),
                  p5(true, true, false);
    
    Parking_place m[] = {p1, p2, p3, p4, p5};
    int len = 5;

    cout << "Количество свободных мест " << count_free_places(m, len);
}

int count_free_places(Parking_place places[], int count) {
        int n = 0;

        for (int i = 0; i < count; i++) {
            if (places[i].is_condition()) {
                n++;
            }
        }

        return n;
    }