##
## EPITECH PROJECT, 2019
## Makfile
## File description:
## rpg
##

SRC     =       src/main.c		\
		src/menu.c		\
		src/set/set_menu.c	\
		src/battle.c		\
		src/set/set_battle.c	\
		src/set/set_player_battle.c	\
		src/set/set_pause_menu.c	\
		src/set/set_player.c	\
		src/hud_ingame.c	\
		src/set/ennemies.c	\
		src/battle_action.c	\
		src/battle_movement.c	\
		src/battle_end.c	\
		src/set/set_lootscreen.c	\
		src/battle_loots.c	\
		src/set/set_textloot.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_rpg

CFLAGS  =       -Iinclude

SFFLAGS =       -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -Llib/my -lmy -W -Wall -Wextra

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(SFFLAGS) -g $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:  fclean all
