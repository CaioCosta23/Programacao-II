all: geraos geraexe

geraos: tabuleiro.c jogador.c jogada.c jogo.c main.c
	gcc -c Respostas/Caio/tabuleiro.c Respostas/Caio/jogador.c Respostas/Caio/jogada.c Respostas/Caio/jogo.c Respostas/Caio/main.c

mov:
	mv Respostas/Caio/*.o ../../build

geraexe: tabuleiro.c jogador.c jogada.c jogo.c main.c
	gcc build/tabuleiro.o build/jogador.o build/jogada.o build/jogo.o build/main.o -o prog

clean:
	rm -rf build/*.o