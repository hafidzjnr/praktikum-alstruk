#include <stdio.h>

// Fungsi untuk menukar dua angka
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printSubArray(int arr[], int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi partisi untuk mengatur ulang array di sekitar pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot adalah elemen terakhir
    printf("\nPivot: %d\n", pivot);
    printf("Sub-array sebelum partisi: ");
    printSubArray(arr, low, high);
    
    int i = (low - 1);      // Indeks elemen yang lebih kecil

    for (int j = low; j <= high - 1; j++) {
        // Jika elemen saat ini lebih kecil dari pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    
    printf("Sub-array setelah partisi: ");
    printSubArray(arr, low, high);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        printf("\nMengurut array[%d..%d]: ", low, high);
        printSubArray(arr, low, high);
        
        // Mempartisi array dan mendapatkan indeks pivot
        int pi = partition(arr, low, high);
        
        // Urutkan elemen secara rekursif sebelum dan sesudah pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Masukan jumlah elemen: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Masukan angka: ");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray awal: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nHasil akhir: ");
    printArray(arr, n);

    return 0;
}