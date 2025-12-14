#include "1.h"
#include "2.h"
#include <iostream>

using namespace std;

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

    News mas[] = {n1, n2, n3, n4, n5};

    News_Feed a{mas, len};

    cout << "Вывод всех новостей" << endl;
    a.output();

    cout << "Прочтение новости по номеру" << endl;
    a.read_news_to_number(3);

    cout << endl << "Вывод всех не прочитанных новостей" << endl;
    a.read_news_feed();

    char n6_text[] = "Новость 6";
    News n6(n6_text, n6_text);

    a.add_new_news(n6);
    cout << endl << "Вывод всех не прочитанных новостей" << endl;
    a.read_news_feed();

    cout << endl << "Вывод длины новостной ленты" << endl;
    cout << a.len_news_feeds();

    
    return 0;
}