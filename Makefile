NAME = pipex

LIBFT = libft/libft.a
LIBFTDIR = libft/

SRCDIR = src/
OBJDIR = obj/
INCDIR = include/

LIBFLAGS = -lft
CFLAGS += -g -I ${LIBFTDIR} -I ${INCDIR}
CC = cc

FILES = pipex.c pathname.c init_data.c
SRC = ${addprefix ${SRCDIR}, ${FILES}}
OBJ = ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

all: ${NAME}

${OBJDIR}:
	@mkdir -p ${OBJDIR}

${OBJDIR}%.o: ${SRCDIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${OBJDIR} ${OBJ}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L ${LIBFTDIR} \
	${LIBFLAGS}

${LIBFT}:
	make -C ${LIBFTDIR}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: re fclean clean all norm