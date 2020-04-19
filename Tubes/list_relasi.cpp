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
        insertFirst(L,P);
    } else {
        address_relasi Q = first_relasi(L);
        while ( Q != NULL ){
            Q = next_relasi(Q);
        }
        next_relasi(Q) = P;
        next_relasi(P) = NULL;
    }
}

void insertAfter(address_relasi Prec, address_relasi P){

}

void deleteFirst(List_relasi &L, address_relasi &P){
    address_relasi Q;
    if(first_relasi(L) != NULL){
        P = first_relasi(L);
        if (next_relasi(P) = first_relasi(L)){
            next_relasi(P) = NULL;
            first_relasi(L) = NULL;
        } else {
            Q = first_relasi((L);
            while(next_relasi(Q) != first_relasi(L)){
                Q = next_relasi((Q);
            }
            first_relasi(L) = next_relasi(P);
            next_relasi(Q) = next_relasi(P);
            next_relasi(P) = NULL;
        }
    }
}

void deleteLast(List_relasi &L, address_relasi &P){
    address_relasi Q;
    if(first_relasi(L) != NULL){
        P = first_relasi(L);
        if(next_relasi(P) = first_relasi(L)){
            next_relasi(P) = NULL;
            first_relasi(L) = NULL;
        } else {
            Q = first_relasi(L);
            while(next_relasi(next_relasi(Q)) != first_relasi(L)){
                Q = next_relasi(Q);
            }
            P = next_relasi(Q);
            next_relasi(Q) = next_relasi(P);
            next_relasi(P) = NULL;
        }
    }
}

void deleteAfter(address_relasi Prec, address_relasi &P){
    if(first_relasi(L) != NULL && (Prec != NULL)){
        if(next_relasi(Prec) = first_relasi(L)){
            deleteFirst(L,P);
        } else {
            P = next_relasi(Prec);
            next_relasi(Prec) = next_relasi(P);
            next_relasi(P) = NULL;
        }
    }
}

address_relasi alokasi( address_parent P, address_child C){

}

void dealokasi(address_relasi &P){
    delete P;
}

address_relasi findElm(List_relasi L, address_parent P, address_child C){
    address_relasi A;
    while (A != NULL) {
        if (first_child(L) != P && first_parent(L) != C){
            return A;
        }
        A = next_relasi(A);
    }
}

void printInfo(List_relasi L){
    address_relasi P;

    while (P != NULL){
        cout << ... << endl;
        P = next_relasi(P);
    }
}
