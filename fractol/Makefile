NAME = fractol
NAMEB = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FILES = main.c ft_strcmp.c initialize.c fractol.c \
	ft_atod.c math_utils.c ft_isdigit.c check.c \
	input.c ft_putnbr.c
BONUS = main_bonus.c ft_strcmp_bonus.c initialize_bonus.c fractol_bonus.c \
	ft_atod_bonus.c math_utils_bonus.c ft_isdigit_bonus.c check_bonus.c \
	input_bonus.c ft_putnbr_bonus.c

FILES_o = $(FILES:.c=.o)
BONUS_o = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) $(MLXFLAGS) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(BONUS_o)
	$(CC) $(CFLAGS) $(BONUS_o) $(MLXFLAGS) -o $(NAMEB)

clean:
	rm -f $(FILES_o) $(BONUS_o)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all
