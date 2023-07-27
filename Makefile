
NAME		= fractol
HEADER		= include/fractol.h

INCLUDE		= -I./ -I libft -I mlx

OBJ_DIR		= obj/

CC			= gcc -g -fsanitize=address
CFLAGS		= -Wall -Werror -Wextra

SRCS		= main.c mlx_needs.c fract_needs.c fractals.c complex.c
OBJS		= $(addprefix ${OBJ_DIR}/,$(SRCS:.c=.o))
DEPS		= $(addsuffix .d,$(basename ${OBJS}))
RUTAS		= libft/libft.a mlx/libmlx.a

######## COLORS #########
GREEN		= \033[1;92m
YELLOW 		= \033[1;93m
RED			= \033[1;91m
NC			= \033[0m

${OBJ_DIR}/%.o: %.c Makefile
				@echo "$(YELLOW)creating.. $(NC)"
				@echo "$(YELLOW)compiling.. $(notdir $<)$(NC)"
				@mkdir -p ${OBJ_DIR}
				@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:
				@${MAKE} -sC libft
				@${MAKE} -sC mlx
				@${MAKE} ${NAME}

${NAME}: ${OBJS} 
				${CC} ${CFLAGS} ${OBJS} ${RUTAS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
				@echo "$(GREEN)fract-ol compiled$(NC)"


-include ${DEPS}

clean:
				@${MAKE} clean -sC libft
				@${MAKE} clean -sC mlx
				rm -rf ${OBJ_DIR}
				@echo "$(RED)\nDestruction successful\n$(NC)"

fclean: clean
				@${MAKE} fclean -sC libft
				rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re