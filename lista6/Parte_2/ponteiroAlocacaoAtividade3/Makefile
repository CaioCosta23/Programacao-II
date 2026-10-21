all: geraos mov geraexe

geraos: Respostas/Caio/filme.c Respostas/Caio/locadora.c Respostas/Caio/main.c
	gcc -c Respostas/Caio/filme.c Respostas/Caio/locadora.c Respostas/Caio/main.c

mov: geraos
	mv *.o build

geraexe: build/filme.o build/locadora.o build/main.o
	gcc build/filme.o build/locadora.o build/main.o -o build/prog

clean:
	rm -rf build/*.o prog