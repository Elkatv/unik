#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int len = 30;

    int h[len];
    srand((unsigned)time(NULL));
    for (int i = 0;  i < len; i++) {
        h[i] = rand() % 10;
    }

    int max = h[0];
    for (int i = 1;  i < len; i++) {
        if (h[i] > max) {
            max = h[i];
        }
    }

    cout << "Максимальное число: " << max << endl;
    cout << "Изначальный массив:  ";
    for (int i = 0;  i < 30; i++) {
        cout << h[i] << " ";
    }
    cout << endl;

    int new_len = len;
    for (int i = 0; i < len - 1; i++) {
        if (h[i] == max) {
            new_len--;
            for (int j = i; j < new_len; j++) {
                h[j] = h[j + 1];
            }
        }
    }

    if (h[new_len - 1] == max) {
        new_len--;
    }

    cout << "Получившийся массив: ";
    for (int i = 0;  i < new_len; i++) {
        cout << h[i] << " ";
    }

    return 0;
} 
