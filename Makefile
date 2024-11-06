NAME	:= 	fractol

DIR		:=	srcs/src/

SRCS	:= 	main.c \
			parse.c

OBJS	:=	$(patsubst %.c, $(DIR)%.o, $(SRCS))

CC		:= cc

LIBS	:= srcs/MacroLibX/libmlx.so

FLAGS 	:= -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS} ${LIBS}
	${CC} -o ${NAME} ${OBJS} ${LIBS} -lSDL2

${DIR}%.o: ${DIR}%.c
	${CC} ${FLAGS} -o $@ -c $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all
