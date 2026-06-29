CFLAGS = -Wall
CC = gcc
# LDFLAGS = -lm (poderia ser necess´aria em outro projeto que utilizasse a math.h)

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) # realiza substitui¸c~ao dos nomes .c para os .o


main: $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm main $(OBJ)