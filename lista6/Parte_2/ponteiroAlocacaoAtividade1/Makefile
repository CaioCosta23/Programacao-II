all: geraos mov geraexe

geraos: Respostas/Caio/tabuleiro.c Respostas/Caio/jogador.c Respostas/Caio/jogada.c Respostas/Caio/jogo.c Respostas/Caio/main.c
	gcc -c Respostas/Caio/tabuleiro.c Respostas/Caio/jogador.c Respostas/Caio/jogada.c Respostas/Caio/jogo.c Respostas/Caio/main.c

mov: geraos
	mv *.o build

geraexe: build/tabuleiro.o build/jogador.o build/jogada.o build/jogo.o build/main.o
	gcc build/tabuleiro.o build/jogador.o build/jogada.o build/jogo.o build/main.o -o prog

clean:
	rm -rf build/*.o