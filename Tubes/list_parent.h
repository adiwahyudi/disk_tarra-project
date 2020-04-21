/// Parent as Single Linked List and Kaset

#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>

#define first_parent(L) L.first_parent
#define last_parent(L) L.last_parent
#define next_parent(P) P->next_parent
#define info_parent(P) P->info_parent

using namespace std;

typedef int infotype_parent;
typedef struct elmlist_parent *adr_parent;

struct elmlist_parent {
    infotype_parent info_parent;
    adr_parent next_parent;
};

struct List_parent {
    adr_parent first_parent;
    adr_parent last_parent;
};

void createList(List_parent &L);
void insertFirstParent(List_parent &L, adr_parent P);
void insertAfterParent(adr_parent Prec, adr_parent P);
void insertLastParent(List_parent &L, adr_parent P);
void deleteFirstParent(List_parent &L, adr_parent &P);
void deleteLastParent(List_parent &L, adr_parent &P);
void deleteAfterParent(adr_parent Prec, adr_parent &P);

adr_parent alokasi(infotype_parent x);
void dealokasi(adr_parent &P);
adr_parent findElm(List_parent L, infotype_parent x);
void printParent(List_parent L);
#endif // LIST_PARENT_H_INCLUDED
