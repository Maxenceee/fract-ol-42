SRCS			= $(shell find sources -name "*.c")
OBJS			= $(SRCS:.c=.o)

HEADERS			= includes/
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 
#MLX_INCLUDES	= -I /usr/X11/include
#MLX_LIB			= -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit -L ./printf -lftprintf
MLX_LIB			= -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -L ./printf -lftprintf

NAME			= fractol

# %.o: %.c $(HEADERS) Makefile
# 	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

all:			$(NAME)

$(NAME):		$(SRCS)
#				$(CC) $(MLX_INCLUDES) $(SRCS) $(MLX_LIB) -o fractol
				$(CC) $(SRCS) $(MLX_LIB) -o fractol

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus