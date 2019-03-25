#using tcc compiler
# tcc main.c src/* -o wtimewakeup

#using musl wrapper to gcc
#musl-gcc -Wall main.c src/* -o wtimewakeup

#using gcc compiler
gcc -Wall src/*.c -o wtimewakeup
