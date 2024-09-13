##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/main.c \
	./src/op.c \
	./src/usage.c \
	./src/read_file.c \
	./src/store_header.c \
	./src/write_in_file.c \
	./src/to_binary.c \
	./src/utils.c \
	./src/check_file.c \
	./src/check_label.c \
	./src/get_type.c \
	./src/utils_2.c \
	./src/check_nbr_args.c \
	./src/last_check.c \

OBJ = $(SRC:.c=.o)

NAME = asm

CFLAGS = -W -Wall -Wextra

CPPFLAGS = -I./include/

CRITF = --coverage -lcriterion

CC = gcc

DIRLIB = lib/my/

DIRT = tests/test_criterion.c

LIB = -L./lib/my/

NAMELIB = -lmy

all: compile $(NAME) clean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(NAMELIB)

clean:
	find . -name "*~" -delete
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	make clean -C $(DIRLIB)

re: fclean compile all

compile:
	make -C $(DIRLIB)

tests: all
	gcc -o unit $(SRC) $(DIRT) $(CFLAGS) $(CPPFLAGS) $(CRITF)

debug: all
	$(CC) -g $(SRC) $(LIB) $(NAMELIB) $(NAMESHELL)

.PHONY: all clean debug fclean re compile tests
