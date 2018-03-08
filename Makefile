# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 13:32:03 by tgreil            #+#    #+#              #
#    Updated: 2018/03/04 17:15:04 by mgreil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		=	rm -rf

NAME	=	libftprintf.a

CFLAGS	+=	-Wall -Wextra -Werror

CFLAGS	+=	-I.

SRCS	=	ft_printf.c					\
			ft_printf_fd.c				\
			ft_printf_file.c			\
			ft_printf_print.c			\
			ft_printf_color.c			\
			ft_printf_conversion.c

OBJS	=	$(SRCS:.c=.o)

$(NAME):	 $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
