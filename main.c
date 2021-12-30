#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "islemler.h"

int main()
{

    int *sayi1 = (int *)malloc(CharCounter("sayi1.txt") * sizeof(int));
    int *sayi2 = (int *)malloc(CharCounter("sayi2.txt") * sizeof(int));

    int sayi1_b = readFile("sayi1.txt", sayi1);
    
    int sayi2_b = readFile("sayi2.txt", sayi2);

     
    int* sonuc = doMath(sayi1,sayi2,sayi1_b,sayi2_b);
  
    readArray(sonuc,sayi1_b);
     
}