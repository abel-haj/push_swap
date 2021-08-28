
NAME		=	push_swap

SRC			=	operations_one.c operations_two.c ps_utils.c

FLAGS		=	-Wall -Werror -Wextra
DEBUG		=	-g -fsanitize=address

$(NAME):	
	@make -C libft && echo "libft"
	gcc $(DEBUG) sorter.c $(SRC) libft/libft.a -o push_swap

bonus:		
	@gcc $(SRC) -o checker && echo "checking..."

all:		$(NAME)

clean:		
	# @rm -f *.o a.out && echo "wiping..."
	# make clean -C libft

fclean:		clean
	@rm -f $(NAME) && echo "tidying..."
	# make fclean -C libft

re:			clean fclean all

.PHONY:		re clean fclean all
