
NAME		= push_swap

SRC			=	gnl/get_next_line.c gnl/get_next_line_utils.c \
				utils/*.c \
				checker_bonus.c

FLAGS		=	-Wall -Werror -Wextra

$(NAME):	
	@make -C libft && echo "libft"
	gcc libft/libft.a sorter.c -o push_swap

bonus:		
	@gcc $(SRC) -o checker && echo "checking..."

all:		$(NAME)

clean:		
	@rm -f *.o a.out && echo "wiping..."
	make clean -C libft

fclean:		clean
	@rm -f $(NAME) && echo "tidying..."
	make fclean -C libft

re:			clean fclean all

.PHONY:		re clean fclean all
