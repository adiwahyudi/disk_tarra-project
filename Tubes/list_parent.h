/// Parent as Single Linked List and Kaset

#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info

using namespace std;

struct InfoKaset {
    string judul;
    int tahunKaset;
    string genre;
    int harga;
    string tipe;
    int kodeKaset;
};

typedef InfoKaset infotype_parent;
typedef struct elmlist_parent *adr_parent;

struct elmlist_parent {
    infotype_parent info;
    adr_parent next;
};

struct List_parent {
    adr_parent first;
    adr_parent last;
};

void createListParent(List_parent &L);
void insertFirstParent(List_parent &L, adr_parent P);
void insertAfterParent(List_parent &L, adr_parent Prec, adr_parent P);
void insertLastParent(List_parent &L, adr_parent P);
void deleteFirstParent(List_parent &L, adr_parent &P);
void deleteLastParent(List_parent &L, adr_parent &P);
void deleteAfterParent(adr_parent Prec, adr_parent &P);

void insertSortParent(List_parent &L, infotype_parent x);
void deleteListParent(List_parent &L, infotype_parent x);

adr_parent alokasiParent(infotype_parent x);
void dealokasiParent(adr_parent &P);
adr_parent findElmParent(List_parent L, int x);
void printParent(List_parent L);

int randomkodeKaset();
void case2(List_parent &LP,infotype_parent &ITP);

#endif // LIST_PARENT_H_INCLUDED
