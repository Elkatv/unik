#include <iostream>
#include <string>
#include <vector>

using namespace std;


class News {

private:
    string news_theme;
    string news_text;
    bool news_read;

public:
    News(string theme, string text) : 
        news_theme(theme), 
        news_text(text)
    {}

    void output() {
        if (news_read) 
            cout << "Тема: " << news_theme << endl << "Текст: " << news_text << endl << "Статус: Прочитано"<< endl;
        else 
            cout << "Тема: " << news_theme << endl << "Текст: " << news_text << endl << "Статус: Не прочитато"<< endl;
    }

    void read_news() {
        news_read = true;
    }

    string theme() {
        return news_theme;
    }
    string text() {
        return news_text;
    }
    bool read() {
        return news_read;
    }
};

class News_Feed {

private:
    vector<News> feed;

public:

};

int main() {

    return 0;
}