# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 12:37:23 by alesferr          #+#    #+#              #
#    Updated: 2026/06/24 22:14:52 by alesferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
OBJS    = $(SRCS:.c=.o)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

SRCS    = ft_printf.c 
			

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean: 
		$(RM) $(OBJS)

fclear: clear
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re