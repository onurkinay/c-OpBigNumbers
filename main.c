#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "islemler.h"

int main()
{

    int sayi1Basamak = CharCounter("sayi1.txt");
    int sayi2Basamak = CharCounter("sayi2.txt");

    int max = ((sayi1Basamak>sayi2Basamak) ? sayi1Basamak : sayi2Basamak)+1;
 
    uint8_t *sayi1 = readFile("sayi1.txt", max); 
    uint8_t *sayi2 = readFile("sayi2.txt", max);

     
    uint8_t* sonuc = doMath(sayi1,sayi2,max);
  
    
    //readArray(sonuc,max);
     
}