#include <stdio.h>
#include "barang.h"
#include "tools.h"

//print seluruh variabel "Id","Nama","Harga","Diskon" barang dalam bentuk list
void printList(Barang brg[], int banyakBarang){
    printf("\n================================\n");
    printf("%-3s %-5s %-12s %-10s %-8s\n", "No", "ID", "Nama", "Harga", "Diskon");
    for(int i = 0; i < banyakBarang; i++){
        printf("%-3d %-5d %-12s %-10d %-8.2f\n",
               i+1, brg[i].ID, brg[i].nama, brg[i].harga, brg[i].diskon);
    }
    printf("\n================================\n");
    printf("Tekan enter untuk melanjutkan");
    getchar();
    getchar();
    printf("\n");
}

//Input barang ke dalam database
void inputBarang(Barang *brg, int id, const char name[], int harga, float diskon){
    strcopy(brg->nama, name);
    brg->ID = id;
    brg->harga = harga;
    brg->diskon = diskon;
    brg->jumlah = 0;
    brg->terisi = 0;
}