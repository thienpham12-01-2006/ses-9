#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void inputArray(int arr[], int *size) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", size);
    if (*size > MAX_SIZE) {
        printf("So phan tu vuot qua gioi han.\n");
        *size = MAX_SIZE;
    }
    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
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

void addElement(int arr[], int *size) {
    if (*size < MAX_SIZE) {
        int value;
        printf("Nhap phan tu can them: ");
        scanf("%d", &value);
        arr[*size] = value;
        (*size)++;
        printf("Phan tu da duoc them vao mang.\n");
    } else {
        printf("Mang da dat muc toi da.\n");
    }
}

void modifyElement(int arr[], int size) {
    int index, value;
    printf("Nhap so thu tu cua mang can sua (tu 0 den %d): ", size - 1);
    scanf("%d", &index);
    if (index >= 0 && index < size) {
        printf("Nhap gia tri moi cho phan tu %d: ", index);
        scanf("%d", &value);
        arr[index] = value;
        printf("Phan tu da duoc sua thanh %d.\n", index, value);
    } else {
        printf("So ban nhap khong hop le.\n");
    }
}

void deleteElement(int arr[], int *size) {
    int index;
    printf("Nhap chu so phan tu can xoa (tu 0 den %d): ", *size - 1);
    scanf("%d", &index);
    if (index >= 0 && index < *size) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Phan tu thu %d da duoc xoa.\n", index);
    } else {
        printf("Chu so khong hop le.\n");
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
       
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon yeu cau: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                printArray(arr, size);
                break;
            case 3:
                addElement(arr, &size);
                break;
            case 4:
                modifyElement(arr, size);
                break;
            case 5:
                deleteElement(arr, &size);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le vui long chon lai.\n");
        }
    } while (choice != 6); 

    return 0;
}

