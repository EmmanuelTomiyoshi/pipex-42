NAME 			= pipex

LIBFT        	= libft/libft.a
LIBFTDIR     	= libft/
LIBPRINTFDIR 	= ft_printf/
FT_PRINTF    	= ft_printf/libftprintf.a
FT_PRINTFDIR 	= ft_printf/include

SRCDIR  		= src/
OBJDIR  		= obj/
SRCDIR_B  		= src_bonus/
OBJDIR_B		= obj_bonus/
INCDIR  		= include/

BIN				= bin/pipex
BIN_B			= bin/pipex_bonus

REQUIRED_DIRS	= ${OBJDIR} ${OBJDIR_B} bin/

LIBFLAGS 		= -lft
CFLAGS 			= -Wall -Werror -Wextra
CFLAGS 			+= -g -I ${FT_PRINTFDIR} -I ${LIBFTDIR} -I ${INCDIR}
LIBFLAGS 		= -lft -lftprintf
CC 				= cc

FILES   		=	pipex.c pathname.c init_data.c handle_error.c		\
					child_process.c close_pipes.c init_cmd_data.c		\
					init_pipe_data.c free_memory.c forking.c			\
					wait_status.c

FILES_B			=	pipex_bonus.c pathname_bonus.c init_data_bonus.c	\
					handle_error_bonus.c child_process_bonus.c 			\
					close_pipes_bonus.c init_cmd_data_bonus.c 			\
					init_pipe_data_bonus.c free_memory_bonus.c			\
					forking_bonus.c wait_status_bonus.c

SRC 			= ${addprefix ${SRCDIR}, ${FILES}}
OBJ 			= ${addprefix ${OBJDIR}, ${FILES:.c=.o}}
SRC_B 			= ${addprefix ${SRCDIR_B}, ${FILES_B}}
OBJ_B 			= ${addprefix ${OBJDIR_B}, ${FILES_B:.c=.o}}

COLOR_WHITE		= \e[00m
COLOR_GREEN		= \e[32m
COLOR_RED		= \e[91m
COLOR_BLUE		= \e[34m

all: ${NAME}

bonus: ${BIN_B}

${REQUIRED_DIRS}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@${CC} ${CFLAGS} -c $< -o $@

${OBJDIR_B}%.o: ${SRCDIR_B}%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${FT_PRINTF} ${LIBFT} ${REQUIRED_DIRS} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${BIN}
	@cp ${BIN} ${NAME}
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

${BIN_B}: ${FT_PRINTF} ${LIBFT} ${REQUIRED_DIRS} ${OBJ_B}
	@${CC} ${CFLAGS} ${OBJ_B} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${BIN_B}
	@cp ${BIN_B} ${NAME}
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

${LIBFT}:
	make -C ${LIBFTDIR}

${FT_PRINTF}:
	make -C ${LIBPRINTFDIR}

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@rm -rf ${OBJDIR}
	@rm -rf ${OBJDIR_B}
	cd $(LIBPRINTFDIR) && make clean
	cd $(LIBFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	rm -rf ${NAME}
	rm -rf ${BIN}
	rm -rf ${BIN_B}
	rm -rf ${FT_PRINTF}
	rm -rf ${LIBFT}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: re fclean clean all norm