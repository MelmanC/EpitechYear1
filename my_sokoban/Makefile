##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/sokoban.c \
	./src/open_map.c \
	./src/play.c \
	./src/get.c \
	./src/keys/down.c \
	./src/keys/up.c \
	./src/keys/left.c \
	./src/keys/right.c \
	./src/count.c \
	./src/verifie.c

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

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
	$(CC) -lncurses -o $(NAME) $(OBJ) $(LIB) $(NAMELIB)

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	make clean -C $(DIRLIB)

re: fclean compile all

compile:
	make -C $(DIRLIB)

tests: all
	gcc -o unit $(SRC) $(DIRT) $(CFLAGS) $(CPPFLAGS) $(CRITF)

debug: all
	$(CC) -lncurses -g $(SRC) $(LIB) $(NAMELIB)

.PHONY: all clean debug fclean re compile tests
