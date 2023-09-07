# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 19:36:40 by gwolf             #+#    #+#              #
#    Updated: 2023/09/07 19:57:44 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM := rm -fr

OBJDIR := obj

SRC = megaphone.cpp
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)/

fclean: clean
	$(RM) $(NAME)

re: fclean all