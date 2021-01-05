#include <stdio.h>
#include <string.h>
#include "bandb.h"
//  File Name: bandb.c
//  Author: Rehan Nagoor Mohideen
//  Student ID: 1100592
//  Purpose: Contain functions for 2520 assignment 1


void getbytes( unsigned char dest[], int bytes, void *src, int reverse) {
    int i;
    unsigned char *temp = src;
    if (reverse == 0) {
        //Copy files in characters (every 8 bits).
        for (i = 0; i < bytes; i++) {
            dest[i] = temp[i];
        }
        
    } else {
        //Copy files in reverse so copying the last file to first destination and so on.
        for (i = 0; i < bytes; i++) {
            dest[i] = temp[bytes -1 - i];
        }
    }
    
}


void getbits( char dest[], int bytes, void *src, int start, int end) {
    unsigned char *bits = src;
    int i, byte, bit;
    int count = 0;
    //for every bit we need to convert
    for (i = start; i > end; i--) {
        byte = i/8;
        bit = i%8;
        //checking if the bit we need to get is a 1 by bit shifting to the bit in lsb & operator with 1
        if ((bits[bytes - byte - 1] >> bit) & 1) {
            dest[count++] = '1';
        } else {
            dest[count++] = '0';
        }
        
    }
    dest[start - end] = '\0';
    
}


unsigned long long bits2ull( char *bits ) {
    unsigned long long ull = 0;
    int nobits = strlen(bits);
    int i;
    unsigned long long value;
    //for every bit in bits
    for (i = 0; i < nobits; i++) {
        //checking if bits are 1 from lsb to msb
        if (bits[nobits - i - 1] == '1') {
            value = 1;
            value = value << i; //getting the appropriate value(2^i) of the bit
            
            ull = ull + value; //switching the appropriate bit to 1 when needed
        }
    }
    
    return ull;
}


long long bits2ll( char *bits ) {
    long long ll = 0;
    int nobits = strlen(bits);
    int i;
    long long value;
    //for every bit in bits
    for (i = 0; i < nobits; i++) {
        //checking if bits are 1 from lsb to msb
        if (bits[nobits - 1 - i] == '1') {

            if (i == nobits-1) {//if the msb in the array == 1 then switch to negative
                value = 1;
                value = value << i;

                ll = ll - value;

            } else {
                value = 1;
                value = value << i;

                ll = ll + value;
            }
        }
    }
    
    return ll;
}


void spff( char *sign, char *exponent, char *significand, float *src ) {
    //check sign bit
    if (*src > 0) {
        sign[0] = '0';
    } else {
        sign[0] = '1';
    }
    sign[1] = '\0';

    unsigned char bytes[4];
    //to flip bits to get it in right order
    getbytes( bytes, sizeof(float), src, 1 );
    //get the bits for the exponent and mantissa
    getbits( exponent, sizeof(float), bytes, 30, 22 );
    getbits( significand, sizeof(float), bytes, 22, -1 );
}


void dpff( char *sign, char *exponent, char *significand, double *src ) {
    //check sign bit
    if (*src > 0) {
        sign[0] = '0';
    } else {
        sign[0] = '1';
    }
    sign[1] = '\0';

    unsigned char bytes[8];
    //to flip bits to get it in right order
    getbytes( bytes, sizeof(double), src, 1 );
    //get the bits for the exponent and mantissa
    getbits( exponent, sizeof(double), bytes, 62, 51 );
    getbits( significand, sizeof(double), bytes, 51, -1 );
}
