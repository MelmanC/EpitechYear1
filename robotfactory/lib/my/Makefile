##
## EPITECH PROJECT, 2023
## Make
## File description:
## make
##

SRC = my_compute_power_rec.c    \
        my_compute_square_root.c        \
        my_find_prime_sup.c     \
        my_getnbr.c     \
        my_is_prime.c   \
        my_isneg.c      \
        my_put_nbr.c    \
        my_put_nbrus.c \
        my_putchar.c    \
        my_putstr.c     \
        my_revstr.c     \
        my_showmem.c    \
        my_showstr.c    \
        my_sort_int_array.c     \
        my_str_isalpha.c        \
        my_str_islower.c        \
        my_str_isnum.c  \
        my_str_isprintable.c    \
        my_str_isupper.c        \
        my_strcapitalize.c       \
        my_str_to_word_array.c \
        my_strcat.c     \
        my_strcmp.c     \
        my_strcpy.c     \
        my_strlen.c     \
        my_strlentab.c \
        my_strlowcase.c \
        my_strncat.c    \
        my_strncmp.c    \
        my_strncpy.c    \
        my_strstr.c     \
        my_strdup.c \
        my_strupcase.c  \
        my_swap.c       \
        my_printf.c \
	functions.c \
	functions_d.c \
	functions_float.c \
	functions_length.c \
	functions_o.c \
	functions_u.c \
	functions_x.c \
	functions_xmaj.c \
        my_put_hexa.c \
 	my_put_hexa_maj.c \
	my_put_octa.c \
	my_put_ptr.c \
	my_put_float.c \
	my_put_scient.c

OBJ = $(SRC:.c=.o)

NAME = libmy

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a *.o
	cp include/my.h ../../include/
	cp include/printf.h ../../include/
	rm -f *~

clean:
	rm -f $(OBJ)
	rm -r $(NAME).a

.PHONKY: all clean
