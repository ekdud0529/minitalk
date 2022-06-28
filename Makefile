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

INCFLAGS = -I./minitalk -I./libft

ifdef BONUS
	OBJECTS_SERVER = $(OBJS_BONUS_SERVER)
	OBJECTS_CLIENT = $(OBJS_BONUS_CLIENT)
else
	OBJECTS_SERVER = $(OBJS_SERVER)
	OBJECTS_CLIENT = $(OBJS_CLIENT)
endif

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJECTS_SERVER)
	make --silent --directory=$(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(INCFLAGS) $^ -o $@

$(CLIENT) : $(OBJECTS_CLIENT)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(INCFLAGS) $^ -o $@

bonus :
	make BONUS=1

clean :
	make clean --directory=$(LIBFT_DIR)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_BONUS_CLIENT) $(OBJS_BONUS_SERVER)

fclean :clean
	make fclean --directory=$(LIBFT_DIR)
	$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re