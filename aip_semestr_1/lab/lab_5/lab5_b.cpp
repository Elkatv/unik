#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input_matrix(int n, int** matrix);
void search(int n, int** matrix);
void output(int n, int** matrix);
void matrix_free(int n, int** matrix);


int main() {

    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    int **matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }


    input_matrix(n, matrix);    
    output(n, matrix);
    search(n, matrix);

    matrix_free(n, matrix);

    return 0;
}

void input_matrix(int n, int** matrix) {
    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void search(int n, int** matrix) {
    int sums_prefix[n]; 
    int sums_postfix[n];

    for (int i = 0; i < n; i++) {
        sums_prefix[i] = 0;
        sums_postfix[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            sums_postfix[i] += matrix[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sums_prefix[j] < sums_postfix[j]) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }

            if (i != n - 1) {
                sums_prefix[j] += matrix[i][j];
                sums_postfix[j] -= matrix[i + 1][j];
            }
        }
        printf("\n");
    }
}

void output(int n, int** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    printf("\n");
}

void matrix_free(int n, int** matrix) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}