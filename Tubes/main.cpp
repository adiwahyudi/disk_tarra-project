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

    int pilihMenu,Nmr,INPUT;
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
            case1(ListC,child);
            break;
        case 2:
            case2(ListP,parent);
            break;
        case 3:
            case3(ListC,ListP,ListR,Chi,Par,Rel);
            break;
        case 4:
            cout << "1. Menampilkan Data Member" << endl;
            cout << "2. Menampilkan Data Kaset " << endl;
            cout << "3. Menampilkan Member dan Pinjamannya " << endl;
            cout << "\nChoose Menu : ";
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
            cout << "1. Menghapus data peminjam" << endl;
            cout << "2. Menghapus data kaset " << endl;
            cout << "   Pilih : ";
            cin >> Nmr;
            if(Nmr == 1){
                cout << "ID Member yang akan di hapus : ";
                cin >> INPUT;
                if(findElmChild(ListC, INPUT) != NULL){
                    deleteListChild(ListC, child);
                } else {
                    cout << "Maaf data tidak ada" <<endl;
                }
            } else if(Nmr == 2){
                cout << "ID Kaset yang akan di hapus : ";
                cin >> INPUT;
                if (findElmParent(ListP,INPUT) != NULL ) {
                    /// kosong we lah
                } else {
                    cout << "Maaf data tidak ada" <<endl;
                }
            }

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
