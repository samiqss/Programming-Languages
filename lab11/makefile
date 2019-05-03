CC=g++
Flags=-Wall -Wextra

lab11x:	lab11.o pool.o pool.h
	${CC} ${Flags} lab11.o pool.o -o lab11x

lab11.o:	lab11.cpp pool.h
	${CC} ${Flags} -c lab11.cpp

pool.o:	pool.cpp pool.h
	${CC} ${Flags} -c pool.cpp

clean:
	rm -f pool.o lab11.o

