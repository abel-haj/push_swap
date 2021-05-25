
NAME		= checker

SRC			=	gnl/get_next_line.c gnl/get_next_line_utils.c \
				utils/*.c \
				checker_bonus.c

FLAGS		=	

$(NAME):	

bonus:		
	@gcc $(SRC) -o checker && echo "checking..."

all:		$(NAME) bonus

clean:		
	@rm -f *.o a.out && echo "wiping..."

fclean:		clean
	@rm -f $(NAME) && echo "tidying..."

re:			clean fclean all
