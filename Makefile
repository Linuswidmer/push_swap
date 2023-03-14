# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 19:41:22 by lwidmer           #+#    #+#              #
#    Updated: 2023/02/28 12:09:32 by lwidmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILENAMES_FT_PRINTF = ft_strlen ft_putchar_fd ft_putstr_fd ft_intlen_base ft_printf ft_strlcpy ft_print_address_hex ft_putnbr_base

FILENAMES_PUSH_SWAP = main ft_split check_input stack swap rotate push print utils terminate init sort sort_two_three

SRCS_FT_PRINTF = ./srcs_ft_printf/
SRCS_PUSH_SWAP = ./srcs_push_swap/
SRCS = $(addprefix $(SRCS_FT_PRINTF), $(addsuffix .c, $(FILENAMES_FT_PRINTF)) $(addprefix $(SRCS_PUSH_SWAP), $(addsuffix .c, $(FILENAMES_PUSH_SWAP))))

OBJS_FT_PRINTF = ./srcs_ft_printf/
OBJS_PUSH_SWAP = ./srcs_push_swap/
OBJS = $(addprefix $(OBJS_FT_PRINTF), $(addsuffix .o, $(FILENAMES_FT_PRINTF))) $(addprefix $(OBJS_PUSH_SWAP), $(addsuffix .o, $(FILENAMES_PUSH_SWAP)))

CFLAGS = -Werror -Wall -Wextra

INCLUDES_DIR = -I ./includes

${NAME}: ${OBJS}
	cc -o push_swap $^

.c.o: ${SRCS}
	cc ${CFLAGS} -c -o $@ $< ${INCLUDES_DIR}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

twenty:
	./push_swap "11 16 15 0 8 2 19 3 17 13 6 5 14 7 12 4 18 1 10 9"
	# ./push_swap "11 16 2 0 8 15 19 3 17 13 6 5 14 7 12 4 9 1 10 18"

memory:
	cc -g3 -fsanitize=address -Werror -Wall -Wextra ${SRCS} $(MINILIBXFLAGS) ${INCLUDES_DIR} -L. ./libft/libft.a -o fdf
