#ifndef HAMMING_H
#define HAMMING_H

#define LEN 4
#define C_LEN 7
#define T_LEN 3
#define GL 7
#define GC 4
#define HL 3
#define HC 7

int checkAndFixArray(int cod[], int test[]);
void getHammingParityArray(int cod[], int test[]);
void clearScreen(void);
void printArray(int arr[], int length);
void convertIntToArray(int option, int value, int arr[]);
void codifyHamming(int arr[], int cod[]);
void insertError(int cod[]);
#endif