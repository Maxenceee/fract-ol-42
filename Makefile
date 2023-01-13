SRCS			= $(shell find mandatory -name "*.c")
OBJS			= $(SRCS:.c=.o)

SRCS_BONUS		= $(shell find bonus -name "*.c")
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

HEADER_SRCS		=	fractol.h fractol_bonus.h
HEADERS_DIR		=	includes/
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADER_SRCS))
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -o3
#MLX_INCLUDES	=	-I /usr/X11/include
#MLX_LIB		=	-L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit -L ./printf -lftprintf
MLX_LIB			=	-L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -L ./printf -lftprintf
NAME			=	fractol

%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ 

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(OBJS) $(MLX_LIB) -o $(NAME)
				@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

bonus:			$(OBJS_BONUS)
				@$(CC) $(OBJS_BONUS) $(MLX_LIB) -o $(NAME)
				@echo "$(GREEN)$(NAME) bonus compiled!$(DEFAULT)"

mlx:
				@cd minilibx_opengl_20191021/ && make

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus