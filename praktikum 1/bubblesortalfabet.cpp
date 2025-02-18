// nama file : Alstruk_BubleSort1

#include <stdio.h>

void bubbleSort(char arr[], int n){
  int i, j;
char tmp;
  for(i = 0; i < n; i++){
    for(j=0; j < n-i-1; j ++){
      if(arr[j] >  arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

int main() {
  char array[100], n, i, j;
  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);

  printf("Masukkan huruf satu persatu: \n");
  for(i = 0; i < n; i ++){
    printf("Huruf ke-%d: ", i+1);
    scanf(" %c", &array[i]);
  }

  bubbleSort(array, n);

  printf("Hasil pengurutan sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%c ", array[i]);
  }
  printf("\n");
}
