//
// Created by MI on 12.02.2021.
//

#ifndef INC_2FISH_TWOFISH_H
#define INC_2FISH_TWOFISH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define UINT unsigned int
#define BYTE unsigned char
#define RS_MOD 0x14D
#define RHO 0x01010101L

void printSubkeys(UINT K[40]);
void fullKey(UINT L[4], int k, UINT QF[4][256]);
void keySchedule(BYTE M[], int N, UINT **S, UINT K[40], int *k);
void encrypt(const UINT K[40], UINT S[const 4][256], BYTE PT[16]);
void decrypt(const UINT K[40], UINT S[4][256], BYTE PT[16]);
void printHex(BYTE b[], int lim);


#endif //INC_2FISH_TWOFISH_H
