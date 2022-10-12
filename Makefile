NAME = pipex

LIBFT        = libft/libft.a
LIBFTDIR     = libft/
LIBPRINTFDIR = ft_printf/
FT_PRINTF    = ft_printf/libftprintf.a
FT_PRINTFDIR = ft_printf/include

SRCDIR  = src/
OBJDIR  = obj/
INCDIR  = include/

LIBFLAGS = -lft
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -I ${FT_PRINTFDIR} -I ${LIBFTDIR} -I ${INCDIR}
LIBFLAGS = -lft -lftprintf
CC = cc

FILES   =	pipex.c pathname.c init_data.c handle_error.c child_process.c \
			close_pipes.c init_cmd_data.c init_pipe_data.c \
			free_memory.c forking.c wait_status.c

SRC = ${addprefix ${SRCDIR}, ${FILES}}
OBJ = ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

COLOR_WHITE		= \e[00m
COLOR_GREEN		= \e[32m
COLOR_RED		= \e[91m
COLOR_BLUE		= \e[34m

all: ${NAME}

${OBJDIR}:
	@mkdir -p ${OBJDIR}

${OBJDIR}%.o: ${SRCDIR}%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${FT_PRINTF} ${LIBFT} ${OBJDIR} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${NAME}
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

${LIBFT}:
	make -C ${LIBFTDIR}

${FT_PRINTF}:
	make -C ${LIBPRINTFDIR}

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@rm -rf ${OBJDIR}
	cd $(LIBPRINTFDIR) && make clean
	cd $(LIBFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	rm -rf ${NAME}
	rm -rf ${FT_PRINTF}
	rm -rf ${LIBFT}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

leaks: ${NAME}
	@clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--trace-children=yes ./pipex file1 "cat" "cat" file2

.PHONY: re fclean clean all norm