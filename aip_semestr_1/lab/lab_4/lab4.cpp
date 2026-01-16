#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int len;

    cout << "Введите число от 1 до 45: ";

    cin >> len;

    int* a = new int[len];

    srand((unsigned)time(NULL));
    for (int i = 0;  i < len; i++) {
        a[i] = rand() % 10;
    }

    int mean = 0;

    for (int i = 0; i < len; i++) {
        mean += a[i];
    }

    mean = mean / len;

    cout << "Среднее арифметическое: " << mean << endl;
    cout << "Изначальный массив:  ";
    for (int i = 0;  i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int new_len = len;
    for (int i = 0; i < len - 1; i++) {
        if (a[i] > mean) {
            new_len--;
            for (int j = i; j < new_len; j++) {
                a[j] = a[j + 1];
            }
            i--;
        }
    }

    cout << "Получившийся массив: ";
    for (int i = 0; i < new_len; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
} 
