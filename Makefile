# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 19:54:46 by daykim            #+#    #+#              #
#    Updated: 2022/06/26 19:54:46 by daykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINITALK = MINITALK
SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = ./libft
LIBFLAGS = -L ./libft -lft

SRCS_SERVER = server.c util.c
SRCS_CLIENT = client.c util.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all : $(MINITALK)

$(LIBFT) :
	make --directory=$(LIBFT_DIR)

$(SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@

$(CLIENT) : $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@

$(MINITALK) : $(LIBFT) $(SERVER) $(CLIENT)

clean :
	make clean --directory=$(LIBFT_DIR)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean :clean
	make fclean --directory=$(LIBFT_DIR)
	$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re