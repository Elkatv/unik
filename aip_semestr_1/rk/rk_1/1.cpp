#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cout << "Введите числа n, m: ";
    cin >> n >> m;

    int k;
    if (n < m) {
        k = m;
        m = n;
        n = k;
    }

    for (int i = 1; i <= m; i++) {
        if (n % i == 0 && m % i == 0) {
            cout << i << " ";
        }
    }

    return 0;
}