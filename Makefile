SRCS			=	./mandatory/circles_utils.c	\
					./mandatory/circles.c	\
					./mandatory/colors.c	\
					./mandatory/complex_nums_opperators.c	\
					./mandatory/complex_nums.c	\
					./mandatory/fractal_apollonian_gasket.c	\
					./mandatory/fractal_burningship.c	\
					./mandatory/fractal_julia.c	\
					./mandatory/fractal_mandelbrot.c	\
					./mandatory/fractol_home.c	\
					./mandatory/fractol_init.c	\
					./mandatory/fractol_list.c	\
					./mandatory/fractol_output.c	\
					./mandatory/fractol_parse_args.c	\
					./mandatory/fractol.c	\
					./mandatory/ft_atof.c	\
					./mandatory/ft_atoi.c	\
					./mandatory/ft_isdigit.c	\
					./mandatory/ft_memcpy.c	\
					./mandatory/ft_strcmp.c	\
					./mandatory/ft_strstr.c	\
					./mandatory/ft_strtolower.c	\
					./mandatory/home_events.c	\
					./mandatory/key_events.c	\
					./mandatory/mlx_draw.c	\
					./mandatory/mlx_events.c	\
					./mandatory/mouse_events.c	\
					./mandatory/mouse_move.c	\
					./mandatory/pallets.c	\
					./mandatory/pallets2.c	\
					./mandatory/pallets3.c
OBJS			=	$(SRCS:.c=.o)

SRCS_BONUS		=	./bonus/circles_utils_bonus.c	\
					./bonus/circles_bonus.c	\
					./bonus/colors_bonus.c	\
					./bonus/complex_nums_opperators_bonus.c	\
					./bonus/complex_nums_bonus.c	\
					./bonus/fractal_apollonian_gasket_bonus.c	\
					./bonus/fractal_burningship_bonus.c	\
					./bonus/fractal_julia_bonus.c	\
					./bonus/fractal_mandelbrot_bonus.c	\
					./bonus/fractol_home_bonus.c	\
					./bonus/fractol_init_bonus.c	\
					./bonus/fractol_list_bonus.c	\
					./bonus/fractol_output_bonus.c	\
					./bonus/fractol_parse_args_bonus.c	\
					./bonus/fractol_bonus.c	\
					./bonus/ft_atof_bonus.c	\
					./bonus/ft_atoi_bonus.c	\
					./bonus/ft_isdigit_bonus.c	\
					./bonus/ft_memcpy_bonus.c	\
					./bonus/ft_strcmp_bonus.c	\
					./bonus/ft_strstr_bonus.c	\
					./bonus/ft_strtolower_bonus.c	\
					./bonus/home_events_bonus.c	\
					./bonus/key_events_bonus.c	\
					./bonus/mlx_draw_bonus.c	\
					./bonus/mlx_events_bonus.c	\
					./bonus/mouse_events_bonus.c	\
					./bonus/mouse_move_bonus.c	\
					./bonus/pallets_bonus.c	\
					./bonus/pallets2_bonus.c	\
					./bonus/pallets3_bonus.c	
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

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