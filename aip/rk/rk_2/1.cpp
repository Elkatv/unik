#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void input_martix(int n, int m, int** matrix);
void output(int n, int m, int** matrix);
void matrix_free(int n, int** matrix);

void search(int n, int m, int** matrix);

int main() {

    int n, m;
    printf("Введите размер матрицы (n x m): ");
    scanf("%d %d", &n, &m);

    int **matrix = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }


    input_martix(n, m, matrix);    
    output(n, m, matrix);

    printf("\n");

    search(n, m, matrix);

    printf("\n");

    output(n, m - 2, matrix);
    matrix_free(n, matrix);

    return 0;
}

void input_martix(int n, int m, int** matrix) {
    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            matrix[i][j] = (rand() % 10) * pow(-1, rand() % 2);
        }
    }
}

void output(int n, int m, int** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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

void search(int n, int m, int** matrix) {

    int sum[m];
    for (int j = 0; j < m; j++) {
        sum[j] = 0;
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sum[j] += abs(matrix[i][j]);
        }
    }
    
    int max = sum[0];
    int max_i = 0;
    int min = sum[0];
    int min_i = 0;

    for (int j = 1; j < m; j++) {
        if (sum[j] > max){
            max = sum[j];
            max_i = j;
        }
        if (sum[j] < min){
            min = sum[j];
            min_i = j;
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (j > min_i && j > max_i) {
                matrix[i][j-2] = matrix[i][j];
            } else if (j > min_i && j > max_i) {
                matrix[i][j-1] = matrix[i][j];
            }
            
        }
    }

    for (int j = 0; j < m; j++) {
        printf("%d ", sum[j]);
    }
    printf("\n");
}