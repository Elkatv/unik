#include <iostream>
#include <math.h>

using namespace std;

void shch(float x) {
    float y1, y2, y;

    y1 = (exp(x) - exp(-x)) / 2;
    y2 = (exp(x) + exp(-x)) / 2;
    y = pow(y2, 2) - pow(y1, 2);
    cout.precision(16);
    cout << "y = " << y << " y1 = " << y1 << " y2 = " << y2 << endl;
}

int main() {

    shch(5.0);
    shch(10.0);
    shch(15.0);
    shch(20.0);
    shch(25.0);
    
    return 0;
}