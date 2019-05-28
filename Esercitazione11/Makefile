CC=g++
CFLAGS=-w -I.
DEPS=esercizio.h soluzione.h albero_binario.h insieme.h lista.h
OBJS=test_esercizio.o esercizio.o soluzione.o albero_binario.o insieme.o lista.o
TGT=test_esercizio

all: $(TGT)

%.o:	%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TGT):	$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY:	clean

clean:
	rm -rf *.o *~ $(TGT)
