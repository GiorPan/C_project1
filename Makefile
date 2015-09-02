all : main.o MD5.o tree.o
	gcc -o filesync ask.o MD5.o tree.o

main.o : main.c tree.h MD5.h
	gcc -c main.c
MD5.o : MD5.c MD5.h
	gcc -c MD5.c
tree.o : tree.c tree.h MD5.h
	gcc -c tree.c
clean :
	rm -rf filesync main.o MD5.o tree.o
