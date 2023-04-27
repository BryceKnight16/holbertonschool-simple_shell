CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

RM = rm -rf

BETTY = betty $(SRC)

SRC = *.c

NAME = shell



all:	1

1:
	$(BETTY)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)


clean:
	$(RM) *~ \#*\# \.\#* \
        $(NAME)

re: clean all
