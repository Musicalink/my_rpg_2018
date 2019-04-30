##
## EPITECH PROJECT, 2019
## Makfile
## File description:
## rpg
##

SRC     =       src/main.c		\
		src/menu.c		\
		src/set_menu.c		\
		src/battle.c		\
		src/set_battle.c	\
		src/set_player_battle.c	\
		src/set_player.c	\
		src/hud_ingame.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_rpg

CFLAGS  =       -Iinclude

SFFLAGS =       -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFFLAGS) -g $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:  fclean all
