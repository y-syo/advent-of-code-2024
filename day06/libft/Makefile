# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 07:21:18 by mmoussou          #+#    #+#              #
#    Updated: 2024/12/06 09:10:58 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./src/stack/ft_stackadd_back.c ./src/stack/ft_stacksize.c ./src/stack/ft_stacklast.c ./src/stack/ft_stackadd_front.c ./src/stack/ft_stacknew.c ./src/int/ft_abs.c ./src/int/ft_min.c ./src/int/ft_max.c ./src/linked_lists/ft_lstadd_front.c ./src/linked_lists/ft_lstsize.c ./src/linked_lists/ft_lstiter.c ./src/linked_lists/ft_lstnew.c ./src/linked_lists/ft_lstadd_back.c ./src/linked_lists/ft_lstdelone.c ./src/linked_lists/ft_lstmap.c ./src/linked_lists/ft_lstclear.c ./src/linked_lists/ft_lstlast.c ./src/io/ft_putuhex_fd.c ./src/io/ft_printf_fd.c ./src/io/ft_printf.c ./src/io/ft_putnbr_fd.c ./src/io/ft_putchar_fd.c ./src/io/ft_putstr_fd.c ./src/io/ft_putendl_fd.c ./src/char/ft_isascii.c ./src/char/ft_isalpha.c ./src/char/ft_isprint.c ./src/char/ft_isalnum.c ./src/char/ft_isdigit.c ./src/str/ft_substr.c ./src/str/ft_strrchr.c ./src/str/ft_tolower.c ./src/str/ft_striteri.c ./src/str/ft_strcmp.c ./src/str/ft_split.c ./src/str/ft_strnstr.c ./src/str/ft_strncmp.c ./src/str/ft_strmapi.c ./src/str/ft_strchr.c ./src/str/ft_strlcat.c ./src/str/ft_strdup.c ./src/str/ft_strlen.c ./src/str/ft_toupper.c ./src/str/ft_strtrim.c ./src/str/ft_strjoin.c ./src/str/ft_strlcpy.c ./src/str/XtoX/ft_atoi.c ./src/str/XtoX/ft_atol.c ./src/str/XtoX/ft_ltoa.c ./src/str/XtoX/ft_itoa.c ./src/mem/ft_calloc.c ./src/mem/ft_memchr.c ./src/mem/ft_memmove.c ./src/mem/ft_memcpy.c ./src/mem/ft_memcmp.c ./src/mem/ft_free.c ./src/mem/ft_bzero.c ./src/mem/ft_memset.c

SHELL = bash

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

INCLUDE = ./include

OBJS = $(SRCS:.c=.o)

define SCRIPT_SRCS
import fileinput
import os
fl=[]
for r, d, f in os.walk('./src'):
 for fn in f:fl.append(os.path.join(r,fn))
#print(fl)
for line in fileinput.input("Makefile", inplace=True):print(line if line[:5] != "SRCS " else f'SRCS = {" ".join(fl)}\n', end='')
endef
export SCRIPT_SRCS

all: $(NAME)

CHECK_SRCS:
	@python3 -c "$$SCRIPT_SRCS"

%.o: %.c
	@printf "\x1B[1;32m[ 󱌣 ]\x1B[0m srcs : compiling : $(CC)\t$@\n"
	@$(CC) $(CFLAGS) -I$(INCLUDE) $< -c -o $@

$(NAME): $(OBJS)
	@printf "\x1B[1;32m[ 󱌣 ] srcs : compiled.\x1B[0m\n"
	@printf "\x1B[1;32m[ 󱉟 ]\x1B[0m compiling : ar\t$(NAME)\n"
	@ar rcs $(NAME) $(OBJS)
	@printf "\x1B[1;33m[ 󱉟 ] $(NAME) compiled.\x1B[0m\n"

clean:
	@rm -f $(OBJS)
	@printf "\x1B[1;31m[  ]\x1B[0m deleted objects.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\x1B[1;31m[  ] deleted $(NAME).\x1B[0m\n"

re: fclean all

.PHONY: all clean fclean re CHECK_SRCS
