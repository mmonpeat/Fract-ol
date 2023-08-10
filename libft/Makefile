NAME	= libft.a

BONUS_NAME = .bonus

HEADER	= libft.h

INCLUDE = -I./

SRCS	= ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c \
		ft_memcmp.c  ft_strnstr.c \
		ft_atoi.c \
		ft_strdup.c ft_calloc.c \
		ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strmapi.c \
		ft_striteri.c ft_itoa.c \
		ft_strjoin.c ft_strtrim.c \
		ft_split.c \

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${BONUS:.c=.o}

DEPS 	= $(addsuffix .d, $(basename ${OBJS}))

DEPS_BONUS 	= $(addsuffix .d, $(basename ${OBJS_BONUS}))

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o : %.c Makefile
	${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
	ar src ${NAME} ${OBJS}

-include	${DEPS}

bonus:	${BONUS_NAME}
   
${BONUS_NAME}: ${OBJS} ${OBJS_BONUS}
	ar src ${NAME} ${OBJS} ${OBJS_BONUS}
	touch $@

-include	${DEPS_BONUS}

clean:
			rm -rf ${OBJS} ${DEPS} ${OBJS_BONUS} ${DEPS_BONUS}

fclean:		clean
			rm -rf ${NAME} ${BONUS_NAME}

re:			fclean all

.PHONY:		all clean fclean re
