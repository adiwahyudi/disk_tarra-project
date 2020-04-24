#include <iostream>
#include <stdlib.h>

#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

void Menu(){
    infotype_parent parent;
    infotype_child child;

    List_child ListC;
    List_parent ListP;
    List_relasi ListR;

    createListChild(ListC);
    createListParent(ListP);
    createListRelasi(ListR);

    adr_child Chi;
    adr_parent Par;
    adr_relasi Rel;

    string jenis;
    string cariNamaKaset;

    int cariNoIdent;
    int pilihMenu,Nmr;

    do{
        cout << "=========PEMINJAMAN KASET===========" << endl;
        cout << "1. Memasukkan Data Peminjam" << endl;
        cout << "2. Memasukkan Data Kaset " << endl;
        cout << "3. Meminjam Kaset " << endl;
        cout << "4. Menampilkan Data " << endl;
        cout << "5. Hapus Data " << endl;
        cout << "6. Edit Data Peminjam" << endl;
        cout << "7. Delete Data Peminjam Kaset" << endl;
        cout << "8. Rekomendasi Film" << endl;
        cout << "0. Quit" << endl;
        cout << "\nChoose Menu : ";
        cin >> pilihMenu;
        system("CLS");
        switch(pilihMenu){
        case 1:
            cout << "Masukan Nama Anda\t: ";
            cin.get();
            getline(cin, child.Nama);
            cout << "Masukan Nomor Identitas\t: ";
            cin >> child.NoIdent;
            child.memberID = randomIDmember();
            insertSortChild(ListC,child);
            cout << "\nSelamat data berhasil anda dibuat!" <<endl;
            cout << "ID Member anda : "<<child.memberID<<" mohon untuk diingat!"<<endl;
            bersih();
            break;
        case 2:

            cout << "Pilih Jenis Kaset ( Film / Musik )\t: ";
            cin >> jenis ;

            if (jenis == "musik" || jenis == "Musik" || jenis == "MUSIK" ) {
                parent.harga = 75000;
                parent.tipe = "Musik";
            } else if ( jenis == "film" || jenis == "Film" || jenis == "FILM" ) {
                parent.harga = 100000;
                parent.tipe = "Film";
            }

            cout << "Masukkan Judul\t: ";
            cin.get();
            getline(cin, parent.judul);
            cout << "Masukkan Tahun Kaset\t: ";
            cin >> parent.tahunKaset;
            cout << "Masukkan Genre\t: ";
            cin >> parent.genre;
            parent.kodeKaset = randomkodeKaset();
            cout << "\nSelamat anda berhasil menambahkan data kaset!" <<endl;
            cout << "Kode kaset "<< parent.judul << " adalah " << parent.kodeKaset <<endl;
            insertLastParent(ListP,alokasiParent(parent));
            /// insertsorted belum dibuat
            bersih();
            break;
        case 3:
            cout << "Silahkan masukan ID Member anda\t: ";
            cin >> cariNoIdent;
            cout << "Judul Kaset : ";
            cin.get();
            getline(cin,cariNamaKaset);
            Chi = findElmChild(ListC,cariNoIdent);Par = findElmParent(ListP,cariNamaKaset);
            if (Chi && Par) {
               Rel = alokasiRelasi(Par,Chi);
               insertLastRelasi(ListR,Rel);
            } else {
                cout << "Maaf tidak terdaftar sebagai Member"<<endl;
            }
            cout << "Selamat anda berhasil menyewa kaset!" << endl;
            bersih();
            break;
        case 4:
            cout << "1. Menampilkan Data peminjam" << endl;
            cout << "2. Menampilkan Kaset " << endl;
            cout << "3. Menampilkan Data Peminjam dan Kasetnya " << endl;
            cout << "   Pilih : ";
            cin >> Nmr;
            system("CLS");
            if(Nmr == 1){
                printChild(ListC);
                bersih();
            } else if(Nmr == 2){
                printParent(ListP);
                bersih();
            } else if(Nmr == 3){
               printRelasi(ListR);
               bersih();
            }
            break;
        case 5:
            cout << "1. Menghapus data member " << endl;
            cout << "2. Menghapus data kaset " << endl;
            cout << "3. Menampilkan Data Peminjam dan Kasetnya " << endl;

            break;
        case 6:
            deleteListChild(ListC, child);
            break;
        case 7:

            break;
        case 8:

            break;
        }
        if(pilihMenu == 0){
            break;
        }
    }while (true);

}
int main()
{
    Menu();
    return 0;
}
