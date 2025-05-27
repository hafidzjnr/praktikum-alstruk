#include "list1.h"
#include <stdio.h>
#include <string.h>

int main() {
    List L;
    CreateList(&L);
    
    // Initial data (Agung Putra) no 2
    Student mhs1 = {24700624706, "Agung Putra"};
    InsertAscending(&L, mhs1);
    
    // Additional data from table no 3
    Student mhs2 = {24700602812, "Helva"};
    Student mhs3 = {24700602809, "Andreas"};
    Student mhs4 = {24700602801, "Bram"};
    
    // Insert data in ascending order 
    InsertAscending(&L, mhs2);
    InsertAscending(&L, mhs3);
    InsertAscending(&L, mhs4);
    
    // Display all nodes no 4
    printf("\nMenampilkan semua data:\n");
    DisplayList(L);
    
    // Search by NIM (with user input) no 5
    long long searchNim;
    printf("\nMasukkan NIM yang ingin dicari: ");
    scanf("%lld", &searchNim);
    printf("\nMencari data dengan NIM %lld:\n", searchNim);
    SearchByNim(L, searchNim);
    
    // Delete a node (with user input) no 6
    long long deleteNim;
    printf("\nMasukkan NIM yang ingin dihapus: ");
    scanf("%lld", &deleteNim);
    printf("nim yang ingin kamu hapus: %lld\n", deleteNim);
    DeleteByNim(&L, deleteNim);
    
    // Display final list after deletion
    printf("\nData setelah penghapusan:\n");
    DisplayList(L);
    
    return 0;
}