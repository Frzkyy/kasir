#include <stdio.h>
#include "menu.h"
#include "barang.h"

/*Print keranjang, 
(jika variabel "terisi" = 1, maka artinya dimasukan ke keranjang)*/
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

/*Memasukan barang ke keranjang dengan ID, 
(Menambah variabel "terisi" dan "jumlah" pada barang dengan ID ditentukan) */
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

/*Mereset keranjang menjadi kosong, 
(membuat semua barang variabel "terisi" dan "jumlah" = 0) */
void resetKeranjang(Barang brg[], int banyakBarang){
    for(int i=0;i<banyakBarang;i++){
        brg[i].terisi = 0;
        brg[i].jumlah = 0;
    }
}


//Melihat apakah ID yang diberikan ada didalam barang
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

/*Melihat apakah barang dengan ID yang diberikan terisi/masuk keranjang, 
(Melihat variabel "terisi" apakah 0 atau 1) */
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

/*Menghapus barang dengan id yang diberikan pada keranjang, 
(mengubah variabel "terisi" dan "jumlah" barang dengan id yang diberikan )*/
void hapusKeranjang(Barang brg[], int id, int banyakBarang){
    for(int i=0;i<banyakBarang;i++){
        if(brg[i].ID == id){
            brg[i].jumlah = 0;
            brg[i].terisi = 0;
        }
    }
}

//Menghitung total belanja pada keranjang dengan melihat "harga","jumlah", dan "diskon"
void printTotalBelanja(Barang brg[], int banyakBarang){
    float total = 0.0;
    for(int i=0;i<banyakBarang;i++){
        if(brg[i].terisi == 1){
            total += brg[i].harga * brg[i].jumlah * (1 - brg[i].diskon);
        }
    }
    printf("Total: %.0f\n",total);
}


//Menghitung total belanja untuk dibayar, dan input uang
void totalBelanjaan(Barang brg[], int banyakBarang){
    int uang, run = 1;
    float total=0;
    printf("Masukan uang: ");
    scanf("%d", &uang);

    for(int i=0;i<banyakBarang;i++){
        if(brg[i].terisi == 1){
            total += (brg[i].harga * brg[i].jumlah * (1 - brg[i].diskon));
        }
    }

    printf("=======================================\n");
    printf("Uang: %d\n", uang);
    printf("Total: %.0f\n", total);
    if(uang >= total){
        printf("Kembalian: %.0f\n", ((float)uang - total));
    }else{
        printf("Maaf, Uang Kurang\n");
    }
    printf("=======================================\n\n");

    while(run){
        int pilih;
        printf("Apakah Masih Ingin Mengedit Barang?\n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Masukan Angka diatas: ");
        scanf("%d", &pilih);
        if(pilih == 1){
            break;
        }else if(pilih == 2){
            resetKeranjang(brg,banyakBarang);
            break;
        }else{
            printf("\nError: Input Salah!\n");
        }

    }
    
}


//Program utama, dan menu kasir
void kasir(Barang brg[], int banyakBarang){
    int running = 1;
    do{
        int temp;
        printf("\n=============================================================================================\n");
        printf("                               Selamat Datang di Bubadibako\n");
        printf("=============================================================================================\n");

        printf("Keranjang:\n");
        printf("_____________________________________________________________________________________________\n");
        printf("%-3s %-15s %-8s %-8s %-12s %s\n", "No", "Nama", "ID", "Jumlah", "Harga", "Diskon");
        printf("_____________________________________________________________________________________________\n");
        printKeranjang(brg, banyakBarang);
        printf("_____________________________________________________________________________________________\n");
        printTotalBelanja(brg,banyakBarang);
        printf("_____________________________________________________________________________________________\n");
        printf("                               Menu Pilihan\n\n");
        printf(">> 1. List Barang\n");
        printf(">> 2. Tambahkan/Edit Barang\n");
        printf(">> 3. Hapus Barang\n");
        printf(">> 4. Selesai\n");
        printf(">> 0. Keluar\n");
        printf("_____________________________________________________________________________________________\n");
        printf("Ketik angka diatas untuk melanjutkan: ");
        scanf("%d", &temp);


        switch (temp){
        case 1:
            printList(brg, banyakBarang);
            break;
        
        case 2:
            
            while(1){
                int idBarang;
                printf("Masukan ID Barang, Jika tidak tahu ketik 0: ");
                scanf("%d", &idBarang);

                if(idBarang == 0){
                    break;
                }
                else if(validID(brg, idBarang, banyakBarang)){
                    inputKeranjang(brg, idBarang, banyakBarang);
                    break;
                }
                else{
                    printf("Error: ID tidak valid!\n");
                }
            }
            break;
        
        case 3:
            while(1){
                int idBarang;
                printf("Masukan ID Barang, Jika tidak tahu ketik 0: ");
                scanf("%d", &idBarang);

                if(idBarang == 0){
                    break;
                }
                else if(validID(brg, idBarang, banyakBarang) == 0){
                    printf("Error: ID tidak valid!\n");
                }
                else if(validIsi(brg, idBarang,banyakBarang)){
                    hapusKeranjang(brg,idBarang,banyakBarang);
                    break;
                }
                else{
                    printf("Error: Barang tidak ada di keranjang!\n");
                }
            }
            break;

        case 4:
            int valid = 0;
            for(int i=0;i<banyakBarang;i++){
                if(brg[i].terisi == 1){
                    valid = 1;
                    break;
                }
            }

            if(valid){
                totalBelanjaan(brg,banyakBarang);

            }else{
                printf("\nError: Mohon Masukan Barang Terlebih Dahulu!\n");
            }
            break;

        case 0:
            printf("\nTerima Kasih :) \n");
            printf("Tekan enter untuk keluar");
            getchar();
            getchar();
            running = 0;
            break;

        default:
            printf("Error: Input Salah!\n");
            break;
        }
             
    }while (running);
    





}