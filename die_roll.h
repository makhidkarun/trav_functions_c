/*
Die Roller implemented in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_rand(int min, int max) {
	static int init = 0;
	int roll;

	if (init == 0) {
		srand(time(NULL));
		init = 1;
	}

	roll = (rand() % (max - min + 1) + min );
	
    return roll;
}

int roll_2d6() {
    int roll;
    roll = get_rand(1,6) + get_rand(1,6);
    return roll;
}

int roll_1d6() {
    int roll;
    roll = get_rand(1,6);
    return roll;
}

int roll_2d6_vs(int target) {
    int roll;
    int success = 0;

    roll = roll_2d6();
    if (roll >= target) {
        success = 1;
    }
    return success;
}

int roll_average_stat() {
    int roll;
    roll = get_rand(2,5) + get_rand(2,5);
    return roll;
}

