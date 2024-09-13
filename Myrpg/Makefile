##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiling makefile
##

SRC			=	src/main.c	\
				src/init.c	\
				src/init_enemy.c \
				src/racoon.c \
				src/frog.c \
				src/utils.c	\
				src/rpg.c	\
				src/event.c \
				src/map.c \
				src/player.c \
				src/attack.c \
				src/clock.c	\
				src/weapon.c \
				src/save.c \
				src/oldman.c \
				src/dialog.c \
				src/enemy.c \
        		src/init_quest.c \
          		src/life.c \
          		src/dead_anime.c \
            	src/init_map.c \
             	src/inventory.c \
              	src/update_view.c \
               	src/pause.c \
                src/tuto.c \
             	src/menu/bear.c	\
				src/menu/parallax.c	\
				src/menu/gameboy.c	\
				src/menu/init_menu.c	\
				src/menu/particle.c	\
				src/menu/draw_menu.c \
				src/menu/sound.c \
				src/menu/play_game_btn.c \
				src/menu/buttons_bg.c \
				src/menu/options_bg.c \
				src/menu/close_cross.c \
				src/menu/options_btn.c \
				src/menu/exit_btn.c \
				src/menu/load_btn.c \
				src/menu/start_btn.c \
				src/menu/handle_events.c \
				src/menu/volume_btn.c \
				src/menu/volume_up_btn.c \
				src/menu/volume_down_btn.c \
				src/menu/keybinds.c \
				src/menu/keybinds_input.c \

NAME		=	my_rpg

CFLAGS		=	-Wall -Wextra -g3

CSFML_FLAGS	=	-lcsfml-system	\
				-lcsfml-window	\
				-lcsfml-graphics	\
				-lcsfml-audio	\
				-lcsfml-network	\
				-Wno-deprecated-declarations	\

LIB		=	-I./include -L./lib/my/ -lmy

MFLAGS = -I/opt/homebrew/Cellar/csfml/2.6.0/include

MLFLAGS = -L/opt/homebrew/Cellar/csfml/2.6.0/lib

all: $(NAME)

$(NAME): libmy.a
		@gcc -o $(NAME) $(SRC) $(LIB) -lm $(CFLAGS) $(CSFML_FLAGS)
		@rm -rf *.dSYM/
		@echo ${GRN}[OK] Files Compiled${RESET}
		@echo

libmy.a:
		make --no-print-directory -C ./lib/my

mac: libmy.a clean
		@gcc -o $(NAME) $(SRC) $(LIB) $(MFLAGS) $(MLFLAGS) $(CSFML_FLAGS)
		@rm -rf *.dSYM/
		@echo ${GRN}[OK] Files Compiled${RESET}
		@echo

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

.PHONY: all cmake unit_tests tests_run clean fclean re mac

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
