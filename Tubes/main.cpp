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
        cout << "=========== PEMBELIAN KASET ===========" << endl;
        cout << "1. Membuat Data Member" << endl;
        cout << "2. Membuat Data Kaset " << endl;
        cout << "3. Membeli Kaset " << endl;
        cout << "4. Menampilkan Data " << endl;
        cout << "5. Hapus Data " << endl;
        cout << "6. Rekomendasi Film" << endl;
        cout << "7. Total Harga Kaset" << endl;
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
            cout << "3. Menampilkan Member dan Belanjaannya " << endl; /// Pas child ada di relasi terus child dihapus berhasil , tapi pas nampilin relasi gagal.
            cout << "4. Menampilkan Kaset Dibeli oleh Siapa " << endl;
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
            } else if (Nmr == 4) {
                /// buat dulu printnya
            }
            break;
        case 5:
            cout << "1. Menghapus Data Member " << endl;
            cout << "2. Menghapus Data Kaset " << endl;
            cout << " \nChoose Menu";
            cin >> Nmr;
            if(Nmr == 1){
                cout << "ID Member yang akan di hapus : ";
                cin >> INPUT;
                if(findElmChild(ListC, INPUT) != NULL){
                    deleteListChild(ListC, INPUT);
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
        case 6:

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
