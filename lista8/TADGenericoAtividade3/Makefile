CC = gcc
CFLAGS = -lm
DEPS = Respostas/Caio/vector.h Respostas/Caio/aluno.h Respostas/Caio/relatorio.h
OBJ = build/vector.o build/aluno.o build/relatorio.o build/main.o

build/%.o: Respostas/Caio/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build/prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

run:
	./build/prog

clean:
	rm -rf build/*.o build/prog