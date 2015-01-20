debug_path: DEBUG= -g -D DEBUG
release: DEBUG=

debug_path: clean all
release: clean all

LINK= -lSDL2 -lGL -lGLU
BUILD= main.o render.o debug.o engine.o mesh.o entity.o
REQ= main.o render.o debug.o engine.o mesh.o entity.o
CC= gcc 

all: $(REQ)
	$(CC) $(LINK) $(BUILD)

main.o: main.c
	$(CC) -c main.c $(DEBUG)

render.o: render.c
	$(CC) -c render.c $(DEBUG)

debug.o: debug.c
	$(CC) -c debug.c $(DEBUG)

engine.o: engine.c
	$(CC) -c engine.c $(DEBUG)

mesh.o: mesh.c
	$(CC) -c mesh.c $(DEBUG)

entity.o: entity.c
	$(CC) -c entity.c $(DEBUG)

clean:
	rm -f a.out *.o
