/// Parent as Single Linked List and Kaset
#include "list_parent.h"

void createList(List_parent &L) {
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P){
    if((first(L) != NULL) && (Prec != NULL)){
        if(next(Prec) = first(L)){
            insertLast(L,P);
        } else {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

void insertLast(List_parent &L, address_parent P){
    address_parent Q;
    if(first(L) = NULL){
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}
void deleteFirst(List_parent &L, address_parent &P){
    address_parent Q;
     if(first(L) != NULL){
        P = first(L);
        if(next(P) = first(L)){
            next(P) = NULL;
            first(L) = NULL;
        } else {
            Q = first(L);
            while(next(Q) != first(L)){
                Q = next(Q);
            }
            first(L) = next(P);
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
}
void deleteLast(List_parent &L, address_parent &P){
    address_parent Q;
    if(first(L) != NULL){
        P = first(L);
        if(next(P) = first(L)){
            next(P) = NULL;
            first(L) = NULL;
        } else {
            Q = first(L);
            while(next(next(Q)) != first(L)){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    if(first(L) != NULL && (Prec != NULL)){
        if(next(Prec) = first(L)){
            deleteFirst(L,P);
        } else {
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}


void printInfo(List_parent L) {
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    address_parent P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
