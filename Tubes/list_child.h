#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <iostream>
#define next_child(P) P->next_child
#define prev_child(P) P->prev_child
#define first_child(L) L.first_child
#define last_child(L) L.last_child
#define info_child(P) P->info_child

using namespace std;

typedef string infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
    address_child last;
};

void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);

address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);


#endif // LIST_CHILD_H_INCLUDED
