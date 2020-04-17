#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#define next(P) P->next_relasi
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
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);

address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);

#endif // LIST_RELASI_H_INCLUDED
