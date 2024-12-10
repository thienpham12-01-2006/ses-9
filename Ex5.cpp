#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void inputArray(int arr[], int *size) {
    printf("Nhap so phan tu can nhap: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size) {
    printf("Mang hien tai: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printEvenAndSum(int arr[], int size) {
    int sum = 0;
    printf("Cac phan tu chan: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac phan tu chan: %d\n", sum);
}

void printMaxAndMin(int arr[], int size) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);
}

void printPrimeAndSum(int arr[], int size) {
    int sum = 0;
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac so nguyen to: %d\n", sum);
}

void countOccurrences(int arr[], int size) {
    int num, count = 0;
    printf("Nhap vao so can thong ke: ");
    scanf("%d", &num);
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) count++;
    }
    printf("So %d xuat hien %d lan\n", num, count);
}

void addElementAtPosition(int arr[], int *size) {
    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (0 den %d): ", *size);
    scanf("%d", &position);
    if (position < 0 || position > *size) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
    printf("Phan tu da duoc them vao vi tri %d\n", position);
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;
    
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                printArray(arr, size);
                break;
            case 3:
                printEvenAndSum(arr, size);
                break;
            case 4:
                printMaxAndMin(arr, size);
                break;
            case 5:
                printPrimeAndSum(arr, size);
                break;
            case 6:
                countOccurrences(arr, size);
                break;
            case 7:
                addElementAtPosition(arr, &size);
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

