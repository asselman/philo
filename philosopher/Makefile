# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 03:59:04 by aasselma          #+#    #+#              #
#    Updated: 2023/06/22 15:21:08 by aasselma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c philo_utils.c philo_routin.c

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -fsanitize=thread -g $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@echo "<<<<all files are deleted>>>>"

fclean: clean
	@$(RM) $(NAME)

re:	fclean all
