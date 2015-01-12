# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdismuke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/10 15:28:26 by bdismuke          #+#    #+#              #
#    Updated: 2015/01/11 16:35:00 by bdismuke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = Enemy.cpp main.cpp Leviathan.cpp DarkShadow.cpp Entity.cpp Level.class.cpp Obstacle.cpp Player.cpp main.cpp

INC = Color.define.hpp Enemy.hpp Leviathan.hpp DarkShadow.hpp Entity.hpp Entitys.struct.hpp Level.class.hpp Obstacle.hpp Player.hpp

OBJ = $(SRC:.cpp=.o)

CXX = g++

M = make

CFLAGS = -Wall -Werror -Wextra -lcurses

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) -c $(SRC)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
