#include "list_relasi.h"

void createListRelasi(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}
void insertFirstRelasi(List_relasi &L, adr_relasi P){
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

void insertLastRelasi(List_relasi &L, adr_relasi P){

    if (first(L) == NULL){
        insertFirstRelasi(L,P);
    } else {
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void insertAfterRelasi(adr_relasi Prec, adr_relasi P){

    next(P) = next(Prec);
    next(Prec) = P;

}

void deleteFirstRelasi(List_relasi &L, adr_relasi &P){

    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLastRelasi(List_relasi &L, adr_relasi &P){
    P = first(L);
    while ( next(P) != last(L) ) {
        P = next(P);
    }
    last(L) = P;
    P = next(P);
    next(last(L)) = NULL;
}

void deleteAfterRelasi(adr_relasi Prec, adr_relasi &P){

    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

}

adr_relasi alokasiRelasi( adr_parent P, adr_child C){

    adr_relasi Q = new elmlist_relasi;

    child(Q) = C;
    parent(Q) = P;
    return Q;
}

void dealokasiRelasi(adr_relasi &P){
    delete P;
}

adr_relasi findElmRelasi(List_relasi L, int diC, int diP){
    adr_relasi Q = first(L);
    while (Q != NULL) {
        if (info(parent(Q)).kodeKaset == diP  && info(child(Q)).memberID == diC){
            return Q;
        } else {
            Q = next(Q);
        }
    }
    return NULL;
}

void printRelasi(List_relasi L){
    adr_relasi P = first(L);
    while (P != NULL){
        cout << info(child(P)).Nama <<" menyewa kaset berjudul ";
        cout << info(parent(P)).judul <<" seharga Rp." << info(parent(P)).harga <<endl;
        P = next(P);
    }
    cout<<endl;
}

void bersih (){
    cout<<endl;
    system("pause > 0 | echo tekan enter untuk melanjutkan..");
    system("CLS");
}
void case3 (List_child &LC,List_parent &LP,List_relasi &LR,adr_child &AC,adr_parent &AP,adr_relasi &AR) {

    int cariIDmem;
    int cariKodeKaset;

    cout << "ID Member\t: ";
    cin >> cariIDmem;
    cout << "ID Kaset\t: ";
    cin >> cariKodeKaset;
    AC = findElmChild(LC,cariIDmem);AP = findElmParent(LP,cariKodeKaset);
    if (AC && AP) {
       AR = alokasiRelasi(AP,AC);
       insertLastRelasi(LR,AR);
       cout << "Selamat anda berhasil menyewa kaset!" << endl;
    } else {
        cout << "Maaf anda tidak terdaftar sebagai Member"<<endl;
    }


}
