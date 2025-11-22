#ifndef BARANG_H
#define BARANG_H

typedef struct
{
    int ID;
    char nama[50];
    int harga;
    float diskon;
} Barang;

void printBarang(Barang brg);
void printList(Barang brg[], int banyakBarang);
void inputBarang(Barang brg[], int id, const char name[], int harga, float diskon);
void cariBarang(Barang brg[], int id, int banyakBarang);

#endif
