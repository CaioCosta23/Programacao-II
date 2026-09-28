CC = gcc
CFLAGS = -lm
DEPS = Respostas/Caio/pacote.h build/gerenciadorpacotes.h
OBJ = build/pacote.o build/gerenciadorpacotes.o build/main.o

build/%.o: Respostas/Caio/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build/prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

run:
	./build/prog

clean:
	rm -rf build/*.o build/prog