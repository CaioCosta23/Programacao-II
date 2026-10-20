CC = gcc
CFLAGS = -lm
DEPS = Respostas/Caio/vector.h Respostas/Caio/conta.h Respostas/Caio/agencia.h Respostas/Caio/banco.h
OBJ = build/vector.o build/conta.o build/agencia.o build/banco.o build/main.o

build/%.o: Respostas/Caio/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build/prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

run:
	./build/prog

clean:
	rm -rf build/*.o build/prog