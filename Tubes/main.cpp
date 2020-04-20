#include <iostream>
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

using namespace std;

void Menu(){
    int pilihMenu;
    do{
        cout << "=========PEMINJAMAN KASET===========" << endl;
        cout << "1. Memasukkan Data Peminjam" << endl;
        cout << "2. Menampilkan Kaset Yang Tersedia" << endl;
        cout << "3. Menampilkan Data Peminjam Kaset" << endl;
        cout << "4. Search Data Peminjam Kaset" << endl;
        cout << "5. Search Kaset" << endl;
        cout << "6. Edit Data Peminjam" << endl;
        cout << "7. Delete Data Peminjam Kaset" << endl;
        cout << "8. Rekomendasi Film" << endl;
        cout << "0. Quit" << endl;
        cout << "Choose Menu : " << endl;
        cin >> pilihMenu;
        switch(pilihMenu){
        case 1:

            break;
        case 2:

            break;
        case 3:

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
