find_determinant.out: matrix.o main.o
	gcc -g -Wall -Werror -o find_determinant.out matrix.o main.o -lm

main.o: main.c matrix.h
	gcc -g -Wall -Werror -c -o main.o main.c

matrix.o: matrix.c matrix.h
	gcc -g -Wall -Werror -c -o matrix.o matrix.c

clean:
	rm -f *.out *.o
