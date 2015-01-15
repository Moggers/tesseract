debug_path: DEBUG= -g -D DEBUG
release: DEBUG=

debug_path: clean all
release: clean all

LINK= -lSDL2 -lGL -lGLU
BUILD= main.o render.o debug.o engine.o
REQ= main.o render.o debug.o engine.o

all: $(REQ)
	gcc $(LINK) $(BUILD)

main.o: main.c
	gcc -c main.c $(DEBUG)

render.o: render.c
	gcc -c render.c $(DEBUG)

debug.o: debug.c
	gcc -c debug.c $(DEBUG)

engine.o: engine.c
	gcc -c engine.c $(DEBUG)

clean:
	rm -f a.out *.o
