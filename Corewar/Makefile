##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/main.c \
	./src/op.c \
	./src/corewar.c \
	./src/init_champs.c \
	./src/get_instructions.c \
	./src/get_params.c \
	./src/load_champs.c \
	./src/dump_memory.c \
	./src/init_corewar.c \
	./src/get_in_memory.c \
	./src/put_value.c \
	./src/instructions/live.c \
	./src/instructions/ld.c \
	./src/instructions/st.c \
	./src/instructions/add.c \
	./src/instructions/sub.c \
	./src/instructions/and.c \
	./src/instructions/or.c \
	./src/instructions/xor.c \
	./src/instructions/zjmp.c \
	./src/instructions/ldi.c \
	./src/instructions/sti.c \
	./src/instructions/fork.c \
	./src/instructions/lld.c \
	./src/instructions/lldi.c \
	./src/instructions/lfork.c \
	./src/instructions/aff.c \
	./src/instructions/make_instruction.c \

OBJ = $(SRC:.c=.o)

NAME = corewar

CFLAGS = -W -Wall -Wextra  -Wno-deprecated-declarations

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
	$(CC) -g $(SRC) $(LIB) $(NAMELIB) $(CPPFLAGS)

.PHONY: all clean debug fclean re compile tests
