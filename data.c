#include <stdio.h>
#include "data.h"
#include "barang.h"

void kasir(Barang *brg, int banyakBarang){

    int running = 1;
    while(running){

        int temp;
        printf("======================\n");
        printf("Keranjang: \n");
        printf("======================\n\n");
        printf("Masukan Produk Pelanggan\n");
        printf("======================\n");
        printf("1. List Barang\n");
        printf("2. Tambahkan Barang\n");
        printf("3. Edit Barang\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("======================\n");
        printf("Ketik angka diatas untuk melanjutkan: ");
        scanf("%d", &temp);

        if(temp == 1){
             printf("\n================================\n");
            printList(brg, banyakBarang);
            printf("================================\n");
            printf("Tekan enter untuk melanjutkan");
            getchar();
            getchar();
            printf("\n");
        }

        else if(temp == 0){
            printf("\nTerima Kasih :) \n");
            printf("Tekan enter untuk keluar");
            getchar();
            getchar();
            running = 0;
        }

        else{
            printf("Error: Input Salah!\n");
        }
    }
}