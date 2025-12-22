#include <iostream>

using namespace std;

class Rectangle {
protected:
    float lenght;
    float width;
public:
    Rectangle(float l, float w) :
        lenght(l),
        width(w)
    {}

    void output() {
        cout << "Длина : " << lenght << endl
            << "Ширина : " << width << endl;
    }

    float square() {
        return lenght * width;
    }
};

class Balcony : public Rectangle {
protected:
    float square_with_furniture;

public:
    Balcony(float l, float w, float s) : 
        Rectangle(l, w), 
        square_with_furniture(s)
    {}

    void output() {
        cout << "Длина : " << lenght << endl
            << "Ширина : " << width << endl 
            << "Площадь занимаемая мебелью : " << square_with_furniture << endl;
    }

    float free_square() {
        return square() - square_with_furniture;
    }
};

int main() {
    Rectangle a(10, 15);

    a.output();
    cout << endl;
    cout << "Площадь прямоугольника : " << a.square() << endl;
    cout << endl;

    Balcony b(10, 15, 30);

    b.output();
    cout << endl;
    cout << "Площадь балкона : " << b.square() << endl;
    cout << endl;
    cout << "Свободная площадь на балконе : " << b.free_square() << endl;

    return 0;
}