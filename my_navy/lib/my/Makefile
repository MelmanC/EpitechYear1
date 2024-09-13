##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Lib builder makefile
##

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../
		@echo -e ${GRN}[OK] "Library successfully compiled"${RESET}

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

GRN	=		"\x1B[32m"
RESET	=	"\x1B[0m"
.PHONY: GRN RESET
