PROGS:=calc

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o

calc: calc.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -save-temps -o $@ $^
