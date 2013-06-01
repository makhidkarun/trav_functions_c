# Makefile for the trav_functions_c stuff.
#

CC = gcc
CFLAGS = -Wall -Werror -std=c99
CFLAGS_OBJ = ${CFLAGS} -c

dice.o: dice.c dice.h
	${CC} ${CFLAGS_OBJ} dice.c 

dice: dice.o
	${CC} ${CFLAGS} dice.o -o dice

die_roller.o: dice.o die_roller.c
	${CC} ${CFLAGS_OBJ} die_roller.c

die_roller: die_roller.o 
	${CC} ${CFLAGS} die_roller.o dice.o -o die_roller




