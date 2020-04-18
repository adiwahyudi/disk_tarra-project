#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#define next_relasi(P) P->next_relasi
#define first_relasi(L) L.first_relasi
#define child(P) P->child
#define parent(P) P->parent

#include "list_parent.h"
#include "list_child.h"

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi {
    address_child child;
    address_parent parent;
    address_relasi next;
};

struct List_relasi {
    address_relasi first;
};
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);

address_relasi alokasi( address_parent P, address_child C);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
void printInfo(List_relasi L);

#endif // LIST_RELASI_H_INCLUDED
