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

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = libft
LIBFT_DIR = ./libft
LIBFLAGS = -L $(LIBFT_DIR) -lft

MINI_DIR = ./minitalk
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(addprefix $(MINI_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(MINI_DIR)/, $(SRCS_CLIENT:.c=.o))

BONUS_DIR = ./bonus
SRCS_BONUS_SERVER = server_bonus.c
SRCS_BONUS_CLIENT = client_bonus.c
OBJS_BONUS_SERVER = $(addprefix $(BONUS_DIR)/, $(SRCS_BONUS_SERVER:.c=.o))
OBJS_BONUS_CLIENT = $(addprefix $(BONUS_DIR)/, $(SRCS_BONUS_CLIENT:.c=.o))

ifdef BONUS
	$(OBJS_SERVER) = $(OBJS_BONUS_SERVER)
	$(OBJS_CLIENT) = $(OBJS_BONUS_CLIENT)
endif

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	make --directory=$(LIBFT_DIR)

$(SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@

$(CLIENT) : $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(LIBFLAGS) $^ -o $@

bonus :
	make BONUS=true

clean :
	make clean --directory=$(LIBFT_DIR)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean :clean
	make fclean --directory=$(LIBFT_DIR)
	$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re libft