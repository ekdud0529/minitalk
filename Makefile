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

LIBFT_DIR = ./libft
MINI_DIR = ./minitalk

SRCS = util.c
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS = $(addprefix $(MINI_DIR)/, $(SRCS:.c=.o))
OBJS_SERVER = $(addprefix $(MINI_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(MINI_DIR)/, $(SRCS_CLIENT:.c=.o))

all : $(MINITALK)

.c.o :
	$(CC) $(CFLAGS) -I./$(MINI_DIR) -c -o $@ $<

$(SERVER) : $(OBJS_SERVER) $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(SERVER)
	$(CC) $(CFLAGS) -I./$(LIBFT_DIR)$^ -o $@

$(CLIENT) : $(OBJS_CLIENT) $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(CLIENT)
	$(CC) $(CFLAGS) -I./$(LIBFT_DIR)$^ -o $@

$(MINITALK) : $(SERVER) $(CLIENT)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS)

fclean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re