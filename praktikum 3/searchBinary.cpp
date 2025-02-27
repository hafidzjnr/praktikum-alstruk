#include <stdio.h>
#include <conio.h>

int main(){
  int arr[10] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22}; //proses ascending
  int i, tar, awal = 0, akhir = 10, tengah;
    printf("Data array : "); //menampilkan data array
      for(i = 0; i < 10; i++)
      {
        printf("%d ", arr[i]);
      }

  tar = 9; //data yang dicari
  printf("\nData yang dicari : %d\n", tar);
  //proses pencarian binary
  while (awal <= akhir)
  {
    tengah = (awal + akhir) /2;
    if (tar > arr[tengah]) // descending tanda > menjadi <
    {
      awal = tengah +1; 
    }
    else if (tar < arr[tengah]) // descending tanda < menjadi >
    {
      akhir = tengah -1; 
    }
    else 
    {
      break; 
    }
  }

    if (tar == arr[tengah])
    {
      printf("Data ditemukan pada indeks ke-%d", tengah);
    }else{
      printf("Data tidak ditemukan");
    }

  getch();
  return 0;
}
