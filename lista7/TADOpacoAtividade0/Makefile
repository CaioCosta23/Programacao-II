CC = gcc
CFLAGS = -lm
DEPS = Respostas/Caio/ponto.h Respostas/Caio/circulo.h
OBJ = build/ponto.o build/circulo.o build/main.o

build/%.o: Respostas/Caio/%.c $(DEPS)
	$(CC) - c -o $@ $< $(CFLAGS)

build/prog: $(OBJ)
	$(CC) - o $@ $^ $(CFLAGS)
	echo "Compilado!"

run:
	./build/prog

clean:
	rm -rf build/*.o build/prog