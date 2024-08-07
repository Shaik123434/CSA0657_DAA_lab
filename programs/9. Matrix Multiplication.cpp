#include <stdio.h>

int main() {
    int m, n, p, q, i, j, k, sum;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &m, &n);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible.");
        return 0;
    }

    int a[m][n], b[p][q], c[m][q];
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    printf("Resultant matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%3d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
