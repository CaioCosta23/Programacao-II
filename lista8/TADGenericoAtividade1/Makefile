CC = gcc
CFLAGS = -lm
DEPS = Respostas/Caio/tadgen.h
OBJ = build/tadgen.o build/main.o

build/%.o: Respostas/Caio/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build/prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

run:
	./build/prog

clean:
	rm -rf build/*.o build/prog