#include <iostream>

using namespace std;

class Shelf {
protected: 
    int max_count_book;
public:
    Shelf(int n) :
        max_count_book(n) 
    {}

    int max_count() {
        return max_count_book;
    }
};

class Shelf_with_book : public Shelf {
protected:
    float procent;
public:
    Shelf_with_book(int max, int count_book) : 
        Shelf(max)
    {
        procent = (float)count_book / (float)max_count_book;
    }

    int books() {
        return (int)(procent * max_count_book);
    }
};

class Bookcase {
protected:
    int count_shelf;
    Shelf_with_book mas[];

public:
    Bookcase(Shelf_with_book m[], int n) {
        for (int i = 0; i < n; i++) {
            mas[i] = m[i];
        }
        count_shelf = n;
    }

    int count_book() {
        int sum_count = 0;
        for (int i = 0; i < count_shelf; i++) {
            sum_count += mas[i].books();
        }

        return sum_count;
    }

    float procent_book() {
        int sum_count = 0;
        int max = 0;
        for (int i = 0; i < count_shelf; i++) {
            sum_count += mas[i].books();
            max += mas[i].max_count();
        }

        return (float)sum_count / (float)max;
    }
};

int main() {
    Shelf_with_book a(10, 8), b(10, 7), c(10, 6);

    Shelf_with_book mas[] = {a, b, c};

    Bookcase casebook(mas, 3);

    cout << casebook.count_book() << endl;
    cout << casebook.procent_book() << endl;

    return 0;
}