#include <stdio.h>

typedef struct
{
    int num;
    int isFilled;
    int much;
}numm;

typedef struct
{
    int id;
    int angka;
} barang;

void inputBarang(barang *brg, int id, int angka){
    brg->angka = angka;
    brg->id = id;

}

int validID(barang *brg, int id, int panjangBarang){
    int temp= 0;
    for(int i=0; i<panjangBarang; i++){
        if(id == brg[i].id){
            temp = 1;
        }
    }
    if(temp){
        return 1;
    }else{
        return 0;
    }
}


int main()
{ 

    barang inventory[5];

    inputBarang(&inventory[0], 01, 300);
    inputBarang(&inventory[1], 02, 400);
    inputBarang(&inventory[2], 03, 500);
    inputBarang(&inventory[3], 04, 600);
    inputBarang(&inventory[4], 05, 700);

    numm list[100];
    for(int i = 0; i< 100; i++){
        list[i].isFilled = 0;
    }



    while (1)
    {
        int tempNum, tempJumlah, indx=0;
        printf("Masukan Angka 1,2,3,4,5 dan 0 untuk keluar: ");
        scanf("%d",&tempNum);
        if(tempNum == 0){
            break;
        }
        if(validID(inventory, tempNum, 5) == 0){
            printf("Masukan Angka yang Valid\n");
            continue;
        }
        printf("Masukan Jumlah: ");
        scanf("%d", &tempJumlah);

        while(list[indx].isFilled == 1){
            indx++;
        }

        list[indx].num = tempNum;
        list[indx].much = tempJumlah;
        list[indx].isFilled = 1;
        printf("\n");
    }
    
    int index = 0;
    while(index < 100 && list[index].isFilled == 1){
        printf("Angka - %d\n", list[index].num);
        printf("Jumlah - %d\n", list[index].much);
        index++;
    }
    return 0;
}
