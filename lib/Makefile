# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 14:16:11 by ale-naou          #+#    #+#              #
#    Updated: 2016/03/22 22:56:00 by ale-naou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH    = ./src/
OBJ_PATH    = ./obj/
INC_PATH    = ./include/

NAME        = libft.a
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra

SRC_NAME    = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c	\
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c	\
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c	\
			ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c			\
			ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c			\
			ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c	\
			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c	\
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c	\
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c				\
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c				\
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c	\
			ft_toupper.c ft_get_next_line.c ft_str_to_hex.c ft_atof.c		\
			ft_isblank.c get_next_line.c ft_strisdigit.c ft_strisprint.c

OBJ_NAME    = $(SRC_NAME:.c=.o)

SRC         = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ         = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC         = $(addprefix -I, $(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@#printf "%-.30s %s" "$< .............................." && \
	echo "[\033[1;32mOK\033[0m]"

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY : all clean fclean re norme lib
