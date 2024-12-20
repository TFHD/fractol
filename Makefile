NAME	:= 	fractol

NAMEB	:= 	fractol_bonus

DIR		:=	srcs/src/

DIRB	:=	srcs/src_bonus/

SRCS	:= 	main.c \
			parse.c \
			utils.c \
			color.c \
			event.c \
			calculs.c
			
SRCSB	:= 	main_bonus.c \
			parse_bonus.c \
			utils_bonus.c \
			color_shift_bonus.c \
			event_zoom_bonus.c \
			calculs_bonus.c

OBJS	:=	$(patsubst %.c, $(DIR)%.o, $(SRCS))

OBJSB	:=	$(patsubst %.c, $(DIRB)%.o, $(SRCSB))

CC		:= cc

LIBS	:= srcs/MacroLibX/libmlx.so srcs/ft_printf/libftprintf.a

FLAGS 	:= -Wall -Werror -Wextra -I includes

all: ${NAME}

${NAME}: ${OBJS} ${LIBS}
	${CC} -o ${NAME} ${OBJS} ${LIBS} -lSDL2 -lm

bonus: ${NAMEB}

${NAMEB}: ${OBJSB} ${LIBS}
	${CC} -o ${NAMEB} ${OBJSB} ${LIBS} -lSDL2 -lm

${DIR}%.o: ${DIR}%.c
	${CC} ${FLAGS} -o $@ -c $<
	
${DIRB}%.o: ${DIRB}%.c
	${CC} ${FLAGS} -o $@ -c $<
	
${LIBS}:
	make -C srcs/ft_printf
	make -C srcs/MacroLibX -j16

clean:
	rm -f ${OBJS} ${OBJSB}
	make -C srcs/ft_printf clean
	make -C srcs/MacroLibX clean

fclean: clean
	rm -f ${NAME}
	rm -f ${NAMEB}
	rm -f srcs/ft_printf/libftprintf.a
	make -C srcs/MacroLibX fclean

re: fclean all

.PHONY: clean fclean re all bonus
