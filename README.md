# Tugas Besar Struktur Data // Data Structure Project

# ***Pembelian Kaset***
>- Berbentuk **IIIA** dan Bertipe **A3** dimana,
>- Kaset sebagai Parent *( Single Linked List )* 
>- Member sebagai Child *( Circular Double Linked List )*
>- dan Relasi *( Single Linked List )*

### Oleh 

>1. Muhammad Ikram Kaer Sinapoy **( 1301193341 )**
>2. I Wayan Adi Wahyudi **( 1301194084 )**

### Deskripsi

**Dimana program ini terdiri atas 7 Menu :**<br>

>**1. Membuat Data Member** _( Menerima Input, Alokasi , lalu di InsertSorted berdasarkan ID (Child) )_<br>
>**2. Membuat Data Kaset** _( Menerima Input,Alokasi, lalu di InsertSorted berdasarkan ID (Parent) )_<br>
>**3. Membeli Kaset** _( Menerima Input ID Member dan ID Kaset , lalu di cari jika ada, InsertLastRelasi )_<br>
>**4. Menampilkan Data** _(Print)_ 
>- 4.1. Menampilkan Data Member *( Print List Child )*
>- 4.2. Menampilkan Data Kaset *( Print List Parent )*
>- 4.3. Menampilkan Member dan Belanjaannya *( Print List Relasi )*
>- 4.4. Menampilkan Kaset Dibeli oleh Siapa saja *( Print Child dari Parent, dengan search ID lalu Print )* 
>- 4.5. Menampilkan Semua Kaset Dibeli oleh Siapa saja *( Print semua Parent,lalu Print Child untuk setiap Parent )*<br>

>**5. Hapus Data** *(Delete)* 

>- 5.1. Menghapus Data Member _( Delete child , by delete all relation relate to child first then delete the child )_
>- 5.2. Menghapus Data Kaset _( Delete parent , by delete all relation relate to parent first then delete the parent )_
>- 5.3. Tidak jadi membeli _( Hanya hapus relasi, berdasarkan input ID member dan ID kaset )_ 

>**6. Jenis Kaset Favorit** _( Case Functionality I , menghitung tipe kaset apa terfavorit berdasarkan tipe kaset apa yang jual laku terbanyak)_<br>
>**7. Total Harga Kaset** _( Case Functionality II, count total price of Kaset of by search the ID Member )_<br>

>***NOTES :***<br>
>- *Untuk ID kita generate dengan sebuah fungsi randomID.Yang dimana kita set untuk member(child) akan mengeluarkan hanya 6 digit dan untuk kaset(parent) hanya 3 digit kode. disetiap generate juga mengecek apakah ID tersebut sudah ada atau belum , jika sudah ada akan dilakukan generate lagi(hal ini sangat kecil kemungkinannya)*
>- *Untuk delete Child maupun Parent, jika masih terhubung di relasi. Maka akan menghapus Child maupun Parent yang akan di delete yang berada di relasi semuanya,setelah yang direlasi didelete baru didelete di list asalnya sesuai dengan permintaan skema*

### **Semua menu berasal dari skema penilaian,jadi semua yang diminta di skema sudah terpenuhi.**
