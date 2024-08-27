allset : myset.o set.o
	gcc -ansi -pedantic -Wall -g myset.o set.o -o myset
myset.o :myset.c set.h
	gcc -c -ansi -pedantic -Wall myset.c -o myset.o	
set.o: set.c set.h
	gcc -c -ansi -pedantic -Wall set.c -o set.o		



