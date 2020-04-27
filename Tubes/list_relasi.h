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
void createListRelasi(List_relasi &L);/// I Wayan Adi Wahyudi (1301194084)
void insertFirstRelasi(List_relasi &L, adr_relasi P);/// I Wayan Adi Wahyudi (1301194084)
void insertLastRelasi(List_relasi &L, adr_relasi P);/// I Wayan Adi Wahyudi (1301194084)
void insertAfterRelasi(adr_relasi Prec, adr_relasi P);/// I Wayan Adi Wahyudi (1301194084)
void deleteFirstRelasi(List_relasi &L, adr_relasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(adr_relasi Prec, adr_relasi &P);

adr_relasi alokasiRelasi( adr_parent P, adr_child C);/// I Wayan Adi Wahyudi (1301194084)
void dealokasiRelasi(adr_relasi &P);
adr_relasi findElmRelasi(List_relasi L, int diC, int diP);
void printRelasi(List_relasi L);/// I Wayan Adi Wahyudi (1301194084)


void bersih();/// I Wayan Adi Wahyudi (1301194084)
void case3 (List_child &LC,List_parent &LP,List_relasi &LR,adr_child &AC,adr_parent &AP,adr_relasi &AR);/// I Wayan Adi Wahyudi (1301194084)
adr_relasi cariParentDiRelasi(List_relasi LR,int x);
adr_relasi cariChildDiRelasi(List_relasi LR,int x);
void deleteParentdiRelasi(List_relasi &LR,int AP);
void deleteChilDiRelasi(List_relasi &LR, int AP);
void deleteListRelasi(List_relasi &LR,int Par,int Chi);

void printChildTOParent(List_relasi &LR,int X);/// I Wayan Adi Wahyudi (1301194084)
void hitungHargaKaset(List_relasi &L,List_child &LC);/// I Wayan Adi Wahyudi (1301194084)
void jenisKasetFavorit(List_relasi &L, adr_relasi P);

void Child4EachParent(List_relasi &LR,List_parent &LP);/// I Wayan Adi Wahyudi (1301194084)
#endif // LIST_RELASI_H_INCLUDED
