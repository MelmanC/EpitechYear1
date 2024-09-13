##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiling makefile
##

TESTS_SRC	=	tests/basic.c \

NAME		=	my_navy

CFLAGS		=	-Wall -Wextra -W -g3

ARGS	=	map

all: $(NAME)

$(NAME): cmake clean
		@rm -rf *.dSYM/
		@echo -e ${GRN}[OK] Files Compiled${RESET}
		@echo

cmake:
		@cmake -B build
		@cmake --build build
		@mv build/my_navy .

unit_tests: fclean
		@$(CC) -o unit_tests src/main.c $(LIB) $(TESTS_SRC)	\
		--coverage -lcriterion -g3

tests_run: unit_tests
		@echo
		@echo
		@echo
		@echo =============================== DETAILED TESTS	\
			  ===============================
		@-./unit_tests --verbose
		@echo
		@echo
		@echo
		@echo ================================== COVERAGE	\
			  =================================
		@gcovr --exclude tests/
		@gcovr --exclude tests/ --branches
		@echo
		@echo
		@echo
		@echo ================================ FAILED TESTS	\
			  ===============================
		@-./unit_tests
		@$(MAKE) fclean

clean:
		@rm -rf *.o
		@rm -rf *.dSYM/
		@rm -rf *.gcda
		@rm -rf *.gcno
		@make --no-print-directory -C ./lib/my/ clean

fclean: clean
		@rm -rf $(NAME)
		@rm -rf unit_tests
		@rm -rf build/
		@make --no-print-directory -C ./lib/my/ fclean

re: fclean all

.PHONY: all cmake unit_tests tests_run clean fclean re

BLD	=		"\x1B[1m"
DRK	=		"\x1B[2m"
ITL	=		"\x1B[3m"
UDL	=		"\x1B[4m"

GRN	=		"\x1B[32m"
CYN	=		"\x1B[36m"
BLU	=		"\x1B[34m"
MAG	=		"\x1B[35m"
YEL	=		"\x1B[33m"
RED	=		"\x1B[31m"
WHT	=		"\x1B[37m"
RESET	=	"\x1B[0m"
.PHONY: BLD DRK ITL UDL GRN CYN BLU MAG YEL RED WHT RESET
