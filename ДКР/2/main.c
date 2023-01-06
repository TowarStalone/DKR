#include <stdio.h>
#include <stdlib.h>

#define N 4

void sort_matrix_rows(int a[N][N], int b[N][N]) {
    // Створення масиву розміром N для зберігання сум рядків
    int sums[N];

    // Обчислити суми рядків матриці а та зберегти їх у масиві sums
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
        for (int j = 0; j < N; j++) {
            sums[i] += a[i][j];
        }
    }

   // Сортування рядків матриці a на основі значень у масиві сум
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sums[i] > sums[j]) {
                // Поміняти місцями рядки i та j в обох матрицях a та b

                for (int k = 0; k < N; k++) {
                  int temp = b[i][k];
                    b[i][k] = b[j][k];
                    b[j][k] = temp;
                }

                // Також поміняти місцями значення в масиві сум
                int temp = sums[i];
                sums[i] = sums[j];
                sums[j] = temp;
            }
        }
    }
}

int main() {
    // Ініціалізація матриць a і b випадковими значеннями
    int a[N][N], b[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % (7-3+1)+3;
            b[i][j] = a[i][j];
        }
    }

    // Сортування рядків матриць
    sort_matrix_rows(a, b);

    // Надрукувати матриці
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
