# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 01:46:32 by bfleitas          #+#    #+#              #
#    Updated: 2024/06/18 13:28:57 by bfleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -rf

MINILIBX = -LMinilibX -lmlx_Linux -lX11 -lXext



LIBRARIES_PATH = -I/usr/include -IMinilibX

SRCS = 1-main.c 2-str_utils.c 3-array_to_double.c 4-math_utils.c \
		5-creation_fractal.c 6-rendering_fractal.c 7-build_different_fractals.c \
		8-event_manager.c
SRCB = 1-main.c 2-str_utils.c 3-array_to_double.c 4-math_utils.c \
		5-creation_fractal.c 6-rendering_fractal.c 7-build_different_fractals.c \
		8-event_manager.c

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(SRCB:.c=.o)

NAME	= fractol
BONUS_NAME = fractol_bonus

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(LIBRARIES_PATH) -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) 
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MINILIBX) -o $(BONUS_NAME)

clean:
		$(RM) $(OBJS) \
		$(BONUS_OBJS)

fclean: clean
	@if [ -f $(NAME) ]; then \
	echo "Removing $(NAME)"; \
	$(RM) $(NAME); fi
	@if [ -f $(BONUS_NAME) ]; then \
	echo "Removing $(BONUS_NAME)"; \
	$(RM) $(BONUS_NAME); fi

re: fclean all