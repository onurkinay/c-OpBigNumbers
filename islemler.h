#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t* readFile(char*, int);
int CharCounter(char*);
void readArray(uint8_t*, int);
uint8_t* Sum(uint8_t* , uint8_t*, int);
uint8_t* Diff(uint8_t* , uint8_t*, int);
uint8_t* createBigNumber(int);
void saveResult(uint8_t* , int);