a.out: main.o mat.o gauss.o
	cc -Wall --pedantic main.o mat.o gauss.o

main.o: main.c mat.h
	cc -c -Wall --pedantic main.c

mat.o: mat.c mat.h
	cc -c -Wall --pedantic mat.c

gauss.o: gauss.c gauss.h
	cc -c -Wall --pedantic gauss.c
