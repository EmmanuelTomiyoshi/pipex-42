NAME = pipex

LIBFT = libft/libft.a
LIBFTDIR = libft/
LIBPRINTFDIR = ft_printf/
FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTFDIR = ft_printf/include

SRCDIR = src/
OBJDIR = obj/
INCDIR = include/

LIBFLAGS = -lft
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -I ${FT_PRINTFDIR} -I ${LIBFTDIR} -I ${INCDIR}
LIBFLAGS = -lft -lftprintf
CC = cc

FILES = pipex.c pathname.c init_data.c handle_error.c keep_track_of_the_code.c
SRC = ${addprefix ${SRCDIR}, ${FILES}}
OBJ = ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

all: ${NAME}

${OBJDIR}:
	@mkdir -p ${OBJDIR}

${OBJDIR}%.o: ${SRCDIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${FT_PRINTF} ${LIBFT} ${OBJDIR} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${NAME}

${LIBFT}:
	make -C ${LIBFTDIR}

${FT_PRINTF}:
	make -C ${LIBPRINTFDIR}

clean:
	rm -rf ${OBJDIR}
	cd $(LIBPRINTFDIR) && make clean
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf ${NAME}
	rm -rf ${FT_PRINTF}
	rm -rf ${LIBFT}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

test: ${NAME}
	./pipex file1 "ls -la" "wc -l" file2

.PHONY: re fclean clean all norm