// NAMA:HAFIDZ JANUAR FATURAHMAN
// NPM:247006111077
// KELAS: C

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {7, 3, 17, 23, 88, 84, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Pilih metode pencarian:\n");
    printf("1: Pencarian Biner\n");
    printf("2: Pencarian Sekuensial\n");
    printf("3: Tidak Ada\n");

    int choice;
    printf("Masukkan pilihan: ");
    scanf("%d", &choice);

    if (choice == 1) {
        qsort(arr, size, sizeof(int), compare); 
    }

    if (choice == 1 || choice == 2) {
        int target;
        printf("Masukkan angka yang ingin dicari: ");
        scanf("%d", &target);

        int result = (choice == 1) ? binarySearch(arr, size, target) : sequentialSearch(arr, size, target);

        if (result != -1)
            printf("Angka %d ditemukan pada indeks %d.\n", target, result);
        else
            printf("Angka tidak ditemukan.\n");
    } else {
        printf("Tidak Ada!\n");
    }

    return 0;
}
