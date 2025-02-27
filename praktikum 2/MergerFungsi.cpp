#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menggabungkan dua subarray dari arr[].
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // Panjang subarray kiri
    int n2 = right - mid;    // Panjang subarray kanan

    // Buat array sementara
    int leftArr[n1], rightArr[n2];

    // Salin data ke array sementara
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Gabungkan array sementara ke arr[left..right]
    i = 0; // Indeks awal subarray kiri
    j = 0; // Indeks awal subarray kanan
    k = left; // Indeks awal array yang digabung

    printf("Proses penggabungan:\n");
    printf("  Left  : ");
    for (int x = 0; x < n1; x++) {
        printf("%d ", leftArr[x]);
    }
    printf("\n  Right : ");
    for (int x = 0; x < n2; x++) {
        printf("%d ", rightArr[x]);
    }
    printf("\n");

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Salin elemen yang tersisa dari leftArr[], jika ada
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Salin elemen yang tersisa dari rightArr[], jika ada
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    printf("  Merged: ");
    for (int x = left; x <= right; x++) {
        printf("%d ", arr[x]);
    }
    printf("\n\n");
}

// Fungsi untuk mengimplementasikan merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Hitung titik tengah
        int mid = left + (right - left) / 2;

        // Urutkan bagian kiri dan kanan
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan kedua bagian yang telah diurutkan
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    // Input jumlah elemen
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];

    // Input elemen array
    printf("Masukkan elemen array:\n");
    for (int i = 0; i < n; i++) {
        printf("  Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Tampilkan array sebelum diurutkan
    printf("\nArray sebelum diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Panggil fungsi mergeSort
    printf("\nProses merge sort:\n");
    mergeSort(arr, 0, n - 1);

    // Tampilkan array setelah diurutkan
    printf("\nArray setelah diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
