/// Child as Double Circular Linked List and Penyewa

#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_child alokasi(infotype_child x) {

    adr_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, adr_child P) {
    if (first(L) != NULL){
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
        last(P) = P;
    }
}
void insertLast(List_child &L, adr_child P){
    if(first(L) == NULL){
       insertFirst(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
}

void insertAfter(adr_child &Prec, adr_child P) {

    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteFirst(List_child &L, adr_child &P){

    P = first(L);
    if (next(first(L))!= P){
        first(L) = next(P);
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
}

void deleteLast(List_child &L, adr_child &P){
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

void deleteAfter(List_child &L, adr_child Prec, adr_child &P){
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
    adr_child P = first(L);

    do {
        cout << info(P) << endl;
        P = next(P);
    } while (P != first(L))
}


adr_child findElm(List_child L, infotype_child x) {
    adr_child P = first(L);
    while(P != NULL) {
        if(info(P) == x ) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
