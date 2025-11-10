#include <stdio.h>
#include <stdlib.h>

void input_martix(int n, char** matrix);
void output_norm(int n, char** matrix);
void output_romb(int n, char** matrix);
void matrix_free(int n, char** matrix);

int main() {

    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    char **matrix = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (char*)malloc(sizeof(char) * n);
    }

    input_martix(n, matrix);
    output_norm(n, matrix);
    printf("\n");
    output_romb(n, matrix);

    matrix_free(n, matrix);

    return 0;
}

void input_martix(int n, char** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                matrix[i][j] = (char)i + 48;
            else
                matrix[i][j] = '*';
        }
    }
}

void output_norm(int n, char** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", matrix[i][j]);
            if (j < n - 1)
                printf(" ");
        }
        printf("\n");
    }
}

void output_romb(int n, char** matrix) {
    int m, k;
    for (int i = 0; i < n; i++) {
        m = 0;
        k = i;
        for (int o = 0; o < n - 1 - i; o++) {
            putchar(' ');
        }
        for (int j = 0; j < i + 1; j++) {
            printf("%c ", matrix[k][m]);
            m++;
            k--;
        }
        printf("\n");
    }

    for (int i = 1; i < n; i++) {
        m = i;
        k = n-1;

        for (int o = 0; o < i; o++) {
            putchar(' ');
        }

        for (int j = i; j < n; j++) {
            printf("%c ", matrix[k][m]);
            m++;
            k--;
        }
        printf("\n");
    }
}

void matrix_free(int n, char** matrix) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}