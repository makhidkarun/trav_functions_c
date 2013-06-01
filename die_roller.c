/*
 * Working on putting this together in a clean way.
 * So far it isn't.  :)
 */

# include <stdio.h>
# include <getopt.h>
# include <stdlib.h>
# include <unistd.h>
# include "dice.h"

# define VERSION 0.01

int helper() {
    /* No long options enabled yet.  */

    printf("Usage:  die_roller [options]  \n");
    printf("\t -a    Number, positive or negative, to be added to the total\n");
    printf("\t -e    Explode die if roll MAX\n");
    printf("\t -h    Help information\n");
    printf("\t -m    Minimum die number\n");
    printf("\t -M    Maximum die number\n");
    printf("\t -n    Number of die\n");
    printf("\t -t    Return 0 if roll vs target number. Defaults to -t 8\n");
    printf("\t -V    Version information\n");
 
    printf("Of the options, -a, -m, -M, -n, and -t require an extra argument.\n");
    printf("For example, die_roller -n 2 -m 1 -M 6\n");
    printf("Would roll 2d6.\n");
    printf("This is the default action, given no other options.\n");

    return 0;
};

int main(int argc, char *argv[]) {

    int roll = 0;
    int loop = 0;
    int ch ;
    int roll_mod = 0;
    int explode = 0;

    int roll_min = 1;
    int roll_max = 6;
    int num_die = 2;
    int target = 0; 
    char *result = "Failed";

    while (( ch = getopt(argc, argv, "a:ehm:M:n:t:v")) != EOF)
        switch(ch) {
            case 'a':
                roll_mod = atoi(optarg);
                break;
            case 'e':
                explode = 1;
                break;
            case 'h':
                helper();
                return 0;
            case 'm':
                roll_min = atoi(optarg);
                break;
            case 'M':
                roll_max = atoi(optarg);
                break;
            case 'n':
                num_die = atoi(optarg);
                break;
            case 't':
                target = atoi(optarg);
                break;
            case 'v':
                printf("Version: %2.2f.\n", VERSION);
                return 0;
        }
    
    argc -= optind;
    argv += optind;
   
    for (loop = 0; loop < num_die; loop++) { 
        roll += get_rand(roll_min, roll_max);
    }
    if (roll_mod) {
        roll += roll_mod;
    }

    if (target > 0)  {
        if ( roll >= target ) {
            result = "Success";
        }
        printf("Rolled %d vs %d. %s!\n", roll, target, result);
    } else {
        printf("%d\n", roll);
    }
      
    return 0;
}

