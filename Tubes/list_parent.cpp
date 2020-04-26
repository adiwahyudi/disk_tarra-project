/// Parent as Single Linked List and Kaset

#include "list_parent.h"
#include "list_relasi.h"

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
       next(last(L)) = P;
       last(L) = P;

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
    P = last(L);
    adr_parent Q = first(L);
    while (next(Q) != last(L)){
        Q = next(Q);
    }
    last(L) = Q;
    next(Q) = NULL;
}

void deleteAfterParent(List_parent &L,adr_parent Prec, adr_parent &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void insertSortParent(List_parent &L, adr_parent Q){
     if ( first(L) != NULL) {
        if (findElmParent(L,info(Q).kodeKaset) == NULL){
            if (info(Q).kodeKaset < info(first(L)).kodeKaset){
                insertFirstParent(L,Q);
            } else if (info(Q).kodeKaset > info(last(L)).kodeKaset) {
                insertLastParent(L,Q);
            } else {
                adr_parent P = first(L);
                while (P != NULL && info(Q).kodeKaset > info(next(P)).kodeKaset){
                    P = next(P);
                }
                insertAfterParent(L,P,Q);
            }
        } else {
            cout << "Maaf data sudah ada " << endl;
        }
    } else {
        insertFirstParent(L,Q);
    }

}

void deleteListParent(List_parent &L, int x){
    adr_parent P;
    P = first(L);
    if (first(L) != NULL){
        if(info(P).kodeKaset == x ){
            deleteFirstParent(L,P);
        } else if(info(last(L)).kodeKaset == x){
            deleteLastParent(L,P);
        } else {
            adr_parent Q = first(L);
            while (Q != NULL && info(Q).kodeKaset < x) {
                   P = Q;
                   Q = next(Q);
                }
            deleteAfterParent(L,P,Q);
            }
    } else {
        cout << "Tidak ada kaset" <<endl;
        bersih();
    }
}

void dealokasiParent (adr_parent &P){
    delete P;
}

void printParent(List_parent L) {
   adr_parent P = first(L);

   if (P != NULL){
       cout << "Daftar Kaset yang tersedia : \n" <<endl;
       while ( P != NULL) {
           cout << "Kode Kaset\t: " << info(P).kodeKaset << endl;
           cout << "Tipe Kaset\t: " << info(P).tipe << endl;
           cout << "Judul Kaset\t: " << info(P).judul << endl;
           cout << "Tahun Kaset\t: " << info(P).tahunKaset << endl;
           cout << "Genre Kaset\t: " << info(P).genre << endl;
           cout << "Harga Kaset\t: " << info(P).harga << endl;
           P = next(P);
           cout<<endl;
       }
    } else {
       cout << "Tidak ada kaset yang tersedia" <<endl;
    }
}
adr_parent findElmParent(List_parent L, int x) {
    adr_parent P = first(L);

    while (P != NULL && info(P).kodeKaset != x){
            P = next(P);
        }
    return P;
}

int randomkodeKaset(){
    int rndm = 100 + rand() % 999;
    return rndm;
}
void case2(List_parent &LP,infotype_parent &ITP){
    string jenis;
    cout << "Pilih Jenis Kaset ( Film / Musik ): ";
    cin >> jenis ;

    if (jenis == "musik" || jenis == "Musik" || jenis == "MUSIK" ) {
        ITP.harga = 75000;
        ITP.tipe = "Musik";
    } else if ( jenis == "film" || jenis == "Film" || jenis == "FILM" ) {
        ITP.harga = 100000;
        ITP.tipe = "Film";
    }

    cout << "Masukkan Judul\t\t: ";
    cin.get();
    getline(cin, ITP.judul);
    cout << "Masukkan Tahun Kaset\t: ";
    cin >> ITP.tahunKaset;
    cout << "Masukkan Genre\t\t: ";
    cin >> ITP.genre;
    ITP.kodeKaset = randomkodeKaset();
    if (findElmParent(LP,ITP.kodeKaset) != NULL){
       ITP.kodeKaset = randomkodeKaset();
    }
    cout << "\nSelamat anda berhasil menambahkan data kaset!" <<endl;
    cout << "Kode kaset "<< ITP.judul << " adalah " << ITP.kodeKaset <<endl;
    insertSortParent(LP,alokasiParent(ITP));
    bersih();
}
