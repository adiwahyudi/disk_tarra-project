#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#define next(P) P->next

#define first(L) L.first
#define last(L) L.last

#define child(P) P->child
#define parent(P) P->parent

#include "list_parent.h"
#include "list_child.h"

typedef struct elmlist_relasi *adr_relasi;

struct elmlist_relasi {
    adr_child child;
    adr_parent parent;
    adr_relasi next;
};

struct List_relasi {
    adr_relasi first;
    adr_relasi last;
};
void createListRelasi(List_relasi &L);
void insertFirstRelasi(List_relasi &L, adr_relasi P);
void insertLastRelasi(List_relasi &L, adr_relasi P);
void insertAfterRelasi(adr_relasi Prec, adr_relasi P);
void deleteFirstRelasi(List_relasi &L, adr_relasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(adr_relasi Prec, adr_relasi &P);

adr_relasi alokasiRelasi( adr_parent P, adr_child C);
void dealokasiRelasi(adr_relasi &P);
adr_relasi findElm(List_relasi L, adr_parent P, adr_child C);
void printRelasi(List_relasi L);

void bersih();
#endif // LIST_RELASI_H_INCLUDED
