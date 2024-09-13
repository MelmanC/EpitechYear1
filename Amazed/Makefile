##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/main.c \
    ./src/amazed.c \
    ./src/open_file.c \
    ./src/parser.c \
    ./src/remove_comment.c \
    ./src/display.c \
    ./src/set_matrix.c \
    ./src/robot_parser.c \
    ./src/rooms_parser.c \
	./src/algorithm_dfs.c	\
	./src/clear_path.c	\
	./src/set_path_inf.c	\
	./src/display_moove.c	\

OBJ = $(SRC:.c=.o)

SRC_T = ./src/amazed.c \
    ./src/open_file.c \
    ./src/parser.c \
    ./src/remove_comment.c \
    ./src/display.c \
    ./src/set_matrix.c \
    ./src/robot_parser.c \
    ./src/rooms_parser.c \
	./src/algorithm_dfs.c	\
	./src/clear_path.c	\
	./src/set_path_inf.c	\
	./src/display_moove.c	\

NAME = amazed

CFLAGS = -W -Wall -Wextra -Wno-deprecated-declarations

CPPFLAGS = -I./include

CRITF = --coverage -lcriterion

CC = gcc

DIRLIB = lib/my/

DIRT = tests/test_display.c \
	tests/test_error.c \

LIB = -L./lib/my

NAMELIB = -lmy

all: compile $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(NAMELIB) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	find . -name "vgcore" -delete
	find . -name "*coding-style*" -delete
	rm -f vgcore*
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	make clean -C $(DIRLIB)

re: fclean compile all

compile:
	make -C $(DIRLIB)

unit_tests: compile
	gcc -o unit_tests $(SRC_T) $(DIRT) $(LIB) $(NAMELIB) $(CPPFLAGS) $(CRITF)

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

debug: all
	$(CC) -g $(SRC) $(LIB) $(NAMELIB) $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean debug fclean re compile unit_tests tests_run
