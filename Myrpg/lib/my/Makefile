##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Lib builder makefile
##

SRC		=	my_compute_power_rec.c	\
			my_compute_square_root.c	\
			my_find_prime_sup.c	\
			my_getnbr.c	\
			my_is_prime.c	\
			my_isneg.c	\
			my_nbrlen.c	\
			my_printf.c	\
			my_putchar.c	\
			my_putnbr.c	\
			my_puts.c	\
			my_putstr.c	\
			my_revstr.c	\
			my_show_word_array.c	\
			my_showmem.c	\
			my_showstr.c	\
			my_sort_int_array.c	\
			my_stderr.c	\
			my_str_isalpha.c	\
			my_str_islower.c	\
			my_str_isnum.c	\
			my_str_isprintable.c	\
			my_str_isupper.c	\
			my_str_to_word_array.c	\
			my_strcapitalize.c	\
			my_strcat.c	\
			my_strcmp.c	\
			my_strcpy.c	\
			my_strdup.c	\
			my_strlen.c	\
			my_strlowcase.c	\
			my_strncat.c	\
			my_strncmp.c	\
			my_strncpy.c	\
			my_strrchr.c	\
			my_strstr.c	\
			my_strupcase.c	\
			my_swap.c	\
			printf_lib/functions_ptr/rest_flags.c	\
			printf_lib/functions_ptr/rest_flags_2.c	\
			printf_lib/functions_ptr/simple_flags.c	\
			printf_lib/my_put_udecimal.c	\
			printf_lib/my_putfloat.c	\
			printf_lib/my_puthex.c	\
			printf_lib/my_puthex_capital.c	\
			printf_lib/my_putoctal.c	\
			printf_lib/my_putptr.c	\

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
