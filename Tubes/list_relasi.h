#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>

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
void createList(List_relasi &L);
void insertFirst(List_relasi &L, adr_relasi P);
void insertLast(List_relasi &L, adr_relasi P);
void insertAfter(adr_relasi Prec, adr_relasi P);
void deleteFirst(List_relasi &L, adr_relasi &P);
void deleteLast(List_relasi &L, adr_relasi &P);
void deleteAfter(adr_relasi Prec, adr_relasi &P);

adr_relasi alokasi( adr_parent P, adr_child C);
void dealokasi(adr_relasi &P);
adr_relasi findElm(List_relasi L, adr_parent P, adr_child C);
void printInfo(List_relasi L);

#endif // LIST_RELASI_H_INCLUDED
