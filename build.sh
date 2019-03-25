#using tcc compiler
#tcc src/*.c -o wtimewakeup

#using musl wrapper to gcc
#musl-gcc -Wall src/*.c -o wtimewakeup

#using gcc compiler
gcc -Wall src/*.c -o wtimewakeup
