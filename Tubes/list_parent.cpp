// Parent as Single Linked List and Kaset
#include "list_parent.h"

void createList(List_parent &L) {
    first_parent(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    address_parent P;
    P = new elmlist_parent;
    info_parent(P) = x;
    next_parent(P) = NULL;
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    address_parent Q;
    if(first_parent(L) == NULL) {
        first_parent(L) = P;
        next_parent(P) = P;
    } else {
        Q = first_parent(L);
        while(next_parent(Q) != first_parent(L)) {
            Q = next_parent(Q);
        }
        next_parent(P) = first_parent(L);
        next_parent(Q) = P;
        first_parent(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P){
    if((first_parent(L) != NULL) && (Prec != NULL)){
        if(next_parent(Prec) = first_parent(L)){
            insertLast(L,P);
        } else {
            next_parent(P) = next_parent(Prec);
            next_parent(Prec) = P;
        }
    }
}

void insertLast(List_parent &L, address_parent P){
    address_parent Q;
    if(first_parent(L) = NULL){
        first_parent(L) = P;
    } else {
        Q = first_parent(L);
        while(next_parent(Q) != first_parent(L)){
            Q = next_parent(Q);
        }
        next_parent(Q) = P;
        next_parent(P) = NULL;
    }
}

void deleteFirst(List_parent &L, address_parent &P){
    address_parent Q;
     if(first_parent(L) != NULL){
        P = first_parent(L);
        if(next_parent(P) = first_parent(L)){
            next_parent(P) = NULL;
            first_parent(L) = NULL;
        } else {
            Q = first_parent(L);
            while(next_parent(Q) != first_parent(L)){
                Q = next_parent(Q);
            }
            first_parent(L) = next_parent(P);
            next_parent(Q) = next_parent(P);
            next_parent(P) = NULL;
        }
    }
}
void deleteLast(List_parent &L, address_parent &P){
    address_parent Q;
    if(first_parent(L) != NULL){
        P = first_parent(L);
        if(next_parent(P) = first_parent(L)){
            next_parent(P) = NULL;
            first_parent(L) = NULL;
        } else {
            Q = first_parent(L);
            while(next_parent(next_parent(Q)) != first_parent(L)){
                Q = next_parent(Q);
            }
            P = next_parent(Q);
            next_parent(Q) = next_parent(P);
            next_parent(P) = NULL;
        }
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    if(first_parent(L) != NULL && (Prec != NULL)){
        if(next_parent(Prec) = first_parent(L)){
            deleteFirst(L,P);
        } else {
            P = next_parent(Prec);
            next_parent(Prec) = next_parent(P);
            next_parent(P) = NULL;
        }
    }
}


void printInfo(List_parent L) {
    address_parent P = first_parent(L);
    while(P != NULL){
        cout << info_child(P) << endl;
        P = next_parent(P);
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    address_parent P = first_parent(L);
    while ((P != NULL) && (info_parent(P) != x)){
        P = next_parent(P);
    }
    return P;
}
