# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 19:21:29 by ricsanto          #+#    #+#              #
#    Updated: 2025/05/09 08:48:49 by ricsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

FLAGS := -Wall -Wextra -Werror

SRC :=	ft_printf.c	h_put_char.c	h_put_nbr.c	h_put_base.c	\
		h_put_ptr.c	h_put_str.c		h_strlen.c

OBJ := $(SRC:.c=.o)

AR := ar -rcs

RM := rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	cc $(FLAGS) -o $@ -c $< -I.

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
