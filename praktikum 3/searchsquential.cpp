#include <stdio.h>
#include <conio.h>
#include <process.h>

int main()
{
    //Deklarasi variabel
    int arr[10] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
    int h = 9; // data yang dicari
    int i, j;

    printf("Mencari data %d dalam array...\n", h);
    for(i = 0; i < 10; i++) {
        printf("Data ke-%d: %d", i + 1, arr[i]);
        printf("\n");
    }

    j = 0;
    for (i = 0; i < 10; i++) //pencarian sekuensial dalam array
    {
        if (arr[i] == h)
        {
            j = 1;
            break;
        }
    }

    //output pencarian
      if (j == 1)
      {
        //jika data ditemukan
          printf("Data %d ditemukan pada indeks ke-%d\n", h, i);
      }
      //jika data tidak ditemukan
      else{
          printf("Data %d tidak ditemukan dalam array\n", h);
      }

    getch();
    return 0;
}