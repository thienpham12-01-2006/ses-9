#include <stdio.h>

#define MAX_SIZE 100

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Nhap so dong cua ma tran: ");
    scanf("%d", rows);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", cols);

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Ma tran hien tai:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printOddAndSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int sum = 0;
    printf("Cac phan tu le: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                printf("%d ", matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", sum);
}

void printBorderAndProduct(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int product = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", matrix[i][j]);
                product *= matrix[i][j];
            }
        }
    }
    printf("\nTich cua cac phan tu tren duong bien: %d\n", product);
}

void printMainDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void printSecondaryDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][cols - 1 - i]);
    }
    printf("\n");
}

void printMaxSumRow(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int maxSum = -1, maxRowIndex = -1;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRowIndex = i;
        }
    }
    printf("Dau ra dong co tong gia tri cac phan tu la lon nhat: ");
    for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[maxRowIndex][j]);
    }
    printf("\nTong cua dong: %d\n", maxSum);
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua ma tran\n");
        printf("2. In gia tri cac phan tu cua ma tran\n");
        printf("3. In gia tri cac phan tu le va tinh tong\n");
        printf("4. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu tren duong cheo chinh\n");
        printf("6. In ra cac phan tu tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(matrix, &rows, &cols);
                break;
            case 2:
                printMatrix(matrix, rows, cols);
                break;
            case 3:
                printOddAndSum(matrix, rows, cols);
                break;
            case 4:
                printBorderAndProduct(matrix, rows, cols);
                break;
            case 5:
                printMainDiagonal(matrix, rows, cols);
                break;
            case 6:
                printSecondaryDiagonal(matrix, rows, cols);
                break;
            case 7:
                printMaxSumRow(matrix, rows, cols);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);

    return 0;
}

