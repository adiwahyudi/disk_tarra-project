/*
    Program Pembelian Kaset (Multi Linked List dengan Bentuk IIA dengan tipe A3)
    Parent = Single Linked List yaitu Kaset
    Child = Double Circular Linked List yaitu Member
    Relasi = Single Linked List

    Penjelasan Program : Program ini diawali dengan membuat member (insertSortedChild) membuat kaset (insertSortedParent)
    lalu untuk membeli(connect) menerima input ID Member dan ID Kaset lalu akan di masukan ke dalam relasi (InsertLastRelasi).

    Untuk penjelasan lebih lengkap bisa di cek di README.md di Github kami.

    untuk mengenai apa saja bagian yang kami buat sudah kami letakan Nama dan NIM di setiap Fungsi dan Prosedurnya.

*/
#include <iostream>
#include <stdlib.h>

#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

///Untuk main dibuat oleh kami berdua

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

    int pilihMenu,Nmr,INPUT,INPUT2;
    do{
        cout << "=========== PEMBELIAN KASET ===========" << endl;
        cout << "1. Membuat Data Member " << endl;
        cout << "2. Membuat Data Kaset " << endl;
        cout << "3. Membeli Kaset " << endl;
        cout << "4. Menampilkan Data " << endl;
        cout << "5. Hapus Data " << endl;
        cout << "6. Jenis Kaset Favorit" << endl;
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
            cout << "3. Menampilkan Member dan Belanjaannya " << endl;
            cout << "4. Menampilkan Kaset Dibeli oleh Siapa saja " << endl;
            cout << "5. Menampilkan Semua Kaset Dibeli oleh Siapa saja" <<endl;
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
                cout << "ID Kaset : ";
                cin >> INPUT;
                printChildTOParent(ListR,INPUT);
                bersih();
            } else  if (Nmr == 5){
                Child4EachParent(ListR,ListP);
                bersih();
            }
            break;
        case 5:
            cout << "1. Menghapus Data Member " << endl;
            cout << "2. Menghapus Data Kaset " << endl;
            cout << "3. Tidak jadi membeli " << endl;
            cout << " \nChoose Menu : ";
            cin >> Nmr;
            system("CLS");
            if(Nmr == 1){
                cout << "ID Member yang akan di hapus : ";
                cin >> INPUT;
                if (findElmChild(ListC,INPUT) != NULL){
                    if (cariChildDiRelasi(ListR,INPUT) != NULL){
                        deleteChilDiRelasi(ListR,INPUT);
                        deleteListChild(ListC,INPUT);
                    } else {
                        deleteListChild(ListC,INPUT);
                    }
                } else {
                    cout << "Tidak ada data" <<endl;
                }
                bersih();
            } else if(Nmr == 2){
                cout << "ID Kaset yang akan di hapus : ";
                cin >> INPUT;
                if (findElmParent(ListP,INPUT) != NULL) {
                    if(cariParentDiRelasi(ListR,INPUT) != NULL) {
                        deleteParentdiRelasi(ListR,INPUT);
                        deleteListParent(ListP,INPUT);
                    } else {
                        deleteListParent(ListP,INPUT);
                    }
                } else {
                    cout << "Tidak ada data" <<endl;
                }
                bersih();

            } else if (Nmr == 3) {
                cout <<"ID Member : ";
                cin >> INPUT;
                cout <<"ID Kaset : ";
                cin >> INPUT2;
                deleteListRelasi(ListR,INPUT2,INPUT);
                bersih();
            }

            break;
        case 6:
            jenisKasetFavorit(ListR, Rel);
            bersih();
            break;
        case 7:
           hitungHargaKaset(ListR,ListC);
           bersih();
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
