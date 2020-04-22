/// Child as Double Circular Linked List and Penyewa
#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last

#define info(P) P->info

using namespace std;

struct InfoPenyewa {
    NoIdent string;
    Nama string;
};

typedef Penyewa infotype_child;
typedef struct elmlist_child *adr_child;

struct elmlist_child{
    infotype_child info;
    adr_child next;
    adr_child prev;
};

struct List_child{
    adr_child first;
    adr_child last;
};

void createList(List_child &L);
void insertFirst(List_child &L, adr_child P);
void insertLast(List_child &L, adr_child P);
void insertAfter(adr_child Prec, adr_child P);
void deleteFirst(List_child &L, adr_child &P);
void deleteLast(List_child &L, adr_child &P);
void deleteAfter(List_child &L,adr_child Prec, adr_child &P);

adr_child alokasi(infotype_child x);
void dealokasi(adr_child &P);
adr_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);


#endif // LIST_CHILD_H_INCLUDED
