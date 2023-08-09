CFLAGS = -g -Wall -Wextra -Werror

all : my_mastermind

my_mastermind : my_mastermind.o
	gcc $(CFLAGS) -o my_mastermind my_mastermind.o

my_mastermind.o : my_mastermind.c
	gcc -o my_mastermind.o -c my_mastermind.c

clean:
	rm -f *.o

fclean: clean
	rm -f my_mastermind

re: fclean all