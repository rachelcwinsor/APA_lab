'CC = gcc
CFLAGS = -lm -lpthread -fopenmp

all: 
	${CC} secuential.c -o  secuential ${CFLAGS}
	${CC} posixPI.c -o  posixPI ${CFLAGS}
	${CC} mpPI.c -o  mpPI ${CFLAGS}
clean:
	rm -f lib secuential
	rm -f lib posixPI
	rm -f lib mpPI

