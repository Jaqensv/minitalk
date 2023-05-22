NAME = libftprintf.a

SOURCES = ft_printf.c toolbox.c \

OBJECTS = $(SOURCES:.c=.o)

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(SOURCES)
		ar rc $(NAME) $(OBJECTS)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
