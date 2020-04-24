/// Child as Double Circular Linked List and Penyewa

#include "list_child.h"

void createListChild(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_child alokasiChild(infotype_child x) {

    adr_child P = new elmlist_child;
    info(P).NoIdent = x.NoIdent;
    info(P).Nama = x.Nama;
    info(P).memberID = x.memberID;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstChild(List_child &L, adr_child P) {
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
        last(L) = P;
    }
}
void insertLastChild(List_child &L, adr_child P){
    if(first(L) == NULL){
       insertFirstChild(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
}

void insertAfterChild(List_child &L, adr_child &Prec, adr_child P) {
    if (first(L) == NULL)
    {
        insertFirstChild(L, P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirstChild(List_child &L, adr_child &P){
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

void deleteLastChild(List_child &L, adr_child &P){

    if ( first(L) != last(L) ){
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(prev(P));
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirstChild(L,P);
    }
}

void deleteAfterChild(List_child &L, adr_child Prec, adr_child &P){

    if ( next(Prec) != first(L) ) {
        P = next(Prec);
        prev(next(P)) = Prec;
        next(Prec) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirstChild(L,P);
    }
}

void insertSortChild(List_child &L, infotype_child x){
    adr_child Q;
    adr_child P = first(L);
    if(P == NULL || info(first(L)).NoIdent >= x.NoIdent){
        insertFirstChild(L, alokasiChild(x));
    } else if (info(last(L)).NoIdent <= x.NoIdent){
        insertLastChild(L, alokasiChild(x));
    } else {
        do {
            Q = P;
            P = next(P);
        } while(P != first(L) && info(P).NoIdent < x.NoIdent);
        insertAfterChild(L, Q, alokasiChild(x));
    }
}

void deleteListChild(List_child &L, infotype_child x){
    adr_child P = findElmChild(L, x.NoIdent);
    if(P != NULL){
        if(P == first(L)){
            deleteFirstChild(L, P);
        } else {
            deleteAfterChild(L, prev(P), P);
        }
    }
}

void printChild(List_child L) {
    adr_child P = first(L);
    do {
        cout << "ID Member       : " << info(P).memberID << endl;
        cout << "Nama            : " << info(P).Nama << endl;
        cout << "Nomer Identitas : " << info(P).NoIdent << endl;
        P = next(P);
        cout<<endl;
    } while (P != first(L));
}


adr_child findElmChild(List_child L, int x) { ///Untuk Sementara NoIdent semestinya ID dari Pengguna.
    adr_child P = first(L);
    do{
        if(info(P).NoIdent == x ) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
void dealokasiChild(adr_child &P) {
    delete P;
}

int randomIDmember(){
    int rndm = 100000 + rand() % 999999;
    return rndm ;
}
