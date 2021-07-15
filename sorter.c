#include "push_swap.h"

/*
 * checks string if it has no more than
 * one '-' and no charcters including '+'
 */
int	 is_number(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (i > 0 && s[i-1] == '-')
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	t_list	*int_l;
	t_list	*int_head_l;

	i = 1;
	j = 0;
	int_l = NULL;
	int_head_l = int_l;
	if (argc > 2)
	{
		while (i < argc)
		{
			if (is_number(argv[i]))
			{
				int_l->content = ft_lstnew(ft_atoi(argv[i]));
				if (int_l->content == -1 && ft_strncmp("-1", argv[i], 2))
				{
					printf("%s OVERFLOW\n", argv[i]);
				}
				else if (int_l->content == 0 && ft_strncmp("0", argv[i], 1))
				{
					printf("%s UNDERFLOW\n", argv[i]);
				}
				else
				{
					int_l = int_l->next;
				}
			}
			i++;
		}
	}
	return (0);
}