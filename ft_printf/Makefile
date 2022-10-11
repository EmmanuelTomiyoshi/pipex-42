NAME 		=	libftprintf.a
CFLAGS 		=	-Wall -Wextra -Werror
CC 			=	cc
RM			=	rm -fr

LIB 		=	ar -rcs

INC_DIR		=	./include/
INC_FLAG    =	-I $(INC_DIR) -g
INC			=	$(INC_DIR)ft_printf.h

SRC_DIR 	=	./src/
OBJ_DIR		=	./obj/

SRC_FILES 	=	ft_printf.c ft_is_character.c ft_uns_itoa.c \
				condition_c.c condition_di.c condition_p.c \
				condition_s.c condition_u.c condition_x.c \
				ft_itoa.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

COLOR_WHITE		= \e[00m
COLOR_GREEN		= \e[32m
COLOR_RED		= \e[91m
COLOR_BLUE		= \e[34m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

obj/%.o: src/%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

$(NAME): $(OBJ) $(INC)
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(NAME)"
	@$(LIB) $(NAME) $(INC) $(OBJ)
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
