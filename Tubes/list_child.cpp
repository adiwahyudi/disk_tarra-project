/// Child as Double Circular Linked List and Penyewa
#include "list_child.h"

void createList(List_child &L) {
    first_child(L) = NULL;
    last_child(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info_child(P) = x;
    next_child(P) = NULL;
    prev_child(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first_child(L) == NULL) {
        first_child(L) = P;
        last_child(L) = P;
    } else {
        next_child(P) = first_child(L);
        prev_child(first_child(L)) = P;
        first_child(L) = P;
    }
}

void insertLast(List_child &L, address_child P){
    if(first_child(L) == NULL){
        first_child(L) = P;
        last_child(L) = P;
    } else {
        prev_child(P) = last_child(L);
        next_child(last_child(L)) = P;
        last_child(L) = P;
    }
}

void insertAfter(address_child &Prec, address_child P) {
    prev_child(next_child(Prec)) = P;
    next_child(P) = next_child(Prec);
    prev_child(P) = Prec;
    next_child(Prec) = P;
}

void deleteFirst(List_child &L, address_child &P){
    if(first_child(L) != NULL){
        P = first_child(L);
        if(P = last_child(L)){
            first_child(L) = NULL;
            last_child(L) = NULL;
        } else {
            first_child(L) = next_child(P);
            next_child(P) = NULL;
            prev_child(first_child(L)) = NULL;
        }
    }
}

void deleteLast(List_child &L, address_child &P){
    if(first_child(L) != NULL){
        P = last_child(L);
        if(P = last_child(L)){
            first_child(L) = NULL;
            last_child(L) = NULL;
        } else {
            last_child(L) = prev_child(P);
            prev_child(P) = NULL;
            next_child(last_child(L)) = NULL;
        }
    }
}

void deleteAfter(List_child &L, address_child Prec, address_child &P){
    if((first_child(L) != NULL)&&(Prec != NULL)){
        if(Prec != last_child(L)){
            if(next_child(Prec) = last_child(L)){
                deleteLast(L,P);
            } else {
                P = next_child(Prec);
                next_child(Prec) = next_child(P);
                prev_child(next_child(P)) = Prec;
                next_child(P) = NULL;
                prev_child(P) = NULL;
            }
        }
    }
}

void printInfo(List_child L) {
    address_child P = first_child(L);
    while(P != NULL) {
        cout<<"->"<<info_child(P)<<endl;
        P = next_child(P);
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first_child(L);
    while(P != NULL) {
        if(info_child(P)==x) {
            return P;
        }
        P = next_child(P);
    }
    return NULL;
}
