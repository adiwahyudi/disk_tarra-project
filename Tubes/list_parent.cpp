/// Parent as Single Linked List and Kaset
#include "list_parent.h"

void createList(List_parent &L) {
    first_parent(L) = NULL;
    last_parent(L) = NULL;
}

adr_parent alokasi(infotype_parent x) {

    adr_parent P;

    P = new elmlist_parent;
    info_parent(P) = x;
    next_parent(P) = NULL;
    return P;
}

void insertFirstParent(List_parent &L, adr_parent P) {
    adr_parent Q;
    if(first_parent(L) == NULL) {
        first_parent(L) = P;
        last_parent(P) = P;
        next_parent(P) = NULL;
    } else {
        next_parent(P) = first_parent(L);
        first_parent(L) = P;
    }
}
void insertAfterParent(adr_parent Prec, adr_parent P){

    next_parent(P) = next_parent(Prec);
    next_parent(Prec) = P;

}
void insertLastParent(List_parent &L, adr_parent P){
    adr_parent Q;
    if(first_parent(L) == NULL){
        insertFirstParent(L,P)
    } else {
       next_parent(last_parent(L)) = P;
       last_parent(L) P;
       next_parent(P) = NULL;
    }
}

void deleteFirstParent(List_parent &L, adr_parent &P){
    if (first_parent(L) != NULL){
        if (first_parent(L) == last_parent(L)) {
            first_relasi(L) = NULL;
            last_relasi(L) = NULL;
        } else {
            first_parent(L) = next_parent(first_parent(L));
            next_parent(P) = NULL;
        }
    }
}
void deleteLastParent(List_parent &L, adr_parent &P){ ///masih bingung lupa euy
   if (first_parent(L) != NULL){
        if (first_parent(L) == last_parent(L)){
            deleteFirstParent(L,P);
        } else {
            adr_parent Q = first_parent(L);
            while ( next_parent(Q) != last_parent(L) ) {
                Q = next_parent(Q);
            }
            last_parent(L) = Q;
            next_parent(last_parent(L))= NULL;
        }
   }
}

void deleteAfterParent(List_parent &L, adr_parent Prec, adr_parent &P){
    if ( first_parent(L) != NULL) {
        P = next_parent(Prec);
        next_parent(Prec) = P;
        next_parent(P) = NULL;
    }
}
void printParent(List_parent L) {
   for (adr_parent P = first_parent(L) ; info_parent(P) != NULL ; P = next_parent(P)) {
        cout << info_parent(P) << endl;
   }
}

adr_parent findElm(List_parent L, infotype_parent x) {
    adr_parent P = first_parent(L);

    while ((P != NULL) && (info_parent(P) != x)){
        P = next_parent(P);
    }
    return P;
}
