.PHONY: clean fclean re

#-------------------------------------------------------------------------------
NAME = libft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

#-------------------------------------------------------------------------------
DH = include/
H = ft_printf.h
H := $(addprefix $(DH), $(H))

#-------------------------------------------------------------------------------
DSRC = src/
SRC = printf.c parse.c buffer.c buffer_number.c extra.c
SRC := $(addprefix $(DSRC), $(SRC))

#-------------------------------------------------------------------------------
DOBJ = obj/
OBJ := $(patsubst $(DSRC)%.c, $(DOBJ)%.o, $(SRC))

#-------------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(DOBJ) $(OBJ) Makefile
	@ar -rc $(NAME) $(OBJ)
	@echo "--------------------------------------"
	@echo "$(NAME) compiled"
	@echo "--------------------------------------"

$(DOBJ):
	@mkdir -p $(DOBJ)

$(DOBJ)%.o: $(DSRC)%.c $(H)
	@echo $<
	@$(CC) $(CFLAGS) -D BUF_SIZE=100 -I$(DH) -c $< -o $@

clean:
	@rm -rf $(DOBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

