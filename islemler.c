#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "islemler.h"

uint8_t *readFile(char *fileName, int maxBasamak)
{
    int charCount = CharCounter(fileName);

    uint8_t *sayi = createBigNumber(maxBasamak);

    FILE *fp = fopen(fileName, "r");
    int i = 0;

    while (1)
    {
        int buff = fgetc(fp);
        if (feof(fp))
            break;
        if (buff >= 48 && buff <= 57)
        {
            *(sayi + (maxBasamak - charCount) + i) = buff - 48;
            i++;
        }
    }

    fclose(fp);

    return sayi;
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

void readArray(uint8_t *array, int length)
{
    int ilkSifirlar = 1;
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) == 0 && ilkSifirlar)
            continue;
        printf("%d", *(array + i));
        ilkSifirlar = 0;
    }
    printf("\n");
}

uint8_t *Sum(uint8_t *sayi1, uint8_t *sayi2, int max)
{
    uint8_t *sonuc = createBigNumber(max);

    int elde = 0;
    for (int i = max - 1; i >= 0; i--)
    {
        *(sonuc + i) = ((*(sayi1 + i) + *(sayi2 + i)) + elde) % 10;

        elde = ((*(sayi1 + i) + *(sayi2 + i)) + elde) / 10;
    }
    saveResult(sonuc, max);
    return sonuc;
}

uint8_t *Diff(uint8_t *sayi1, uint8_t *sayi2, int max)
{
    uint8_t *sonuc = createBigNumber(max);
    int carry = 0;
    for (int i = max - 1; i >= 0; i--)
    {

        if ((int)(*(sayi1 + i) - *(sayi2 + i) - carry) >= 0)
        {
            *(sonuc + i) = ((*(sayi1 + i) - *(sayi2 + i)) - carry);
            carry = 0;
        }
        else
        { 
            int j = 1;
            while ( *(sonuc + i - j) == 0)
            {
                *(sonuc + i - j) = 9;
                j++;
            }

            *(sonuc + i - j) = *(sonuc + i - j) - 1;
            *(sonuc + i) = ( (*(sayi1 + i)) + (10-carry) ) - *(sayi2 + i);
            carry = 1;
        }
    }
    saveResult(sonuc, max);
    return sonuc;
}

uint8_t *createBigNumber(int basamak)
{
    uint8_t *bigNumber = (uint8_t *)malloc(basamak * sizeof(uint8_t));

    for (int i = 0; i < basamak; i++)
    {
        *(bigNumber + i) = 0;
    }
    return bigNumber;
}

void saveResult(uint8_t *sayi, int length)
{
    FILE *fp = fopen("sonuc.txt", "w");
    int ilkSifirlar = 1;
    for (int i = 0; i < length; i++)
    {
        if (*(sayi + i) == 0 && ilkSifirlar)
            continue;
        fputc(*(sayi + i) + 48, fp);
        ilkSifirlar = 0;
    }
    printf("\n");
    fclose(fp);
}
