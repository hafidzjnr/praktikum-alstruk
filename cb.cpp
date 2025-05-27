#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NIL NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define Pertama(L) ((L).Pertama)

typedef struct {
    long long nim;
    char nama[50];
} InfoType;

typedef struct tElmtList *Address;
typedef struct tElmtList {
    InfoType info;
    Address next;
} ElmtList;

typedef struct {
    Address Pertama;
} List;

/********************** FUNGSI DASAR **********************/
bool ApakahKosong(List *L) {
    return Pertama(*L) == NIL;
}

void BuatList(List *L) {
    Pertama(*L) = NIL;
}

Address Alokasi(InfoType X) {
    Address P = (Address)malloc(sizeof(ElmtList));
    if (P != NIL) {
        info(P) = X;
        next(P) = NIL;
    }
    return P;
}

void Dealokasi(Address P) {
    free(P);
}

/********************** OPERASI LIST **********************/
Address Cari(List L, long long nim) {
    Address P = Pertama(L);
    while (P != NIL) {
        if (info(P).nim == nim)
            return P;
        P = next(P);
    }
    return NIL;
}

void SisipTerurut(List *L, InfoType data) {
    Address nodeBaru = Alokasi(data);
    if (nodeBaru == NIL) return;

    // Jika list kosong atau sisip di depan
    if (ApakahKosong(L) || data.nim < info(Pertama(*L)).nim) {
        next(nodeBaru) = Pertama(*L);
        Pertama(*L) = nodeBaru;
        return;
    }

    // Cari posisi sisip
    Address sekarang = Pertama(*L);
    Address sebelumnya = NIL;
    
    while (sekarang != NIL && info(sekarang).nim < data.nim) {
        sebelumnya = sekarang;
        sekarang = next(sekarang);
    }
    
    // Sisip di antara node atau di akhir
    next(sebelumnya) = nodeBaru;
    next(nodeBaru) = sekarang;
}

void TampilkanList(List L) {
    printf("\nDaftar Mahasiswa:\n");
    printf("---------------------------------\n");
    printf("NIM\t\tNama\n");
    printf("---------------------------------\n");
    
    Address P = Pertama(L);
    while (P != NIL) {
        printf("%-12lld\t%s\n", info(P).nim, info(P).nama);
        P = next(P);
    }
    printf("---------------------------------\n");
}

void CariBerdasarkanNIM(List L) {
    long long nimCari;
    printf("\nMasukkan NIM yang dicari: ");
    scanf("%lld", &nimCari);
    
    Address hasil = Cari(L, nimCari);
    if (hasil != NIL) {
        printf("\n[Hasil Pencarian]\nNIM: %lld\nNama: %s\n", 
              info(hasil).nim, info(hasil).nama);
    } else {
        printf("\nData dengan NIM %lld tidak ditemukan\n", nimCari);
    }
}

void HapusBerdasarkanNIM(List *L) {
    long long nimHapus;
    printf("\nMasukkan NIM yang akan dihapus: ");
    scanf("%lld", &nimHapus);
    
    Address sebelumnya = NIL;
    Address sekarang = Pertama(*L);
    
    // Cari node yang akan dihapus
    while (sekarang != NIL && info(sekarang).nim != nimHapus) {
        sebelumnya = sekarang;
        sekarang = next(sekarang);
    }
    
    if (sekarang == NIL) {
        printf("\nData dengan NIM %lld tidak ditemukan\n", nimHapus);
        return;
    }
    
    // Sesuaikan pointer
    if (sebelumnya == NIL) {
        Pertama(*L) = next(sekarang);
    } else {
        next(sebelumnya) = next(sekarang);
    }
    
    Dealokasi(sekarang);
    printf("\nData dengan NIM %lld berhasil dihapus\n", nimHapus);
}

/********************** PROGRAM UTAMA **********************/
int main() {
    List daftarMhs;
    BuatList(&daftarMhs);
    
    // Data awal
    InfoType data[] = {
        {24700624706, "Agung Putra"},
        {247006022812, "Helva"},
        {247006022809, "Andreas"},
        {247006022801, "Bram"}
    };
    
    // Memasukkan data ke list
    for (int i = 0; i < 4; i++) {
        SisipTerurut(&daftarMhs, data[i]);
    }
    
    // Menu interaktif
    int pilihan;
    do {
        printf("\n=== MENU MANAJEMEN DATA MAHASISWA ===\n");
        printf("1. Tampilkan Seluruh Data\n");
        printf("2. Cari Berdasarkan NIM\n");
        printf("3. Hapus Data\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1:
                TampilkanList(daftarMhs);
                break;
            case 2:
                CariBerdasarkanNIM(daftarMhs);
                break;
            case 3:
                HapusBerdasarkanNIM(&daftarMhs);
                break;
            case 4:
                printf("\nProgram selesai\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while(pilihan != 4);
    
    return 0;
}