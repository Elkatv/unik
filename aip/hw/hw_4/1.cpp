#include <iostream>
#include <string>
#include "1.h"

using namespace std;

void read_newspaper(News newspaper[], int len);

int main() {
    char n1_text[] = "Новость 1";
    News n1(n1_text, n1_text);

    char n2_text[] = "Новость 2";
    News n2(n2_text, n2_text);

    char n3_text[] = "Новость 3";
    News n3(n3_text, n3_text);

    char n4_text[] = "Новость 4";
    News n4(n4_text, n4_text);

    char n5_text[] = "Новость 5";
    News n5(n5_text, n5_text);

    int len = 5;

    n2.read_news();
    n3.read_news();

    News newspaper[5] = {n1, n2, n3, n4, n5};

    read_newspaper(newspaper, len);

    
    return 0;
}

void read_newspaper(News newspaper[], int len) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        if (!newspaper[i].read()) {
            newspaper[i].output();
            newspaper[i].read_news();
            c++;
            cout << endl;
        }
    }

    cout << "Непрочитанных новостей: " << c << endl;
}