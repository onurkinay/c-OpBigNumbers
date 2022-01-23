/*
* @file islemler.h
* @description Fonksiyon prototiplerin tutulduğu dosyadır
* @assignment Proje 2
* @date 30 December 2021
* @author Onur Kınay onur.kinay@stu.fsm.edu.tr
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifndef __ISLEMLER_H__
#define __ISLEMLER_H__

uint8_t* createBigNumber(int);
uint8_t* readFile(char*, int);
int DigitCounter(char*);
void saveArray(uint8_t* , int);
void readArray(uint8_t*, int);
uint8_t* Sum(uint8_t* , uint8_t*, int);
uint8_t* Diff(uint8_t* , uint8_t*, int);

#endif

