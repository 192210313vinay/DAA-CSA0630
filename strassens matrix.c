#include <stdio.h>


void addMatrix(int n, int A[][n], int B[][n], int C[][n]) {
	int i,j;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

]
void subtractMatrix(int n, int A[][n], int B[][n], int C[][n]) {
	int i,j;
    for (i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}


void strassenMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    
    int i,j;
    for ( i = 0; i < newSize; i++)
        for (j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }

    
    subtractMatrix(newSize, B12, B22, temp1);
    strassenMultiply(newSize, A11, temp1, temp2);
    addMatrix(newSize, A11, A12, temp1);
    strassenMultiply(newSize, temp1, B22, C11);

    strassenMultiply(newSize, A21, temp1, C12);

    subtractMatrix(newSize, B21, B11, temp1);
    strassenMultiply(newSize, A22, temp1, temp2);
    addMatrix(newSize, A21, A22, temp1);
    strassenMultiply(newSize, temp1, B11, C21);

    strassenMultiply(newSize, A12, temp1, C22);

    
    addMatrix(newSize, C11, C12, C);
    addMatrix(newSize, C, C21, C);
    subtractMatrix(newSize, C, C22, C);
    addMatrix(newSize, C, C22, C);
}


void printMatrix(int n, int mat[][n]) {
	int i,j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int n = 2; 

    int A[][2] = {{1, 2}, {3, 4}};
    int B[][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    printf("Matrix A:\n");
    printMatrix(n, A);

    printf("\nMatrix B:\n");
    printMatrix(n, B);

    strassenMultiply(n, A, B, C);

    printf("\nResultant Matrix C (Using Strassen's Multiplication):\n");
    printMatrix(n, C);

    return 0;
}

