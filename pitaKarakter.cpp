#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char pita[101];
    printf("Masukkan pita karakter (maksimum 100 karakter, diakhiri dengan titik(.)\nInput: ");
    fgets(pita, sizeof(pita), stdin);

    // Validasi jika pita kosong atau hanya berisi titik
    if (pita[0] == '.' || pita[0] == '\n') {
        printf("Pita kosong, tidak ada isinya\n");
        return 0;
    }

    int jumlahHuruf[26] = {0}; // Menyimpan jumlah kemunculan setiap huruf
    int posisiHuruf[26][100];  // Menyimpan posisi kemunculan setiap huruf
    int nomorUrut = 1;         // Nomor urut karakter pada pita

    for (int i = 0; pita[i] != '\0'; i++) {
        char c = pita[i];
        if (c == '.') break;  // Berhenti membaca saat menemukan titik
        if (c == ' ') continue; // Abaikan karakter 'blank'

        if (isalpha(c)) { // Hanya proses huruf
            int index = tolower(c) - 'a';
            posisiHuruf[index][jumlahHuruf[index]] = nomorUrut;
            jumlahHuruf[index]++;
        }
        nomorUrut++;
    }

    printf("\nOutput:\n");

    // Jika tidak ada huruf yang ditemukan
    int adaHuruf = 0;
    for (int i = 0; i < 26; i++) {
        if (jumlahHuruf[i] > 0) {
            adaHuruf = 1;
            printf("%c : ", i + 'a');
            for (int j = 0; j < jumlahHuruf[i]; j++) {
                printf("%d ", posisiHuruf[i][j]);
            }
            printf("\nMuncul %d kali\n", jumlahHuruf[i]);
        }
    }

    if (!adaHuruf) {
        printf("Pita kosong, tidak ada isinya\n");
    }

    return 0;
}
//Nama : Hafidz Januar Faturahman
//NPM : 247006111077
//Kelas : C
