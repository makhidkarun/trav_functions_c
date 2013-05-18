#include <stdio.h>
#include <string.h>
#include "./die_roll.h"

#define UPP_LEN 6
#define STR 0
#define DEX 1
#define END 2
#define INT 3
#define EDU 4
#define SOC 5

int UPP[6];
char UPP_SYM[][4] = {
    "STR",
    "DEX",
    "END",
    "INT",
    "EDU",
    "SOC",
};

int main(void) {

    int j; 
    for ( j = 0; j < UPP_LEN; j++) {
        UPP[j] = roll_average_stat();
    }

    printf("UPP: ");
    for ( j = 0; j < UPP_LEN; j++) {
        printf("%X", UPP[j]);
    }
    printf("\n");
}
