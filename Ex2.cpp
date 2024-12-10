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

    int pos, new_value;
    	
    printf("Nhap vi tri can sua (1 den %d): ", n);
    scanf("%d", &pos);
		   
    if (pos < 1 || pos > n) {
        printf("Vi tri khong hop le!\n");
    } else {
    	
        printf("Nhap gia tri moi: ");
        scanf("%d", &new_value);

        numbers[pos - 1] = new_value; 
    }

    printf("Mang sau khi sua: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

