#include "list_relasi.h"

void createList(List_relasi &L){
    first_relasi(P) = NULL;
}
void insertFirst(List_relasi &L, address_relasi P){
    if (first_relasi(L) != NULL){
        next_relasi(P) = first_relasi(L)
        first_relasi(L) = P;
    } else {
        first_relasi(P) = P;
        next_relasi(P) = NULL;
    }
}
void insertLast(List_relasi &L, address_relasi P){
    if (first_relasi(L) != NULL){

    }
}
void insertAfter(address_relasi Prec, address_relasi P){

}
void deleteFirst(List_relasi &L, address_relasi &P){
    if (first_relasi(L) != NULL){
        if(next_relasi(P) != NULL){

        }
    }
}
void deleteLast(List_relasi &L, address_relasi &P){

}
void deleteAfter(address_relasi Prec, address_relasi &P){

}
address_relasi alokasi( address_parent P, address_child C){

}
void dealokasi(address_relasi &P){

}
address_relasi findElm(List_relasi L, address_parent P, address_child C){

}
void printInfo(List_relasi L){

}
