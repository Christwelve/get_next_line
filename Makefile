# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 06:41:13 by cmeng             #+#    #+#              #
#    Updated: 2022/12/19 15:49:05 by cmeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	get_next_line.a
CC				=	cc
SRC_FILES		=	get_next_line.c \
					get_next_line_utils.c
OBJ_FILES		=	$(SRC_FILES:.c=.o)
CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I incl
RM				=	rm -f
AR				=	ar -crs

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)
	@echo "----- ft_get_next_line compiled -----"

clean:
	$(RM) $(OBJ_FILES)
	@echo "----- ft_get_next_line object files cleaned -----"

fclean: clean
	$(RM) $(NAME)
	@echo "----- ft_get_next_line executable (.a) cleaned -----"

re: fclean all
	@echo "----- Cleaned and rebuilt everything -----"

all: $(NAME)

.PHONY:		all clean fclean all re test