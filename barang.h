#ifndef BARANG_H
#define BARANG_H

/*tipe data Barang, untuk menyimpan ID("ID"), Nama("nama"), Harga("harga"), Diskon("diskon"), 
Apakah dimasukan ke keranjang("terisi"), dan jumlah jika dimasukan ke keranjang("jumlah")*/
typedef struct
{
    int ID;
    char nama[50];
    int harga;
    float diskon;
    int terisi;
    int jumlah;
} Barang;


void printList(Barang brg[], int banyakBarang);
void inputBarang(Barang *brg, int id, const char name[], int harga, float diskon);


#endif
