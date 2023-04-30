CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format
RM = rm -rf
BETTY = betty
SRC = 	0-print_list.c 1-list_len.c 3-add_node_end.c executor.c \
	simple_shell.c tokenizer.c utils.c printenvironment.c
TARGET = hsh



all:
	$(BETTY) $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

dev:
	$(CC) $(SRC) -o $(TARGET)
clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all
