NAME = single_perceptron
SRC = single_input_perceptron.c
CC = gcc -std=c11
CFLAG = -Wall -Wextra 

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) 	

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all, clean, re