# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 18:35:29 by mrubina           #+#    #+#              #
#    Updated: 2024/04/22 21:57:34 by mrubina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -std=c++98 #-g -fsanitize=thread
# ASFLAG = -fsanitize=address
# THSFLAG = -fsanitize=thread

SRC = main.cpp PmergeMe.cpp VPair.cpp
OBJ = $(SRC:.cpp=.o)
NAME = PmergeMe

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