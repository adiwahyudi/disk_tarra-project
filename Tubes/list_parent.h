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

void createListParent(List_parent &L);///Muhammad Ikram Kaer Sinapoy(1301193341)
void insertFirstParent(List_parent &L, adr_parent P);///Muhammad Ikram Kaer Sinapoy(1301193341)
void insertAfterParent(List_parent &L, adr_parent Prec, adr_parent P);///Muhammad Ikram Kaer Sinapoy(1301193341)
void insertLastParent(List_parent &L, adr_parent P);///Muhammad Ikram Kaer Sinapoy(1301193341)
void deleteFirstParent(List_parent &L, adr_parent &P);///Muhammad Ikram Kaer Sinapoy(1301193341)
void deleteLastParent(List_parent &L, adr_parent &P);///Muhammad Ikram Kaer Sinapoy(1301193341)
void deleteAfterParent(List_parent &L, adr_parent Prec, adr_parent &P);///Muhammad Ikram Kaer Sinapoy(1301193341)

void insertSortParent(List_parent &L,adr_parent Q);///Muhammad Ikram Kaer Sinapoy(1301193341)
void deleteListParent(List_parent &L, int x);///Muhammad Ikram Kaer Sinapoy(1301193341)

adr_parent alokasiParent(infotype_parent x);///Muhammad Ikram Kaer Sinapoy(1301193341)
void dealokasiParent(adr_parent &P);///Muhammad Ikram Kaer Sinapoy(1301193341)
adr_parent findElmParent(List_parent L, int x);///Muhammad Ikram Kaer Sinapoy(1301193341)
void printParent(List_parent L);///Muhammad Ikram Kaer Sinapoy(1301193341)

int randomkodeKaset();///Muhammad Ikram Kaer Sinapoy(1301193341)
void case2(List_parent &LP,infotype_parent &ITP);///Muhammad Ikram Kaer Sinapoy(1301193341)

#endif // LIST_PARENT_H_INCLUDED
