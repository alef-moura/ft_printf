# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 12:37:23 by alesferr          #+#    #+#              #
#    Updated: 2026/06/26 17:53:27 by alesferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
OBJS    = $(SRCS:.c=.o)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f
SRCS_D  = srcs/

SRCS    = ft_printf.c \
			$(SRCS_D)ft_putchar.c \
			$(SRCS_D)ft_putstr.c \
			$(SRCS_D)ft_putnbr.c \
			$(SRCS_D)ft_putnbr_unsigned.c \
			$(SRCS_D)ft_puthex.c \
			$(SRCS_D)ft_putptr.c \

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean: 
		$(RM) $(OBJS)

fclear: clear
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re