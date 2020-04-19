/// Child as Double Circular Linked List and Penyewa
#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteFirst(List_child &L, address_child &P){
    if(first(L) != NULL){
        P = first(L);
        if(P = last(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            next(P) = NULL;
            prev(first(L)) = NULL;
        }
    }
}

void deleteLast(List_child &L, address_child &P){
    if(first(L) != NULL){
        P = last(L);
        if(P = last(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(P);
            prev(P) = NULL;
            next(last(L)) = NULL;
        }
    }
}

void deleteAfter(List_child &L, address_child Prec, address_child &P){
    if((first(L) != NULL)&&(Prec != NULL)){
        if(Prec != last(L)){
            if(next(Prec) = last(L)){
                deleteLast(L,P);
            } else {
                P = next(Prec);
                next(Prec) = next(P);
                prev(next(P)) = Prec;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P)<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
