# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 19:36:40 by gwolf             #+#    #+#              #
#    Updated: 2024/01/27 15:50:26 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out

CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE = $(CXX) $(DEPFLAGS) $(CXXFLAGS) -c
POSTCOMPILE = @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@
RM := rm -fr

OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)/dep

SRC = 	main.cpp \
		Bureaucrat.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEPFILES = $(SRC:%.cpp=$(DEP_DIR)/%.d)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.cpp $(DEP_DIR)/%.d | $(DEP_DIR)
	$(COMPILE) $< -o $@
	$(POSTCOMPILE)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(DEPFILES):

.PHONY: clean
clean:
	$(RM) $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

include $(wildcard $(DEPFILES))
