all: geraos mov geraexe

geraos: Respostas/Caio/eleitor.c Respostas/Caio/candidato.c Respostas/Caio/eleicao.c Respostas/Caio/main.c
	gcc -c Respostas/Caio/eleitor.c Respostas/Caio/candidato.c Respostas/Caio/eleicao.c Respostas/Caio/main.c

mov: geraos
	mv *.o build

geraexe: build/eleitor.o build/candidato.o build/eleicao.o build/main.o
	gcc build/eleitor.o build/candidato.o build/eleicao.o build/main.o -o build/prog

clean:
	rm -rf build/*.o prog