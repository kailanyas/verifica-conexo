all: compila executa clean
compila: main.o matriz.o 
	gcc main.o matriz.o -o trabalho
main.o: main.c
	gcc -c main.c
matriz.o: matriz.c
	gcc -c matriz.c
executa:
	./trabalho $(arquivo)
clean:
	rm main.o matriz.o


