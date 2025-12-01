#include <stdio.h>
#include "barang.h"
#include "tools.h"
#include "menu.h"


//Program utama
int main()
{
    //banyakBarang wajib sama dengan banyak barang yang akan diinput ke array
    const int banyakBarang = 10;
    Barang daftarBarang[banyakBarang];
    
    //daftarBarang[i], ID, Nama, Harga, Diskon
    inputBarang(&daftarBarang[0], 101, "Choclatos" ,1500, 0);
    inputBarang(&daftarBarang[1], 102, "Chiki" ,15000, 0);
    inputBarang(&daftarBarang[2], 103, "Potato" ,10000, 0);
    inputBarang(&daftarBarang[3], 104, "Ratatuili", 50000, 0.5);
    inputBarang(&daftarBarang[4], 105, "Oreo", 7000, 0);
    inputBarang(&daftarBarang[5], 201, "Sabun", 31000, 0);
    inputBarang(&daftarBarang[6], 202, "Sampo", 20000, 0);
    inputBarang(&daftarBarang[7], 203, "Deterjen", 11000, 0);
    inputBarang(&daftarBarang[8], 204, "Parfum", 50000, 0);
    inputBarang(&daftarBarang[9], 301, "Silverqueen", 15000, 0.15);

    kasir(daftarBarang, banyakBarang);

    return 0;
}
