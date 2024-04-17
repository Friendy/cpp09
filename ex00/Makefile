# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 18:35:29 by mrubina           #+#    #+#              #
#    Updated: 2024/04/15 13:24:41 by mrubina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = easyfind

all: $(NAME)

$(NAME): $(OBJ)
	c++ -o $(NAME) $(OBJ) $(CXXFLAGS)

%.cpp.o: %.cpp
	c++ $(CXXFLAGS) -c  $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all