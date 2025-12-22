#include <ncurses.h>
#include <stdio.h>

void output(int cord_x, int cord_y, int hight_right, int hight_left, int count_r, int count_l, int tens_l,
            int tens_r, int ones_l, int ones_r, int n) {
    tens_l = count_l / 10, tens_r = count_r / 10;
    ones_l = count_l % 10, ones_r = count_r % 10;
    n = 0;
    // printw("\033[H\033[J");
    clear();
    refresh();

    printw("================================================================================\n");
    for (int y = 1; y <= 25; y++) {
        for (int x = 1; x <= 80; x++) {
            if (cord_x == x && cord_y == y) {
                printw("o");
            } else if (x == 78 && (hight_right == y || hight_right + 1 == y || hight_right + 2 == y)) {
                printw("*");
            } else if (x == 3 && (hight_left == y || hight_left + 1 == y || hight_left + 2 == y)) {
                printw("*");
            } else if (x == 40 + y % 2) {
                printw("|");
            } else if (2 <= y && y <= 6 && 32 <= x && x <= 34) {
                n = tens_l;

                if (n == 0) {
                    printw(" ");
                    continue;
                }

                if (x == 32) {
                    if (y == 2) {
                        if (n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        if (n != 1 && n != 2 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 1 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else if (x == 33) {
                    if (y == 2) {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        printw(" ");
                    } else if (y == 4) {
                        if (n != 0 && n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n == 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else {
                    if (y == 2) {
                        printw("*");
                    } else if (y == 3) {
                        if (n != 5 && n != 6)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 2 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                }

            } else if (2 <= y && y <= 6 && 36 <= x && x <= 38) {
                n = ones_l;

                if (x == 36) {
                    if (y == 2) {
                        if (n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        if (n != 1 && n != 2 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 1 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else if (x == 37) {
                    if (y == 2) {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        printw(" ");
                    } else if (y == 4) {
                        if (n != 0 && n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n == 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else {
                    if (y == 2) {
                        printw("*");
                    } else if (y == 3) {
                        if (n != 5 && n != 6)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 2 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                }
            } else if (2 <= y && y <= 6 && 43 <= x && x <= 45) {
                if (tens_r == 0)
                    n = ones_r;
                else
                    n = tens_r;

                if (x == 43) {
                    if (y == 2) {
                        if (n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        if (n != 1 && n != 2 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 1 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else if (x == 44) {
                    if (y == 2) {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        printw(" ");
                    } else if (y == 4) {
                        if (n != 0 && n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n == 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else {
                    if (y == 2) {
                        printw("*");
                    } else if (y == 3) {
                        if (n != 5 && n != 6)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 2 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                }
            } else if (2 <= y && y <= 6 && 47 <= x && x <= 49) {
                if (tens_r == 0) {
                    printw(" ");
                    continue;
                } else
                    n = ones_r;

                if (x == 47) {
                    if (y == 2) {
                        if (n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        if (n != 1 && n != 2 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 1 && n != 3 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 1 && n != 3 && n != 4 && n != 5 && n != 7 && n != 9)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else if (x == 48) {
                    if (y == 2) {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 3) {
                        printw(" ");
                    } else if (y == 4) {
                        if (n != 0 && n != 1)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n == 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 1 && n != 4)
                            printw("*");
                        else
                            printw(" ");
                    }
                } else {
                    if (y == 2) {
                        printw("*");
                    } else if (y == 3) {
                        if (n != 5 && n != 6)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 4) {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else if (y == 5) {
                        if (n != 2 && n != 7)
                            printw("*");
                        else
                            printw(" ");
                    } else {
                        if (n != 7)
                            printw("*");
                        else
                            printw(" ");
                    }
                }
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    printw("================================================================================\n");
    // printw("%d %d : %d %d %d\n", cord_x, cord_y, hight_right, hight_right + 1, hight_right + 2);
}

int do_input(int cord_x, int cord_y, int hight_right, int hight_left, int count_r, int count_l, int vector_x,
             int vector_y, int tens_l, int tens_r, int ones_l, int ones_r, int n) {
    // char input;
    // printw("sjkfdhgjdfhgdhshdgh;");
    halfdelay(1);
    int ch = getch();

    if (ch == 97 || ch == 122 || ch == 107 || ch == 109 || ch == ERR) {
        switch (ch) {
            case (97):
                if (hight_left != 1) {
                    hight_left -= 1;
                }
                break;
            case (122):
                if (hight_left != 23) {
                    hight_left += 1;
                }
                break;
            case (107):
                if (hight_right != 1) {
                    hight_right -= 1;
                }
                break;
            case (109):
                if (hight_right != 23) {
                    hight_right += 1;
                }
                break;
            case (ERR):
                break;
        }
        cord_x += vector_x;
        cord_y += vector_y;

        if (cord_y <= 1 || cord_y >= 25) {
            vector_y = -vector_y;
        }

        if (cord_x == 4 && (cord_y == hight_left || cord_y == hight_left + 1 || cord_y == hight_left + 2)) {
            vector_x = -vector_x;
        }
        if (cord_x == 77 &&
            (cord_y == hight_right || cord_y == hight_right + 1 || cord_y == hight_right + 2)) {
            vector_x = -vector_x;
        }

        if (cord_x < 1 || cord_x > 80) {
            if (cord_x > 40) {
                count_l++;
            } else {
                count_r++;
            }

            cord_x = 40;
            cord_y = 13;
            vector_y = -vector_y;
        }

        output(cord_x, cord_y, hight_right, hight_left, count_r, count_l, tens_l, tens_r, ones_l, ones_r, n);
    }

    if (count_l >= 5) {
        return 0;
    } else if (count_r >= 5) {
        return 1;
    }

    do_input(cord_x, cord_y, hight_right, hight_left, count_r, count_l, vector_x, vector_y, tens_l, tens_r,
             ones_l, ones_r, n);

    return 2;
}

int main() {
    int count_r = 0, count_l = 0;
    int vector_x = 1, vector_y = 1, cord_x = 40, cord_y = 13;
    int hight_right = 12, hight_left = 12;
    int win;
    int tens_l = count_l / 10, tens_r = count_r / 10;
    int ones_l = count_l % 10, ones_r = count_r % 10;
    int n = 0;

    initscr();
    cbreak();
    noecho();

    output(cord_x, cord_y, hight_right, hight_left, count_r, count_l, tens_l, tens_r, ones_l, ones_r, n);
    win = do_input(cord_x, cord_y, hight_right, hight_left, count_r, count_l, vector_x, vector_y, tens_l,
                   tens_r, ones_l, ones_r, n);
    if (win == 0) {
        printw("Left WINS!!!");
    } else if (win == 1) {
        printw("Right WINS!!!");
    }
    endwin();

    return 0;
}