#include <stdio.h>
#include <conio.h>
#include <process.h>

int main()
{
    int data[10] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
    int cari = 9;
    int i, ketemu;

    printf("Mencari data %d dalam array...\n", cari);
    for(i = 0; i < 10; i++) {
        printf("Data ke-%d: %d", i + 1, data[i]);
        printf("\n");
    }

    ketemu = 0;
    for (i = 0; i < 10; i++)
    {
        if (data[i] == cari)
        {
            ketemu = 1;
            break;
        }
    }

    if (ketemu == 1)
    {
        printf("Data %d ditemukan pada indeks ke-%d\n", cari, i);
    }
    else
    {
        printf("%d tidak ditemukan dalam array\n", cari);
    }

    getch();
    return 0;
}