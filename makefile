CC=gcc
CFLAGS=-g -Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
# OBJS = obj/main.o obj/test.o
BINDIR=bin
BIN = $(BINDIR)/PasswordManager

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*