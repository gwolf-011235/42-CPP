# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 19:36:40 by gwolf             #+#    #+#              #
#    Updated: 2023/09/19 16:54:47 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE = $(CXX) $(DEPFLAGS) $(CXXFLAGS) -c
POSTCOMPILE = @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@
RM := rm -fr

OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)/dep

SRC = 	main.cpp \
		PhoneBook.cpp \
		Contact.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEPFILES = $(SRC:%.cpp=$(DEP_DIR)/%.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.cpp $(DEP_DIR)/%.d | $(DEP_DIR)
	$(COMPILE) $< -o $@
	$(POSTCOMPILE)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(DEPFILES):

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

include $(wildcard $(DEPFILES))