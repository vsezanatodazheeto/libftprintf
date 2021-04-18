.PHONY: all clean fclean re

#-------------------------------------------------------------------------------
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
#-------------------------------------------------------------------------------
DH = include/
H = ft_printf.h
H := $(addprefix $(DH), $(H))
#-------------------------------------------------------------------------------
DSRC = src/
SRC = \
	printf \
	parse \
	buffer \
	buffer_number \
	extra
SRC := $(addprefix $(DSRC), $(addsuffix .c, $(SRC)))
#-------------------------------------------------------------------------------
DOBJ = obj/
OBJ = $(patsubst $(DSRC)%, $(DOBJ)%, $(SRC))
OBJ := $(patsubst %.c, %.o, $(OBJ))
#-------------------------------------------------------------------------------
all:
	@$(MAKE) -s $(NAME)

$(NAME): $(DOBJ) $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo "--------------------------------"
	@echo "$(NAME) compiled"
	@echo "--------------------------------"

$(DOBJ):
	@mkdir -p $(DOBJ)

$(DOBJ)%.o: $(DSRC)%.c $(H) Makefile
	@echo $<
	@$(CC) $(CFLAGS) \
	-D BUF_SIZE=100 \
	-I$(DH) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

# @$(CC) $(CFLAGS) -I$(DH) -D BUF_SIZE -c $< -o $@
