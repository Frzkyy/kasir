#include <stdio.h>
#include "barang.h"
#include "util.h"
#include "data.h"

int main()
{
    int banyakBarang = 10;
    Barang daftarBarang[10];
    int pilih, run=1;
    
    inputBarang(&daftarBarang[0], 101, "Choclatos" ,1500, 0);
    inputBarang(&daftarBarang[1], 102, "Chiki" ,15000, 0);
    inputBarang(&daftarBarang[2], 103, "Potato" ,10000, 0);
    inputBarang(&daftarBarang[3], 104, "Ratatuili", 50000, 0);
    inputBarang(&daftarBarang[4], 105, "Oreo", 7000, 0);
    inputBarang(&daftarBarang[5], 201, "Sabun", 31000, 0);
    inputBarang(&daftarBarang[6], 202, "Sampo", 20000, 0);
    inputBarang(&daftarBarang[7], 203, "Deterjen", 11000, 0);
    inputBarang(&daftarBarang[8], 204, "Parfum", 50000, 0);
    inputBarang(&daftarBarang[9], 205, "Pepsoden", 30000, 0);

    
    while(run){
        printMenuUtama(&pilih);
        switch (pilih)
        {
        case 1:
            printf("\n================================\n");
            printList(daftarBarang, banyakBarang);
            printf("================================\n");
            printf("Tekan enter untuk melanjutkan");
            getchar();
            getchar();
            break;
        case 2:
            kasir(daftarBarang, banyakBarang);
            break;
        case 0:
            printf("\nTerima Kasih :)\nTekan tombol apapun untuk keluar");
            getchar();
            getchar();
            run=0;
        
        default:
            printf("\nInput Salah! \n");
            break;
        }
    }

    return 0;
}
