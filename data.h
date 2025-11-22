#ifndef DATA_H
#define DATA_H
#include "barang.h"

void totalBelanjaan(Barang brg[], int banyakBarang);
void resetKeranjang(Barang brg[], int banyakBarang);
void printTotalBelanja(Barang brg[], int banyakBarang);
void hapusKeranjang(Barang brg[], int id, int banyakBarang);
int validIsi(Barang brg[], int idBarang,int panjangBarang);
void kasir(Barang brg[], int banyakBarang);
int validID(Barang *brg, int id, int panjangBarang);

#endif