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
    if (P != NULL) {
        while (P != NULL){
        cout << info(child(P)).Nama <<" menyewa kaset berjudul ";
        cout << info(parent(P)).judul <<" seharga Rp." << info(parent(P)).harga <<endl;
        P = next(P);
        }
    } else {
        cout << "Tidak ada data pembelian" <<endl;
    }
    cout<<endl;
}

void bersih (){
    cout<<endl;
    system("pause > 0 | echo tekan enter untuk melanjutkan..");
    system("CLS");
}
void case3(List_child &LC,List_parent &LP,List_relasi &LR,adr_child &AC,adr_parent &AP,adr_relasi &AR) {

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
    bersih();
}
/*adr_relasi cariChild(List_relasi &L,int C){

    adr_relasi P = first(L);

    while (P != NULL && info(child(P)).memberID != C){
        P = next(P);
    }
    return P;
}
adr_relasi cariParent(List_relasi &L,int C){

    adr_relasi P = first(L);

    while (P != NULL && info(parent(P)).kodeKaset != C){
        P = next(P);
    }
    return P;
}
*/
adr_relasi cariParentDiRelasi(List_relasi LR,int x){

    adr_relasi P = first(LR);

    while (P != NULL) {
        if (info(parent(P)).kodeKaset == x){
            return P;
        } else {
            P = next(P);
        }
    }
    return P;
}

adr_relasi cariChildDiRelasi(List_relasi LR,int x){

    adr_relasi P = first(LR);

    while (P != NULL) {
        cout<<"A";
        if (info(child(P)).memberID == x){
            return P;
        } else {
            P = next(P);
        }
    }
    return NULL;
}

void deleteParentdiRelasi(List_relasi &LR,int AP) {

    adr_relasi P,Q,Z;
    Z = first(LR);
    while (cariParentDiRelasi(LR,AP) != NULL){
        if (info(parent(first(LR))).kodeKaset == AP ){
            deleteFirstRelasi(LR,P);
            dealokasiRelasi(P);
        } else if (info(parent(last(LR))).kodeKaset == AP ){
            deleteLastRelasi(LR,P);
            dealokasiRelasi(P);
        } else {
            Q = first(LR);
            while (cariParentDiRelasi(LR,info(parent(P)).kodeKaset) != NULL){
                if (info(next(parent(Q))).kodeKaset == AP){
                    deleteAfterRelasi(Q,next(Q));
                    dealokasiRelasi(Q);
                }
                Q = next(Q);
            }
        }
    }
}

void deleteChilDiRelasi(List_relasi &LR, int AP){
    adr_relasi P,Q;
    Q = first(LR);

    while (cariChildDiRelasi(LR,AP) != NULL){
        if(info(child(first(LR))).memberID == AP ){
            cout<<"A";
            deleteFirstRelasi(LR,P);
            dealokasiRelasi(P);
        } else if (info(child(last(LR))).memberID == AP){
            cout<<"B";
            deleteLastRelasi(LR,P);
            dealokasiRelasi(P);
        } else {
            adr_relasi Q = first(LR);
            while (P != NULL && info(child(Q)).memberID < AP) {
                   P = Q;
                   Q = next(Q);
                }
                cout<<"C";
            deleteAfterRelasi(P,Q);
            dealokasiRelasi(P);
            }
        }
        Q = next(Q);
}

void deleteListRelasi(List_relasi &LR,int Par,int Chi) {

    adr_relasi P,Q;
    Q = first(LR);

    if ( info(parent(Q)).kodeKaset == Par && info(child(Q)).memberID == Chi ){
        deleteFirstRelasi(LR,P);
        dealokasiRelasi(P);
    } else if (info(parent(last(LR))).kodeKaset == Par && info(child(last(LR))).memberID == Chi ){
        deleteLastRelasi(LR,P);
        dealokasiRelasi(P);
    } else {
        while ( Q != NULL){
            if (info(next(parent(Q))).kodeKaset == Par && info(next(child(Q))).memberID == Chi){
                deleteAfterRelasi(Q,next(Q));
                dealokasiRelasi(Q);
            }
            Q = next(Q);
        }
    }
}

//void hitungHargaKaset(List_relasi L,){

//}
