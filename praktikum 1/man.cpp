#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() {
    char pita[MAX + 1];
    int posisi[256][MAX]; // Menyimpan posisi kemunculan tiap karakter
    int jumlah[256] = {0}; // Menyimpan jumlah kemunculan tiap karakter
    int index = 1; // Penomoran karakter (bukan spasi)
    
    printf("Masukkan pita karakter (maks 100 karakter, diakhiri titik):\n");
    fgets(pita, sizeof(pita), stdin);

    int panjang = strlen(pita);
    int kosong = 1;

    for (int i = 0; i < panjang; i++) {
        char c = pita[i];

        if (c == '.') break;

        if (c == ' ') continue;

        kosong = 0;
        posisi[(int)c][jumlah[(int)c]++] = index++;
    }

    if (kosong) {
        printf("Pita kosong, tidak ada isinya\n");
        return 0;
    }

    // Tampilkan output sesuai urutan abjad
    for (char c = 'a'; c <= 'z'; c++) {
        if (jumlah[(int)c] > 0) {
            printf("%c :\n", c);
            for (int j = 0; j < jumlah[(int)c]; j++) {
                printf(" %d\n", posisi[(int)c][j]);
            }
            printf("Muncul %d kali\n\n", jumlah[(int)c]);
        }
    }

    return 0;
}