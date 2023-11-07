NAME = gates
SRC = gates.c
CC = gcc -std=c11
CFLAG = -Wall -Wextra 

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) 	

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all, clean, re