#include <stdio.h>
#include <string.h>
#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

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

int		main(int argc, char *argv[])
{
	// int result;
	// if (argc > 1)
	// {
	// 	for (int i=1; i<argc; i++)
	// 	{
	// 		result = ft_atoi(argv[i]);
	// 		if (is_number(argv[i]))
	// 		{
	// 			if (result == -1 && strncmp("-1", argv[i], 2))
	// 				printf("%s OVERFLOW\n", argv[i]);
	// 			else if (result == 0 && strncmp("0", argv[i], 1))
	// 				printf("%s UNDERFLOW\n", argv[i]);
	// 			else
	// 				printf("%s YES\n", argv[i]);
	// 		}
	// 		else
	// 			printf("%s NOT A NUMBER\n", argv[i]);
	// 	}
	// }

	int		i;
	t_list	*a;
	t_list	*h;
	t_list	*t;
	t_list	*f;
	t_list	*s;
	t_list	*t;

	f->content = 1;
	f->next = s;
	s->content = 2;
	s->next = t;
	t->content = 3;
	t->next = NULL;

	// i = 0;
	// while (i < 5)
	// {
	// 	t = ft_lstnew(0);
	// 	a = t;
	// 	a->content = i;
	// 	a->next = a;
	// 	i++;
	// }
}