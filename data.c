#include <stdio.h>
#include "data.h"
#include "barang.h"

void inputKeranjang(Barang brg[], int id, int banyakBarang){
    int jumlah;
    printf("Masukan banyak Barang: ");
    scanf("%d", &jumlah);
    for(int i=0;i<banyakBarang;i++){
        if(brg[i].ID == id && jumlah > 0){
            brg[i].terisi = 1;
            brg[i].jumlah = jumlah;
        }
    }

}

void printKeranjang(Barang brg[], int banyakBarang){
    int no = 0;
    for(int i=0;i<banyakBarang;i++){
        if(brg[i].terisi == 1){
            no++;
            float harga = brg[i].harga * brg[i].jumlah * (1 - brg[i].diskon);
            printf("%-3d %-15s %-8d %-8d %-12.0f %.0f%c\n",
               no, brg[i].nama, brg[i].ID ,brg[i].jumlah, harga, (brg[i].diskon * 100),'%');
        }
    }
}


int validID(Barang brg[], int id, int panjangBarang){
    int temp= 0;
    for(int i=0; i<panjangBarang; i++){
        if(id == brg[i].ID){
            temp = 1;
        }
    }
    if(temp){
        return 1;
    }else{
        return 0;
    }
}

int validIsi(Barang brg[], int idBarang, int panjangBarang){
    int temp= 0;
    for(int i=0; i<panjangBarang; i++){
        if(brg[i].terisi == 1 && brg[i].ID == idBarang){
            temp = 1;
        }
    }
    if(temp){
        return 1;
    }else{
        return 0;
    }
}

void hapusKeranjang(Barang brg[], int id, int banyakBarang){
    for(int i=0;i<banyakBarang;i++){
        if(brg[i].ID == id){
            brg[i].jumlah = 0;
            brg[i].terisi = 0;
        }
    }
}

void printTotalBelanja(Barang brg[], int banyakBarang){
    float total = 0.0;
    for(int i=0;i<banyakBarang;i++){
        if(brg[i].terisi == 1){
            total += brg[i].harga * brg[i].jumlah * (1 - brg[i].diskon);
        }
    }
    printf("Total: %.0f\n",total);
}

void kasir(Barang brg[], int banyakBarang){
    int running = 1;

    while(running){
        int temp;
        printf("\n=============================================================================================\n");
        printf("                               Selamat Datang di Indomaret\n");
        printf("=============================================================================================\n");

        printf("Keranjang:\n");
        printf("_____________________________________________________________________________________________\n");
        printf("%-3s %-15s %-8s %-8s %-12s %s\n", "No", "Nama", "ID", "Jumlah", "Harga", "Diskon");
        printf("_____________________________________________________________________________________________\n");
        printKeranjang(brg, banyakBarang);
        printf("_____________________________________________________________________________________________\n");
        printTotalBelanja(brg,banyakBarang);
        printf("_____________________________________________________________________________________________\n");
        printf("                           Masukan Produk Pelanggan\n\n");
        printf("1. List Barang\n");
        printf("2. Tambahkan Barang\n");
        printf("3. Hapus Barang\n");
        printf("4. Selesai\n");
        printf("0. Keluar\n");
        printf("_____________________________________________________________________________________________\n");
        printf("Ketik angka diatas untuk melanjutkan: ");
        scanf("%d", &temp);


        if(temp == 1){  
            printList(brg, banyakBarang);
        }

        else if(temp == 2){
            int idBarang;
            int runn = 1;
            

            while(runn){
                printf("Masukan ID Barang, Jika tidak tahu ketik 0: ");
                scanf("%d", &idBarang);

                if(idBarang == 0){
                    runn = 0;
                }
                else if(validID(brg, idBarang, banyakBarang)){
                    inputKeranjang(brg, idBarang, banyakBarang);
                    runn = 0;
                }
                else{
                    printf("Error: ID tidak valid!\n");
                }
            }
        }

        else if(temp == 3){
            int idBarang;
            int runn = 1;
            while(runn){
                printf("Masukan ID Barang, Jika tidak tahu ketik 0: ");
                scanf("%d", &idBarang);

                if(idBarang == 0){
                    runn=0;
                }
                else if(validID(brg, idBarang, banyakBarang) == 0){
                    printf("Error: ID tidak valid!\n");
                }
                else if(validIsi(brg, idBarang,banyakBarang)){
                    hapusKeranjang(brg,idBarang,banyakBarang);
                    runn=0;
                }
                else{
                    printf("Error: Barang tidak ada di keranjang!\n");
                }
            }
        }
        else if(temp == 4){
            int valid = 0;
            for(int i=0;i<banyakBarang;i++){
                if(brg[i].terisi == 1){
                    valid = 1;
                }
            }

            if(valid){
                printf("Valid\n");
            }else{
                printf("\nError: Mohon Masukan Barang Terlebih Dahulu!\n");
            }
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