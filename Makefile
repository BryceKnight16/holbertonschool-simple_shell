CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format
RM = rm -rf
BETTY = betty
SRC = *.c
TARGET = shell



all:
	$(BETTY) $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

dev:
	$(CC) $(SRC) -o $(TARGET)
clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all
