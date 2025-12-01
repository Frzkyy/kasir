# Program Kasir Sederhana — Bahasa C

Program ini adalah aplikasi kasir sederhana yang dibuat menggunakan bahasa C.  
Aplikasi ini memiliki fitur untuk menampilkan daftar barang, memasukkan barang ke keranjang, menghapus barang, menghitung total belanja, dan melakukan transaksi.

Struktur program dibagi menjadi beberapa file (`main.c`, `menu.c`, `barang.c`, `tools.c`) agar mudah dibaca, dipelihara, dan dikembangkan.
---
## Fitur

- Menampilkan daftar barang
- Memasukkan barang ke keranjang berdasarkan ID
- Menghapus barang dari keranjang
- Menghitung total belanja termasuk diskon
- Menampilkan kembalian berdasarkan uang yang dimasukkan
- Reset otomatis keranjang setelah transaksi
- Validasi ID barang dan validasi isi keranjang

## Struktur File

main.c
tools.h
tools.c
barang.h
barang.c
menu.h
menu.c
---
## Cara Melakukan Kompilasi

```
gcc meain.c tools.c tools.h barang.h barang.c menu.h menu.c -o main
```
Lalu Jalankan
```
./main
```
---
## Requirement
Program ini hanya membutuhkan:
- Compiler C (GCC/MinGW/Clang)
- Terminal / Command Prompt
Tidak ada library tambahan selain standard library C.
---
## Penjelasan Singkat Modul

### **1. barang.c / barang.h**
Mengelola data barang, seperti:
- ID barang  
- Nama barang  
- Harga  
- Diskon  
- Status masuk keranjang  
- Jumlah barang  

### **2. menu.c / menu.h**
Mengatur seluruh sistem kasir:
- Menambah barang ke keranjang  
- Menghapus barang  
- Menampilkan keranjang  
- Menghitung total  
- Menu interaktif  

### **3. tools.c / tools.h**
Berisi fungsi utilitas seperti:
- `strcopy()` (pengganti `strcpy()`)

### **4. main.c**
Tempat eksekusi program:
- Inisialisasi barang  
- Menjalankan menu kasir utama  
