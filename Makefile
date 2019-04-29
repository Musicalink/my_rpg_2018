##
## EPITECH PROJECT, 2019
## Makfile
## File description:
## rpg
##

SRC     =       src/main.c		\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_rpg

CFLAGS  =       -Iinclude

SFFLAGS =       -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -Llib/my -lmy

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFFLAGS) -g $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:  fclean all
