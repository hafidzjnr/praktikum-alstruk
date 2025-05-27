#include "list1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

boolean IsEmpty(List *L) {
    return (First(*L) == Nil) ? TRUE : FALSE;
}

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (info(P).nim == X.nim) {
            return P;
        }
        P = next(P);
    }
    return Nil;
}

boolean FSearch(List L, address P) {
    address Q = First(L);
    while (Q != Nil) {
        if (Q == P) {
            return TRUE;
        }
        Q = next(Q);
    }
    return FALSE;
}

address SearchPrec(List L, infotype X, address *Prec) {
    address P = First(L);
    *Prec = Nil;
    
    // Handle empty list or if X is first element
    if (P == Nil || info(P).nim == X.nim) {
        return P;
    }
    
    // Search through the list
    while (next(P) != Nil && info(next(P)).nim != X.nim) {
        P = next(P);
    }
    
    if (next(P) == Nil) {
        return Nil;
    } else {
        *Prec = P;
        return next(P);
    }
}

void InsertFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (P != Nil) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void InsertLast(List *L, infotype X) {
    if (IsEmpty(L)) {
        InsertFirst(L, X);
    } else {
        address P = Alokasi(X);
        if (P != Nil) {
            address last = First(*L);
            while (next(last) != Nil) {
                last = next(last);
            }
            next(last) = P;
        }
    }
}
//mulai lagi besok
void InsertAscending(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(L) || info(First(*L)).nim > X.nim) {
            // Insert at beginning
            next(P) = First(*L);
            First(*L) = P;
        } else {
            // Find position to insert
            address curr = First(*L);
            while (next(curr) != Nil && info(next(curr)).nim < X.nim) {
                curr = next(curr);
            }
            next(P) = next(curr);
            next(curr) = P;
        }
    }
}

void PrintInfo(List L) {
    if (IsEmpty(&L)) {
        printf("List kosong\n");
    } else {
        address P = First(L);
        printf("\nIsi List:\n");
        printf("NIM\t\t\tNama\n");
        printf("--------------------------------\n");
        while (P != Nil) {
            printf("%lld\t%s\n", info(P).nim, info(P).name);
            P = next(P);
        }
        printf("--------------------------------\n");
    }
}

void DisplayList(List L) {
    if (IsEmpty(&L)) {
        printf("List kosong\n");
    } else {
        address P = First(L);
        printf("\nNim\t\t\tNama\n");
        while (P != Nil) {
            printf("%lld\t\t%s\n", info(P).nim, info(P).name);
            P = next(P);
        }
    }
}

void SearchByNim(List L, long long nim) {
    address P = First(L);
    printf("searching\n");
    while (P != Nil) {
        if (info(P).nim == nim) {
            printf("nama ditemukan : %s\n", info(P).name);
            return;
        }
        P = next(P);
    }
    printf("nama tidak ditemukan\n");
}

void DeleteByNim(List *L, long long nim) {
    if (!IsEmpty(L)) {
        address P = First(*L);
        address prev = Nil;
        
        printf("searching\n");
        
        // If first node is the one to be deleted
        if (P != Nil && info(P).nim == nim) {
            First(*L) = next(P);
            Dealokasi(P);
            printf("nim teridentifikasi dan berhasil dihapus\n");
            return;
        }
        
        // Search for the node to be deleted
        while (P != Nil && info(P).nim != nim) {
            prev = P;
            P = next(P);
        }
        
        // If NIM was not found
        if (P == Nil) {
            printf("nim tidak ditemukan\n");
            return;
        }
        
        // Remove the node
        next(prev) = next(P);
        Dealokasi(P);
        printf("nim teridentifikasi dan berhasil dihapus\n");
    }
}