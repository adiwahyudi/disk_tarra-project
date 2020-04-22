#include "list_relasi.h"

void createList(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}
void insertFirst(List_relasi &L, adr_relasi P){
    if (first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
        last(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void insertLast(List_relasi &L, adr_relasi P){

    if (first(L) == NULL){
        insertFirst(L,P);
    } else {
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void insertAfter(adr_relasi Prec, adr_relasi P){

    next(P) = next(Prec);
    next(Prec) = P;

}

void deleteFirst(List_relasi &L, adr_relasi &P){

    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLast(List_relasi &L, adr_relasi &P){
    P = first(L);
    while ( next(P) != last(L) ) {
        P = next(P);
    }
    last(L) = P;
    P = next(P);
    next(last(L)) = NULL;
}

void deleteAfter(adr_relasi Prec, adr_relasi &P){

    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

}

adr_relasi alokasi( adr_parent P, adr_child C){

    adr_relasi Q = new elmlist_relasi;

    child(Q) = C;
    parent(Q) = P;
    return Q;
}

void dealokasi(adr_relasi &P){
    delete P;
}

adr_relasi findElm(List_relasi L, adr_parent P, adr_child C){
    adr_relasi Q = first(L);
    while (Q != NULL) {
        if ( (parent(Q)) == P && (child(Q)) == C){
            return Q;
        } else {
            Q = next(Q);
        }
    }
    return NULL;
}

void printInfo(List_relasi L){
    adr_relasi P = first(L);
    while (P != NULL){
        cout << "nanti" << endl;
        P = next(P);
    }

}
