#include <stdio.h>
#include "barang.h"
#include "tools.h"
#include "menu.h"


//Program utama
int main()
{
    //banyakBarang wajib sama dengan banyak barang yang akan diinput ke array
    const int banyakBarang = 20;
    Barang daftarBarang[banyakBarang];
    
    //daftarBarang[i], ID, Nama, Harga, Diskon
    inputBarang(&daftarBarang[0], 101, "SGM Eksplor Vanila 900g" ,93500, 0.14);
    inputBarang(&daftarBarang[1], 102, "ABC Kecap Manis Refill 685g" ,25000, 0.32);
    inputBarang(&daftarBarang[2], 103, "Potato" ,10000, 0);
    inputBarang(&daftarBarang[3], 104, "Blue Band Sachet 200g", 10200, 0.5);
    inputBarang(&daftarBarang[4], 105, "Oreo", 7000, 0);
    inputBarang(&daftarBarang[5], 201, "Biore Body Wash Refil l400ml ", 26200, 0.28);
    inputBarang(&daftarBarang[6], 202, "Kanzler Chicken Nugget 450g", 58900, 0.12);
    inputBarang(&daftarBarang[7], 203, "Soklin Lantai PL Citrus Garden Refill 700ml", 7500, 0);
    inputBarang(&daftarBarang[8], 204, "Parfum", 50000, 0.5);
    inputBarang(&daftarBarang[9], 301, "Indomie Goreng (5 pcs)", 15000, 0);
    inputBarang(&daftarBarang[10],302, "Aqua Air Mineral 1.5L", 7500, 0.10);
    inputBarang(&daftarBarang[11],303, "Sari Roti Tawar Kupas 420g", 14500, 0.15);
    inputBarang(&daftarBarang[12],304, "Molto All In One Softener Refiil 660ml", 19000, 0.15);
    inputBarang(&daftarBarang[13],401, "Luwak White Koffie 10 Sachet", 12000, 0.10);
    inputBarang(&daftarBarang[14],402, "Pilus", 8000, 0);
    inputBarang(&daftarBarang[15],403, "Ultra Milk UHT(2x200ml)", 12500, 0.10);
    inputBarang(&daftarBarang[16],404, "Qtela", 12000, 0.10);
    inputBarang(&daftarBarang[17],501, "Beng-Beng", 2500, 0);
    inputBarang(&daftarBarang[18],502, "Pucuk Harum (350ml)", 3900, 0);
    inputBarang(&daftarBarang[19],503, "Rinso Cair Anti Noda 700ml", 32000, 0.10);

    kasir(daftarBarang, banyakBarang);

    return 0;
}
