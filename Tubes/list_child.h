/// Child as Double Circular Linked List and Pembeli
#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last

#define info(P) P->info
using namespace std;

struct InfoPenyewa {
    string NoIdent;
    string Nama;
    int memberID;
};

typedef InfoPenyewa infotype_child;
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

void createListChild(List_child &L); /// I Wayan Adi Wahyudi (1301194084)
void insertFirstChild(List_child &L, adr_child P); /// I Wayan Adi Wahyudi (1301194084)
void insertLastChild(List_child &L, adr_child P); /// I Wayan Adi Wahyudi (1301194084)
void insertAfterChild(List_child &L, adr_child &Prec, adr_child P); /// I Wayan Adi Wahyudi (1301194084)
void deleteFirstChild(List_child &L, adr_child &P); /// I Wayan Adi Wahyudi (1301194084)
void deleteLastChild(List_child &L, adr_child &P); /// I Wayan Adi Wahyudi (1301194084)
void deleteAfterChild(List_child &L,adr_child Prec, adr_child &P); /// I Wayan Adi Wahyudi (1301194084)

void insertSortChild(List_child &L, adr_child Q); /// I Wayan Adi Wahyudi (1301194084)
void deleteListChild(List_child &L, int x); /// I Wayan Adi Wahyudi (1301194084)

adr_child alokasiChild(infotype_child x); /// I Wayan Adi Wahyudi (1301194084)
void dealokasiChild(adr_child &P); /// I Wayan Adi Wahyudi (1301194084)
adr_child findElmChild(List_child L, int x); /// I Wayan Adi Wahyudi (1301194084)
void printChild(List_child L); /// I Wayan Adi Wahyudi (1301194084)

int randomIDmember(); /// I Wayan Adi Wahyudi (1301194084)
void case1(List_child &L,infotype_child &ITC); /// I Wayan Adi Wahyudi (1301194084)

#endif // LIST_CHILD_H_INCLUDED
