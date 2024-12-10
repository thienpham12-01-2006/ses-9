#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Nhap cac gia tri cho mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int pos;
    printf("Nhap vi tri can xoa (1 den %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Vi tri khong hop le!\n");
    } else {
        for (int i = pos - 1; i < n - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
        
        n--;

        printf("Mang sau khi xoa: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    return 0;
}

