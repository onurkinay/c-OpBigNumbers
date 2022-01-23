/*
* @file main.c
* @description Ana program dosyasıdır
* @assignment Proje 2
* @date 30 December 2021
* @author Onur Kınay onur.kinay@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "islemler.h"

int main()
{

    char islem = '0';

    int sayi1Basamak = -1;//sayıBir'in basamağı
    int sayi2Basamak = -1;//sayı iki'in basamağı
    int max = -1;//maksimum basamak

    /* 
        Büyük sayıların tutulacağı değişkenler
    */
    uint8_t *sayi1;
    uint8_t *sayi2;
    uint8_t *sonuc;

    int islemYapildiMi = 0;//işlem gerçekleştirilmiş mi??

    while(1)//MENÜ EKRANI
    {
        printf("\n==================Buyuk sayilar ile matematiksel islemler=================\n");
        
        printf("[1]-> Dosyadan sayilari oku: (1)\n");
        printf("[2]-> Okunan sayilari ekrana yaz: (2)\n");
        printf("[+/-]-> Islem seciniz: (+ veya -)\n");
        printf("[4]-> Sonucu ekrana yazdir: (4)\n");
        printf("[5]-> Cikis : (5)\n");

        scanf("%c", &islem);

        if (islem == '1')//Dosyadan sayilari oku
        {
            sayi1Basamak = CharCounter("sayi1.txt");//basamak sayacı
            sayi2Basamak = CharCounter("sayi2.txt");

            max = ((sayi1Basamak > sayi2Basamak) ? sayi1Basamak : sayi2Basamak) + 1;//kimin sayının basamağı en fazla??

            sayi1 = readFile("sayi1.txt", max);
            sayi2 = readFile("sayi2.txt", max);

            printf("!!!SAYILAR BASARILI BIR SEKILDE ALINDI!!!\n");
        }
        else if (islem == '2')//Okunan sayilari ekrana yaz
        {
            if (sayi1Basamak == -1 || sayi2Basamak == -1 || max == -1)//Daha önce dosya okunmadıysa
            {
                printf("!!!ONCELIKLE DOSYA OKUYUNUZ!!!\n");
            }
            else
            {
                printf("\n===SAYI 1===\n");
                readArray(sayi1, max);
                printf("\n===SAYI 1 SONU===\n");
                printf("\n===SAYI 2===\n");
                readArray(sayi2, max);
                printf("\n===SAYI 2 SONU===\n");
            }
        }
        else if (islem == '+' || islem == '-')//IŞLEM YAPMA
        {
            if (sayi1Basamak == -1 || sayi2Basamak == -1 || max == -1)//Daha önce dosya okunmadıysa
            {
                printf("!!!ONCELIKLE DOSYA OKUYUNUZ!!!\n");
            }
            else if (islem == '+')//TOPLAMA IŞLEMI
            {
                sonuc = Sum(sayi1, sayi2, max);
                islemYapildiMi = 1;
                printf("ISLEM BASARIYLA GERCEKLESTIRILDI VE DOSYA OLARAK KAYDEDILDI\n");
            }
            else if (islem == '-')//ÇIKARMA İŞLEMİ
            {
                sonuc = Diff(sayi1, sayi2, max);
                islemYapildiMi = 1;
                printf("ISLEM BASARIYLA GERCEKLESTIRILDI VE DOSYA OLARAK KAYDEDILDI\n");
            }
        }
        else if (islem == '4')//Sonucu ekrana yazdır
        {
            if (sayi1Basamak == -1 || sayi2Basamak == -1 || max == -1)
                printf("!!!ONCELIKLE DOSYA OKUYUNUZ!!!\n");

            else if (islemYapildiMi)
                readArray(sonuc, max);
            else
                printf("ONCELIKLE ISLEMI GERCEKLESTIRINIZ\n");
        }
        else if (islem == '5')//Çıkış
            break; 
        else//herhangi komut yok ise
        { 
            printf("GECERSIZ KOMUT\n");
        }

        printf("DEVAM ETMEK ICIN ENTER\n");
        getchar();
        getchar();
    } 

    free(sayi1);//memory temizle
    free(sayi2);
    free(sonuc);
}