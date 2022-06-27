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

AR = ar -rcs
RM = rm -rf

LIBFT_DIR = ./libft
MINI_DIR = ./minitalk

SRCS = util.c
SRCS_SERVER = $(SERVER).c
SRCS_CLIENT = $(CLIENT).c

OBJS = $(SRCS:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all : $(MINITALK)

.c.o :
	$(CC) $(CFLAGS) -I./$(MINI_DIR) -c -o $@ $<

$(SERVER) : $(OBJS_SERVER) $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(SERVER)
	$(AR) $(NAME) $(OBJS_SERVER) $(OBJS)

$(CLIENT) : $(OBJS_CLIENT) $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(CLIENT)
	$(AR) $(NAME) $(OBJS_CLIENT) $(OBJS)

$(MINITALK) : $(SERVER) $(CLIENT)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS)

fclean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY : all clean fclean re