/// Parent as Single Linked List and Kaset

#include "list_parent.h"

void createListParent(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_parent alokasiParent(infotype_parent x) {

    adr_parent P;

    P = new elmlist_parent;
    info(P).judul = x.judul;
    info(P).tahunKaset = x.tahunKaset;
    info(P).genre = x.genre;
    info(P).harga = x.harga;
    info(P).tipe = x.tipe;
    info(P).kodeKaset = x.kodeKaset;
    next(P) = NULL;
    return P;
}

void insertFirstParent(List_parent &L, adr_parent P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfterParent(List_parent &L, adr_parent Prec, adr_parent P){

    next(P) = next(Prec);
    next(Prec) = P;

}
void insertLastParent(List_parent &L, adr_parent P){
    if(first(L) == NULL){
        insertFirstParent(L,P);
    } else {
       next(last(L)) = P;
       last(L) = P;
       next(P) = NULL;
    }
}

void deleteFirstParent(List_parent &L, adr_parent &P){
    if (first(L) != NULL){
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
}
void deleteLastParent(List_parent &L, adr_parent &P){ ///masih bingung lupa euy
   if (first(L) != NULL){
        if (first(L) == last(L)){
            deleteFirstParent(L,P);
        } else {
            adr_parent Q = first(L);
            while ( next(Q) != last(L) ) {
                Q = next(Q);
            }
            last(L) = Q;
            next(last(L))= NULL;
        }
   }
}

void deleteAfterParent(List_parent &L, adr_parent Prec, adr_parent &P){
        P = next(Prec);
        next(Prec) = P;
        next(P) = NULL;
}

void insertSortParent(List_parent &L, infotype_parent x){
    adr_parent Q;
    adr_parent P = first(L);
    if(P == NULL){
        insertFirstParent(L, alokasiParent(x));
    } else if (info(last(L)).judul <= x.judul){
        insertLastParent(L, alokasiParent(x));
    } else {
        while(P != first(L) && info(P).judul < x.judul){
            Q = P;
            P = next(P);
        }
        insertAfterParent(L, Q, alokasiParent(x));
    }
}
void dealokasiParent (adr_parent &P){
    delete P;
}

void printParent(List_parent L) {
   adr_parent P = first(L);

   while ( P != NULL) {
       cout << "\nKode Kaset\t: " << info(P).kodeKaset << endl;
       cout << "Tipe Kaset\t: " << info(P).tipe << endl;
       cout << "Judul Kaset\t: " << info(P).judul << endl;
       cout << "Tahun Kaset\t: " << info(P).tahunKaset << endl;
       cout << "Genre Kaset\t: " << info(P).genre << endl;
       cout << "Harga Kaset\t: " << info(P).harga << endl;
       P = next(P);
       cout<<endl;
   }
}

adr_parent findElmParent(List_parent L, string x) { ///Untuk Sementara judul semestinya ID dari Kaset.
    adr_parent P = first(L);

    while ((P != NULL) && (info(P).judul != x)){
        P = next(P);
    }
    return P;
}

int randomkodeKaset(){
    int rndm = 100 + rand() % 999;
    return rndm;
}

