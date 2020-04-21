#include "list_relasi.h"

void createList(List_relasi &L){
    first_relasi(L) = NULL;
    last_relasi(L) = NULL;
}
void insertFirst(List_relasi &L, adr_relasi P){
    if (first_relasi(L) != NULL){
        next_relasi(P) = first_relasi(L);
        first_relasi(L) = P;
        P = last_relasi(L);
    } else {
        first_relasi(L) = P;
        next_relasi(P) = NULL;
    }
}

void insertLast(List_relasi &L, adr_relasi P){
    if (first_relasi(L) != NULL){
        insertFirst(L,P);
    } else {
        adr_relasi Q = first_relasi(L);
        while ( Q != NULL ){
            Q = next_relasi(Q);
        }
        next_relasi(Q) = P;
        next_relasi(P) = NULL;
        P = last_relasi(L);
    }
}

void insertAfter(adr_relasi Prec, adr_relasi P){

}

void deleteFirst(List_relasi &L, adr_relasi &P){
    adr_relasi Q;
    if(first_relasi(L) != NULL){
        P = first_relasi(L);
        if (next_relasi(P) == first_relasi(L)){
            next_relasi(P) = NULL;
            first_relasi(L) = NULL;
        } else {
            Q = first_relasi(L);
            while(next_relasi(Q) != first_relasi(L)){
                Q = next_relasi(Q);
            }
            first_relasi(L) = next_relasi(P);
            next_relasi(Q) = next_relasi(P);
            next_relasi(P) = NULL;
        }
    }
}

void deleteLast(List_relasi &L, adr_relasi &P){

    adr_relasi Q = first_relasi(L);

    while(next_relasi(next_relasi(Q)) != NULL ) {
            Q = next_relasi(Q);
    }

    P = next_relasi(Q);
    next_relasi(P) = NULL;
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
    adr_relasi Q = first_relasi(L);
    while (Q != NULL) {
        if ( info_parent(parent(Q)) == P && info_child(child(Q)) == C){
            return Q;
        }
        Q = next_relasi(Q);
    }
}

void printInfo(List_relasi L){
    adr_relasi P = first_relasi(L);
    while (P != NULL){
        cout << "nanti" << endl;
        P = next_relasi(P);
    }

}
