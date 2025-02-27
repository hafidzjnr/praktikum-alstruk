#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menukar dua elemen
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi Bubble Sort
void bubbleSort(int arr[], int n, int ascending) {
    printf("Proses Bubble Sort:\n");
    int i, j, swap;
    for(i = 0; i < n; i++){
      for(j=0; j < n-i-1; j ++){
        if((ascending && arr[j] >  arr[j+1]) || (!ascending && arr[j] < arr[j+1])){
          swap = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = swap;
        }
      }
      printf("Iterasi ke-%d: ", i+1);
      for(int k = 0; k < n; k++){
        printf("%d ", arr[k]);
      }
        printf("\n");
    }
  }

// Fungsi Insertion Sort
void insertionSort(int arr[], int n) {
    printf("\nData awal: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	for(int i=1; i < n; i++){
		printf("Iterasi ke-%d: ", i);
		for(int j=i; j>0 && arr[j] < arr[j-1]; j--){
			int swap=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=swap;
		}
		for (int m = 0; m < n; m++)
		{
			printf("%d ", arr[m]);
		}
		printf("\n");
	}
}

// Fungsi Selection Sort
int selectionSort(int arr[], int n){
    printf("\nSebelum diurutkan: \n");
    for(int i = 0; i < n; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
  
    int i, j, posisi, swap;
    for(i = 0; i < (n-1); i++){
      posisi = i;
      for (j = i + 1; j < n; j++){
        if(arr[posisi] > arr[j]){
          posisi = j;
        }
      }
      if(posisi != i){
        swap = arr[i];
        arr[i] = arr[posisi];
        arr[posisi] = swap;
      }
      printf("Iterasi ke-%d: ", i + 1);
        for(int k = 0; k < n; k++){
          printf("%d ", arr[k]);
        }
        printf("\n");
    }
  }
  

// Fungsi Merge untuk Merge Sort
void merge(int arr[], int kiri, int tngh, int kanan) {
    int i, j, k;
    int n1 = tngh - kiri + 1; 
    int n2 = kanan - tngh;    

    int kiriArr[n1], kananArr[n2];

    for (i = 0; i < n1; i++)
        kiriArr[i] = arr[kiri + i];
    for (j = 0; j < n2; j++)
        kananArr[j] = arr[tngh + 1 + j];

    
    i = 0; 
    j = 0; 
    k = kiri; 
    printf("\nProses penggabungan:\n");
    printf("  Kiri  : ");
    for (int x = 0; x < n1; x++) {
        printf("%d ", kiriArr[x]);
    }
    printf("\n  Kanan : ");
    for (int x = 0; x < n2; x++) {
        printf("%d ", kananArr[x]);
    }
    printf("\n");

    while (i < n1 && j < n2) {
        if (kiriArr[i] <= kananArr[j]) {
            arr[k] = kiriArr[i];
            i++;
        } else {
            arr[k] = kananArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = kiriArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = kananArr[j];
        j++;
        k++;
    }

    printf("  Penggabungan: ");
    for (int x = kiri; x <= kanan; x++) {
        printf("%d ", arr[x]);
    }
    printf("\n");
}

// Fungsi untuk mengimplementasikan merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Fungsi Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Fungsi Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("\nPivot %d: ", arr[pi]);
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi utama/menu
int main() {
    int choice, n;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    int arr[n], temp[n];
    printf("Masukkan elemen array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        for (int i = 0; i < n; i++) temp[i] = arr[i];

        printf("\nMenu Sorting:\n");
        printf("1. Bubble Sort Ascending\n");
        printf("2. Bubble Sort Descending\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(temp, n, 1);
                printf("Hasil Akhir: ");
                printArray(temp, n);
                break;
            case 2:
                bubbleSort(temp, n, 0);
                printf("Hasil Akhir: ");
                printArray(temp, n);
                break;
            case 3:
                insertionSort(temp, n);
                printf("Hasil Akhir: ");
                printArray(temp, n);
                break;
            case 4:
                selectionSort(temp, n);
                printf("Hasil Akhir: ");
                printArray(temp, n);
                break;
            case 5:
                printf("Proses Merge Sort:\n");
                mergeSort(temp, 0, n - 1);
                printf("Hasil Akhir: ");
                printArray(temp, n);
                break;
            case 6:
                printf("Proses Quick Sort:\n");
                quickSort(temp, 0, n - 1);
                printf("Hasil Akhir: ");
                printArray(temp, n);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}
