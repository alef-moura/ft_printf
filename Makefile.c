/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:37:23 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/18 18:07:22 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. ---------- Variaveis ---------- 
NAME    = libftprintf.a
OBJS    = $(SRCS:.c=.o)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

// ---------- 2. Listando Arquivos ---------- 
SRCS    = ft_printf.c ft_print_char.c ft_print_str.c \
			ft_printnt_nbr.c ft_print_hex.c ft_print_ptr.c \
			
// ---------- 3. Regras ---------- 
//REGRA PRINCIPAL
all: $(NAME)

//CRIAÇÃO DA BIBLIOTECA
$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

// 4. ---------- Limpeza ---------- 
clean: 
		$(RM) $(OBJS)

fclear: clear
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re