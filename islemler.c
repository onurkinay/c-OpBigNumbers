/*
* @file islemler.c
* @description Fonksiyonların tutulduğu dosyadır
* @assignment Proje 2
* @date 30 December 2021
* @author Onur Kınay onur.kinay@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "islemler.h"

uint8_t *createBigNumber(int basamak) //sayının tutulacağı yeri ayırma ve adresi döndürme fonk.
{
    uint8_t *bigNumber = (uint8_t *)malloc(basamak * sizeof(uint8_t));

    for (int i = 0; i < basamak; i++)
    {
        *(bigNumber + i) = 0;
    }
    return bigNumber;
}

uint8_t *readFile(char *fileName, int maxBasamak) //dosya okuma ve diziye aktarma
{
    int charCount = DigitCounter(fileName);

    uint8_t *sayi = createBigNumber(maxBasamak);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("!!!HATA: %s ISIMLI DOSYA YOK!!!", fileName);
        exit(EXIT_FAILURE);
    }
    int i = 0;

    while (1)
    {
        int digit = fgetc(fp); //ascii olarak alır
        if (feof(fp))
            break;
        if (digit >= 48 && digit <= 57) // 0 = 48 <--> 9 = 57 //ascii
        {
            *(sayi + (maxBasamak - charCount) + i) = digit - 48; //ascii'den decimale çevirme
            i++;
        }
        else if (digit == 10) //alt satır(ascii 10) pas geçme
            continue;
        else
        { //sayı dışı(harf vs.) bir char varsa
            printf("!!!HATA: %s SAYI DOSYASI FORMATA UYGUN DEGIL!!! %d %d", fileName, digit, i);
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);

    return sayi;
}

int DigitCounter(char *fileName) // sayının kaç basamaklı olduğunu göster
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("!!!HATA: %s ISIMLI DOSYA YOK!!!", fileName);
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (1)
    {
        int digit = fgetc(fp);
        if (feof(fp))
            break;
        
        if (digit >= 48 && digit <= 57) // 0 -> 48 -- 9 -> 57 //ascii
            i++;
        else if (digit == 10) //alt satır(ascii 10) pas geçme
            continue;
        else
        { //sayı dışı(harf vs.) bir char varsa
            printf("!!!HATA: %s SAYI DOSYASI FORMATA UYGUN DEGIL!!! %d %d", fileName, digit, i);
            exit(EXIT_FAILURE);
        }
    }

    int fclose(FILE * fp);
    return i;
}

void saveArray(uint8_t *sayi, int length) //diziyi dosyaya kaydetme
{
    FILE *fp = fopen("sonuc.txt", "w");
    int ilkSifirlar = 1; // soldaki basamaklar 0 olanları es geçmek için kullanılacak => 000011204 --> 11204
    for (int i = 0; i < length; i++)
    {
        if (*(sayi + i) == 0 && ilkSifirlar)
            continue;
        fputc(*(sayi + i) + 48, fp);//ascii
        ilkSifirlar = 0;
    }
    printf("\n");
    fclose(fp);
}

void readArray(uint8_t *array, int length) //sayıyı ekrana yazdırma
{
    int ilkSifirlar = 1; // soldaki basamaklar 0 olanları es geçmek için 000011204 --> 11204
    for (int i = 0; i < length; i++)
    {
        if (*(array + i) == 0 && ilkSifirlar)
            continue;
        printf("%d", *(array + i));
        ilkSifirlar = 0;
    }
    printf("\n");
}

uint8_t *Sum(uint8_t *sayi1, uint8_t *sayi2, int max) //toplama işlemi
{
    uint8_t *sonuc = createBigNumber(max);

    int elde = 0;
    for (int i = max - 1; i >= 0; i--)
    {
        *(sonuc + i) = ((*(sayi1 + i) + *(sayi2 + i)) + elde) % 10;

        elde = ((*(sayi1 + i) + *(sayi2 + i)) + elde) / 10; //elde var
    }
    saveArray(sonuc, max); //sonucu dosya olarak kaydet
    return sonuc;
}

uint8_t *Diff(uint8_t *sayi1, uint8_t *sayi2, int max) //çıkarma işlemi
{
    uint8_t *sonuc = createBigNumber(max);
    int carry = 0;
    for (int i = max - 1; i >= 0; i--)
    {

        if ((int)(*(sayi1 + i) - *(sayi2 + i) - carry) >= 0) //iki basamağın farkı 0'dan az değil ise
        {
            *(sonuc + i) = ((*(sayi1 + i) - *(sayi2 + i)) - carry);
            carry = 0;
        }
        else
        {
            int j = 1;
            while (*(sonuc + i - j) == 0) //komşu basamağı sıfırdan farklı olanlara ziyaret et
            {
                *(sonuc + i - j) = 9; // bir tane ödünç aldım
                j++;
            }

            *(sonuc + i - j) = *(sonuc + i - j) - 1;
            *(sonuc + i) = ((*(sayi1 + i)) + (10 - carry)) - *(sayi2 + i);
            carry = 1;
        }
    }
    saveArray(sonuc, max);
    return sonuc;
}
