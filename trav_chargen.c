#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "dice.h"

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

int main(int argc, char *argv[]) {

    int j; 
    int ch;

    if (argc > 1 ){
        while (( ch = getopt(argc, argv, "ahrs")) != EOF) {
         switch(ch) {
             case 'a':   
                 for ( j = 0; j < UPP_LEN; j++) {
                     UPP[j] = roll_average_traveller_stat();
                 }
                 break;
             case 'h':
                 printf("-a <average stats>, -s <strong stats>\n");
                 printf("Default is 2-C.\n");
                 return 0;
             case 's':
                 for ( j = 0; j < UPP_LEN; j++) {
                     UPP[j] = roll_strong_traveller_stat(2) ;
                 }
                 break;
             default:
                 printf("-a <average stats>, -s <strong stats>\n");
                 printf("Default is 2-C.\n");
                 return 0;
         }
        }
    } else {
      for ( j = 0; j < UPP_LEN; j++) {
         UPP[j] = roll_2d6();
       }
    }



    printf("UPP: ");
    for ( j = 0; j < UPP_LEN; j++) {
        printf("%X", UPP[j]);
    }
    printf("\n");
    return 0;
}

