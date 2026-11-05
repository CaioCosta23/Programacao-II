all: geraos mov geraexe

geraos: Respostas/Caio/aluno.c Respostas/Caio/main.c
	gcc -c Respostas/Caio/aluno.c Respostas/Caio/main.c

mov: geraos
	mv *.o build

geraexe: build/aluno.o build/main.o
	gcc build/aluno.o build/main.o -o build/prog

clean:
	rm -rf build/*.o prog