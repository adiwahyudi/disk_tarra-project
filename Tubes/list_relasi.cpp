#include "list_relasi.h"

void createList(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}
void insertFirst(List_relasi &L, adr_relasi P){
    if (first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
        P = last(L);
    } else {
        first(L) = P;
        next(P) = NULL;
    }
}

void insertLast(List_relasi &L, adr_relasi P){
    if (first(L) != NULL){
        insertFirst(L,P);
    } else {
        adr_relasi Q = first(L);
        while ( Q != NULL ){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
        P = last(L);
    }
}

void insertAfter(adr_relasi Prec, adr_relasi P){

}

void deleteFirst(List_relasi &L, adr_relasi &P){
    adr_relasi Q;
    if(first(L) != NULL){
        P = first(L);
        if (next(P) == first(L)){
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

void deleteLast(List_relasi &L, adr_relasi &P){

    adr_relasi Q = first(L);

    while(next(next(Q)) != NULL ) {
            Q = next(Q);
    }

    P = next(Q);
    next(P) = NULL;
}

void deleteAfter(adr_relasi Prec, adr_relasi &P){

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
