#ifndef NEWS_H
#define NEWS_H

#include <iostream>
#include <string.h>

using namespace std;

class News {

protected:
    char* news_theme;
    char* news_text;
    bool news_read;

public:
    News(char theme[], char text[]) :
        news_read(false)
    {
        news_theme = (char*)malloc(sizeof(char) * (strlen(theme) + 1));
        strcpy(news_theme, theme);

        news_text = (char*)malloc(sizeof(char) * (strlen(text) + 1));
        strcpy(news_text, text);
    }

    News(const News &old_news)
    {
        news_read = old_news.news_read;

        news_theme = (char*)malloc(sizeof(char) * (strlen(old_news.news_theme) + 1));
        strcpy(news_theme, old_news.news_theme);

        news_text = (char*)malloc(sizeof(char) * (strlen(old_news.news_text) + 1));
        strcpy(news_text, old_news.news_text);
    }

    ~News() {
        free(news_text);
        free(news_theme);
    }

    void output() {
        if (news_read) 
            cout << "Тема: " << news_theme << endl << "Текст: " << news_text << endl << "Статус: Прочитано"<< endl;
        else 
            cout << "Тема: " << news_theme << endl << "Текст: " << news_text << endl << "Статус: Не прочитато"<< endl;
    }

    void read_news() {
        news_read = true;
    }

    char* theme() {
        return news_theme;
    }
    char* text() {
        return news_text;
    }
    bool read() {
        return news_read;
    }
};

#endif