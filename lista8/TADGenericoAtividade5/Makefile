CC = gcc
CFLAGS = -lm
DEPS = Respostas/Caio/tarefasoma.h Respostas/Caio/tarefamultiplica.h Respostas/Caio/tarefaimprime.h Respostas/Caio/agendatarefas.h
OBJ = build/tarefasoma.o build/tarefamultiplica.o build/tarefaimprime.o build/agendatarefas.o build/main.o

build/%.o: Respostas/Caio/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build/prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "Compilado!"

run:
	./build/prog

clean:
	rm -rf build/*.o build/prog