# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mescande <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 14:03:19 by mescande          #+#    #+#              #
#    Updated: 2019/04/25 04:55:17 by mescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_DIR = srcs/
OBJ_DIR = obj/
INC_DIR = includes/
SRC_LIST = chr/ft_isalnum.c\
		   chr/ft_isalpha.c\
		   chr/ft_isascii.c\
		   chr/ft_isblank.c\
		   chr/ft_iscntrl.c\
		   chr/ft_isdigit.c\
		   chr/ft_isgraph.c\
		   chr/ft_islower.c\
		   chr/ft_isprint.c\
		   chr/ft_isspace.c\
		   chr/ft_isupper.c\
		   chr/ft_isxdigit.c\
		   chr/ft_tolower.c\
		   chr/ft_toupper.c\
		   lst/ft_lstadd.c\
		   lst/ft_lstdel.c\
		   lst/ft_lstdelone.c\
		   lst/ft_lstiter.c\
		   lst/ft_lstmap.c\
		   lst/ft_lstnew.c\
		   mem/ft_bzero.c\
		   mem/ft_memalloc.c\
		   mem/ft_memccpy.c\
		   mem/ft_memchr.c\
		   mem/ft_memcmp.c\
		   mem/ft_memcpy.c\
		   mem/ft_memdel.c\
		   mem/ft_memmove.c\
		   mem/ft_memset.c\
		   put/ft_putchar.c\
		   put/ft_putchar_fd.c\
		   put/ft_putendl.c\
		   put/ft_putendl_fd.c\
		   put/ft_putnbr.c\
		   put/ft_putnbr_fd.c\
		   put/ft_putstr.c\
		   put/ft_putstr_fd.c\
		   str/ft_atoi.c\
		   str/ft_itoa.c\
		   str/ft_strcat.c\
		   str/ft_strchr.c\
		   str/ft_strclr.c\
		   str/ft_strcmp.c\
		   str/ft_strcpy.c\
		   str/ft_strdel.c\
		   str/ft_strdup.c\
		   str/ft_strequ.c\
		   str/ft_striter.c\
		   str/ft_striteri.c\
		   str/ft_strjoin.c\
		   str/ft_strlcat.c\
		   str/ft_strlen.c\
		   str/ft_strmap.c\
		   str/ft_strmapi.c\
		   str/ft_strncat.c\
		   str/ft_strncmp.c\
		   str/ft_strncpy.c\
		   str/ft_strnequ.c\
		   str/ft_strnew.c\
		   str/ft_strnstr.c\
		   str/ft_strsplit.c\
		   str/ft_strrchr.c\
		   str/ft_strstr.c\
		   str/ft_strsub.c\
		   str/ft_strtok.c\
		   str/ft_strtrim.c
		   
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))
DIR = $(sort $(dir $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)

$(DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)
