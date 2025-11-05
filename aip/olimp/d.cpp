#include <iostream>
#include <cmath>
#include <vector>
#include <clocale>
#include <algorithm>
using namespace std;

struct zap {
    long long v;
    bool p;
};

bool prov(vector <zap> mas, int dl) {
    long long x = 0;
    int j = 0;
    int sum0 = 0;
    int sum1 = 0;
    if (dl % 2 == 1) {
        return 0;
    }
    for (int i = 0; i < dl; i++) {
        if (x == mas[i].v) {
            if (mas[i].p) {
                sum1 += 1;
            }
            else {
                sum0 += 1;
            }
        }
        else {
            if ((sum0 + sum1) % 2 == 0) {
                if (sum0 != sum1) {
                    return 0;
                }
            }
            else {
                if (j % 2 == 0) {
                    if (sum1 != sum0 + 1) {
                        return 0;
                    }
                }
                else {
                    if (sum1 + 1 != sum0) {
                        return 0;
                    }
                }
            }
            j = i;
            sum0 = 0;
            sum1 = 0;
            x = mas[i].v;
            if (mas[i].p) {
                sum1 += 1;
            }
            else {
                sum0 += 1;
            }
        }
    }
    if ((sum0 + sum1) % 2 == 0) {
        if (sum0 != sum1) {
            return 0;
        }
    }
    else {
        if ((dl - 1) % 2 == 0) {
            if (sum1 != sum0 + 1) {
                return 0;
            }
        }
        else {
            if (sum1 + 1 != sum0) {
                return 0;
            }
        }
    }
    return 1;
}


int main()
{
    int t, n, x;
    // int p, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector <zap> gu(n);
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x < 0) {
                gu[j].p = 0;
            }
            else {
                gu[j].p = 1;
            }
            gu[j].v = abs(x);
        }
        //
        zap temp;
        for (int i1 = 0; i1 < n - 1; i1++) {
            for (int j1 = 0; j1 < n - i1 - 1; j1++) {
                if (gu[j1].v > gu[j1 + 1].v) {
                    // меняем элементы местами
                    temp = gu[j1];
                    gu[j1] = gu[j1 + 1];
                    gu[j1 + 1] = temp;
                }
            }
        }

        if (prov(gu, n)) {
            int sum = 0;
            for (int i2 = 0; i2 < n - 1; i2 += 2) {
                sum += gu[i2 + 1].v - gu[i2].v;
            }
            cout << sum;
        }
        else {
            cout << -1;
        }
        cout << endl;
        //
        n = 0;
    }
    return 0;
}
