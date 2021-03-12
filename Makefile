CFLAGS = -I. -Wall -pedantic
DEPS = list.h
OBJ = list_example.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

list_example: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) list_example

check: list_example
	./list_example
