/* 
 * File: hw1_lib.c
 * gcc -c hw1_lib.c -o hw1_lib.o
 * gcc -S hw1_lib.c -o hw1_lib.s
 * objdump -D hw1_lib.o
 */
#include "hw1_lib.h"

uint16_t gray_to_binary(uint16_t gray)
{
	uint16_t get_val= 0b1000000000000000;
	uint16_t val1, val2, bin_val, temp;
        unsigned char i;

        bin_val = gray & get_val;
        val1 = bin_val;
        for(i=1; i<16; i++) {
                val1>>=1;
                val2 = gray & (get_val >> 1);
                bin_val|=(val1 ^ val2);
                get_val>>=1;
                val1 = (bin_val & get_val);
        }
	gray = bin_val;
	return gray;
}

uint16_t binary_to_gray(uint16_t binary)
{
	uint16_t get_val= 0b1000000000000000;
        uint16_t val1, val2, gray_val, temp;
        unsigned char i;

        gray_val = binary & get_val;
        for(i=1; i<16; i++) {
                val1 = binary & get_val;
                val1>>=1;
                val2 = binary & (get_val >> 1);
                gray_val|=(val1 ^ val2);
                get_val>>=1;
        } 
	binary = gray_val;
	return binary;
}


