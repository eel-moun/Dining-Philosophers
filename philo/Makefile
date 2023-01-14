# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 16:55:24 by eel-moun          #+#    #+#              #
#    Updated: 2022/10/23 20:23:07 by eel-moun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread

SRC = philo.c routine.c stockfill.c utils.c check_death.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all