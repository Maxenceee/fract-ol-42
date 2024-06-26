MANDATORY_DIR	=	mandatory
BONUS_DIR		=	bonus
OBJ_DIR			=	.objs

SRCS			=	$(MANDATORY_DIR)/circles_utils.c	\
					$(MANDATORY_DIR)/circles.c	\
					$(MANDATORY_DIR)/colors.c	\
					$(MANDATORY_DIR)/complex_nums_opperators.c	\
					$(MANDATORY_DIR)/complex_nums.c	\
					$(MANDATORY_DIR)/fractal_apollonian_gasket.c	\
					$(MANDATORY_DIR)/fractal_burningship.c	\
					$(MANDATORY_DIR)/fractal_julia.c	\
					$(MANDATORY_DIR)/fractal_mandelbrot.c	\
					$(MANDATORY_DIR)/fractol_home.c	\
					$(MANDATORY_DIR)/fractol_init.c	\
					$(MANDATORY_DIR)/fractol_list.c	\
					$(MANDATORY_DIR)/fractol_output.c	\
					$(MANDATORY_DIR)/fractol_parse_args.c	\
					$(MANDATORY_DIR)/fractol.c	\
					$(MANDATORY_DIR)/ft_atof.c	\
					$(MANDATORY_DIR)/ft_atoi.c	\
					$(MANDATORY_DIR)/ft_isdigit.c	\
					$(MANDATORY_DIR)/ft_bzero.c	\
					$(MANDATORY_DIR)/ft_strcmp.c	\
					$(MANDATORY_DIR)/ft_strstr.c	\
					$(MANDATORY_DIR)/ft_strtolower.c	\
					$(MANDATORY_DIR)/home_events.c	\
					$(MANDATORY_DIR)/key_events.c	\
					$(MANDATORY_DIR)/mlx_destroy_display.c \
					$(MANDATORY_DIR)/mlx_draw.c	\
					$(MANDATORY_DIR)/mlx_events.c	\
					$(MANDATORY_DIR)/mouse_events.c	\
					$(MANDATORY_DIR)/mouse_move.c	\
					$(MANDATORY_DIR)/pallets.c	\
					$(MANDATORY_DIR)/pallets2.c	\
					$(MANDATORY_DIR)/pallets3.c
OBJS			=	$(patsubst $(MANDATORY_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

SRCS_BONUS		=	$(BONUS_DIR)/circles_utils_bonus.c	\
					$(BONUS_DIR)/circles_bonus.c	\
					$(BONUS_DIR)/colors_bonus.c	\
					$(BONUS_DIR)/colors_utils_bonus.c	\
					$(BONUS_DIR)/complex_nums_opperators_bonus.c	\
					$(BONUS_DIR)/complex_nums_bonus.c	\
					$(BONUS_DIR)/complex_nums_trigo_bonus.c	\
					$(BONUS_DIR)/fractal_apollonian_gasket_bonus.c	\
					$(BONUS_DIR)/fractal_burningship_bonus.c	\
					$(BONUS_DIR)/fractal_julia_bonus.c	\
					$(BONUS_DIR)/fractal_mandelbrot_bonus.c	\
					$(BONUS_DIR)/fractal_tricorn_bonus.c	\
					$(BONUS_DIR)/fractal_zc_bonus.c	\
					$(BONUS_DIR)/fractal_sinzc_bonus.c	\
					$(BONUS_DIR)/fractol_home_bonus.c	\
					$(BONUS_DIR)/fractol_init_bonus.c	\
					$(BONUS_DIR)/fractol_list_bonus.c	\
					$(BONUS_DIR)/fractol_list_2_bonus.c	\
					$(BONUS_DIR)/fractol_output_bonus.c	\
					$(BONUS_DIR)/fractol_parse_args_bonus.c	\
					$(BONUS_DIR)/fractol_bonus.c	\
					$(BONUS_DIR)/ft_atof_bonus.c	\
					$(BONUS_DIR)/ft_atoi_bonus.c	\
					$(BONUS_DIR)/ft_isdigit_bonus.c	\
					$(BONUS_DIR)/ft_bzero_bonus.c	\
					$(BONUS_DIR)/ft_strcmp_bonus.c	\
					$(BONUS_DIR)/ft_strstr_bonus.c	\
					$(BONUS_DIR)/ft_strtolower_bonus.c	\
					$(BONUS_DIR)/home_events_bonus.c	\
					$(BONUS_DIR)/key_events_bonus.c	\
					$(BONUS_DIR)/mlx_destroy_display.c \
					$(BONUS_DIR)/mlx_draw_bonus.c	\
					$(BONUS_DIR)/mlx_events_bonus.c	\
					$(BONUS_DIR)/mouse_events_bonus.c	\
					$(BONUS_DIR)/mouse_move_bonus.c	\
					$(BONUS_DIR)/pallets_bonus.c	\
					$(BONUS_DIR)/pallets2_bonus.c	\
					$(BONUS_DIR)/pallets3_bonus.c	\

OBJS_BONUS		=	$(patsubst $(BONUS_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

NAME			=	fractol

HEADER_SRCS		=	fractol.h fractol_bonus.h
HEADERS_DIR		=	includes/
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADER_SRCS))
CC				=	cc
RM				=	rm -f
INCLUDES_DIR	=	-I $(HEADERS_DIR) -I./printf-42
PRINTF_LIB		=	-L ./printf-42 -lftprintf
CFLAGS			=	-Wall -Wextra -Werror -ofast $(INCLUDES_DIR)

ifeq ($(shell uname), Darwin)
	MLX_DIR			=	libmlx_mac
	MLX_LIB			=	-L ./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR			=	libmlx_linux
	MLX_LIB			=	-L./$(MLX_DIR) -lmlx -lX11 -lXext -lm -lpthread
endif

GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
RED				=	\033[1;31m
YELLOW      	=	\033[1;33m
DEFAULT			=	\033[0m
UP				=	"\033[A"
CUT				=	"\033[K"

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

all: lib $(NAME)

lib:
	@echo "$(YELLOW)Make MLX$(DEFAULT)"
	@make -sC $(MLX_DIR)
	@echo "$(YELLOW)Make ft_printf$(DEFAULT)"
	@make bonus -sC printf-42
	@echo "$(BLUE)Compiling...$(DEFAULT)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_LIB) $(PRINTF_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

bonus: lib $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(MLX_LIB) $(PRINTF_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) bonus compiled!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@$(RM) $(NAME)
	@make fclean -sC printf-42
	@make clean -sC $(MLX_DIR)

re:				fclean all

.PHONY:			all clean fclean re bonus