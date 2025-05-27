/* file : list1.h */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* representasi address dengan pointer */
/* infotype adalah Student */
#ifndef list1_H
#define list1_H
#include <stdio.h>
#include "boolean.h"

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

typedef struct {
    long long nim;
    char name[50];
} Student;

typedef Student infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

/* Definisi list */
/* List kosong : First (L) = Nil */
/* setiap elemen dengan address P dapat diacu info(P), next(P) */
/* Element terakhir list : jika addressny Last, maka Next(Last) = Nil */
typedef struct {
    address First;
} List;

/* PROTOTYPE */
/******************* Test List Kosong *********************/
boolean IsEmpty(List *L);
/* mengirim true jika list kosong */

/******************* Pembuatan list kosong *********************/
void CreateList(List *L);
/* I.S sembarang */
/* F.S terbentuk list kosong */

/****************** Manajemen Memori *********************/
address Alokasi(infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi(address P);
/* I.S P terdefinisi */
/* F.S P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** Pencarian *********************/
address Search(List L, infotype X);
/* Mencari apakah ada elemen list dengan info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

boolean FSearch(List L, address P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

address SearchPrec(List L, infotype X, address *Prec);
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */

/****************** Primitif Berdasarkan Nilai *********************/
void InsertFirst(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsertAfter(List *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/****************** Display *********************/
void PrintInfo(List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */

/****************** Operations *********************/
void InsertAscending(List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di posisi yang sesuai dengan nilai X jika alokasi berhasil */

void DisplayList(List L);
/* I.S. List mungkin kosong */
/* F.S. Menampilkan semua elemen list */

void SearchByNim(List L, long long nim);
/* I.S. List mungkin kosong */
/* F.S. Mencari elemen berdasarkan nim */

void DeleteByNim(List *L, long long nim);
/* I.S. List mungkin kosong */
/* F.S. Menghapus elemen berdasarkan nim */

#endif