#include <iostream>
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

using namespace std;

void Menu(){
    infotype_parent parent;
    infotype_child child;
    int pilihMenu,Nmr;
    do{
        cout << "=========PEMINJAMAN KASET===========" << endl;
        cout << "1. Memasukkan Data Peminjam" << endl;
        cout << "2. Memasukkan Data Kaset " << endl;
        cout << "3. Menampilkan Data Peminjam/ Kaset " << endl;
        cout << "4. Search Kaset" << endl;
        cout << "5. Edit Data Peminjam" << endl;
        cout << "6. Delete Data Peminjam Kaset" << endl;
        cout << "7. Rekomendasi Film" << endl;
        cout << "0. Quit" << endl;
        cout << "\nChoose Menu : ";
        cin >> pilihMenu;
        switch(pilihMenu){
        case 1:
            cout << "Masukkan nama anda: " << endl;
            getline(cin, child.Nama);
            cout << "Masukkan Nomor Identitas: " << endl;
            getline(cin, child.NoIdent);
            // insertshort belum dibuat
            break;
        case 2:
            cout << "Masukkan Judul: " << endl;
            getline(cin, parent.judul);
            cout << "Masukkan Tahun Kaset: " << endl;
            getline(cin, parent.tahunKaset);
            cout << "Masukkan Genre: " << endl;
            getline(cin ,parent.genre);
            // insertshort belum dibuat
            break;
        case 3:
            cout << "1. Menampilkan Data peminjam" << endl;
            cout << "2. Menampilkan Kaset " << endl;
            cout << "3. Menampilkan Data Peminjam Kaset " << endl;
            cout << "   Pilih : " << endl;
            cin >> Nmr;
            if(Nmr == 1){
                printChild(L);
            } else if(Nmr == 2){
                printParent(L);
            } else if(Nmr == 3){
                printRelasi(L);
            }
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
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
