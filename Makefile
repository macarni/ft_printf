# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:52:47 by adrperez          #+#    #+#              #
#    Updated: 2023/01/10 15:15:01 by adrperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Exit
NAME		= 	libftprintf.a

#Sources
SRCS		= 	ft_printf.c \
				ft_print_letters.c \
				ft_print_numbers.c

OBJS		= 	$(SRCS:.c=.o)

#Compilation
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

#Erase
RM			= 	rm -rf

#Default target
all:		$(NAME)
			
# Linking: option -r to ensure that if the library (.a) file already exists, 
# it will be replaced. The command option -c should be used so that if the 
# file doesn’t exist, it will be created.
$(NAME):	$(OBJS) 
			ar -rcs $(NAME) $(OBJS)

#Cleaning objects (Eliminacion de objetos)
clean:
			$(RM) $(OBJS)

#Cleaning objects and executable 
fclean:		clean
			$(RM) $(NAME)

#Cleaning all and then compilation
re:			fclean all

#Exectute no matter name is
.PHONY: all clean fclean re