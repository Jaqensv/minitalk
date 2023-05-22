CLIENT		= client

SERVER		= server

SRC_CLIENT	= client.c \
		inc_libft/ft_atoi.c

SRC_SERVER	= server.c \
		inc_printf/ft_printf.c \
		inc_printf/toolbox.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

CC		= gcc

CFLAGS		+= -Wall -Wextra -I./include/

RM		= rm -f

all:		$(CLIENT) $(SERVER)

$(SERVER):	$(OBJ_SERVER)
		$(CC) -o $(SERVER) $(OBJ_SERVER)

$(CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(CLIENT) $(OBJ_CLIENT)

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:		clean
		$(RM) $(SERVER) $(CLIENT)

re:		fclean all