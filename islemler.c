#include <stdio.h>
#include <stdlib.h>
#include "islemler.h"

int readFile(char *fileName, int *array)
{
    int charCount = CharCounter(fileName);
    
    FILE *fp = fopen(fileName, "r");
    int i = 0;
 
    while (1)
    {
        int buff = fgetc(fp);
        if (feof(fp))
            break;
        if (buff >= 48 && buff <= 57)
        {
            *(array + i) = buff-48; 
            i++;
        }
    }

    int fclose(FILE * fp);
 
    return charCount;
}

int CharCounter(char *fileName)
{
    FILE *fp = fopen(fileName, "r");
    int i = 0;
    while (1)
    {
        int number = fgetc(fp);
        if (feof(fp))
            break;
        if (number > 47 && number < 58)
            i++;
    }
    int fclose(FILE * fp);
    return i;
}

void readArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d", *(array + i));
    }
    printf("\n");
}

int* doMath(int* sayi1, int* sayi2, int sayi1_b,int sayi2_b){
      
    int max = (sayi1_b>sayi2_b) ? sayi1_b : sayi2_b;
    int min = (sayi1_b>sayi2_b) ? sayi2_b : sayi1_b;
    int *sonuc = (int *)malloc(max * sizeof(int));
    int j = 0;
    min--;
    int elde = 0;
    for (int i = max-1; i >= 0; i--)
    {
        *(sonuc+i) = ((*(sayi1+i) + *(sayi2+min-j))+elde)%10;
        elde = ((*(sayi1+i) + *(sayi2+min-j))+elde) / 10;
        j++;
    }
  
    return sonuc;
}