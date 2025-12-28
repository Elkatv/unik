#ifndef NEWS_FEED_H
#define NEWS_FEED_H

#include "1.h"
#include <iostream>

using namespace std;

class News_Feed {

protected:
    News* feeds;
    int count;

public:
    News_Feed(News* n, int c) : 
        count(c)
    {
        feeds = (News*)malloc(sizeof(News) * c);

        for (int i = 0; i < c; i++) {
            feeds[i] = n[i];
        }
    }

    News_Feed(const News_Feed &n) {
        count = n.count;

        feeds = (News*)malloc(sizeof(News) * n.count);
        
        for (int i = 0; i < n.count; i++) {
            feeds[i] = n.feeds[i];
        }
    }

    ~News_Feed() {
        free(feeds);
    }



    void output() {
        for (int i = 0; i < count; i++) {
            feeds[i].output();
            cout << endl;
        }
    }

    void add_new_news(News new_news) {
        feeds = (News*)realloc(feeds, sizeof(News) * (count + 1));
        feeds[count] = new_news;
        count += 1;
    }

    void read_news_to_number(int n) {
        n = n - 1;
        feeds[n].output();
        feeds[n].read_news();
    }

    void read_news_feed() {
        for (int i = 0; i < count; i++) {
            if (!feeds[i].read()) {
                feeds[i].output();
                feeds[i].read_news();
                cout << endl;
            }
        }
    }

    int len_news_feeds() {
        return count;
    }

};

#endif 