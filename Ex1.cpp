#include <stdio.h>

int main() {
    int n;
    
    printf("Vui long nhap so gia tri ma ban muon in : ");
    scanf("%d", &n);
    
    if (n > 100 || n < 1) {
        printf("Gia tri khong hop le! \n");
        return 1;
    }

    int numbers[n];
    int currentLength = n;

    for (int i = 0; i < n; i++) {
        printf("Vui long nhap gia tri thu %d : ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Cac so ban da nhap: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int addIndex, value;
    printf("Nhap vi tri muon chen (0 den %d): ", currentLength);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex > currentLength) {
        printf("Vi tri khong hop le!\n");
    } else {
        printf("Nhap gia tri muon chen: ");
        scanf("%d", &value);

        if (addIndex >= currentLength) {
            numbers[addIndex] = value;
            currentLength = addIndex + 1;
        } else {
            for (int i = currentLength; i > addIndex; i--) {
                numbers[i] = numbers[i - 1];
            }
            numbers[addIndex] = value;
            currentLength++;
        }

        printf("Cac so trong mang sau khi chen: ");
        for (int i = 0; i < currentLength; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    return 0;
}

