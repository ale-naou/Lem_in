# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 13:50:13 by ale-naou          #+#    #+#              #
#    Updated: 2016/03/17 17:43:32 by ale-naou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_PATH	= ./src/
OBJ_PATH	= ./obj/
INC_PATH	= ./include/
LIB_PATH	= ./lib

NAME		= lem_in 
CC			= gcc
CFLAGS		= -Wall -Werror	-Wextra

SRC_NAME	= main.c parsing.c error.c display.c					\
				get_ants.c get_rooms.c get_tubes.c					\
				get_display.c get_comments.c check_tube.c			\
			  	create_link.c	
OBJ_NAME	= $(SRC_NAME.c=.o)
LIB_NAME	= libft.a

SRC			= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			= $(addprefix -I, $(INC_PATH))
LIB			= $(LIB_PATH)$(LIB_NAME)


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C lib $(OBJ)
	$(CC) $(CFLAGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

clean :
	rm -rf $(OBJ_PATH)
	@make clean -C lib

fclean : clean		
	rm -fv $(NAME)
	@make fclean -C lib

re : fclean all

norme :
	norminette $(SRC)		
	norminette $(INC_PATH)*.h
	norminette $(LIB_PATH)*.[ch]

.PHONY : all clean fclean re norme lib
