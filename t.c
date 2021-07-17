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

void	triple_c(int **c)
{
	*c[0] = 3;
}

void	double_p(int **b)
{
	*b[0] = 1;
	triple_c(b);
}

int		main(int argc, char *argv[])
{
	int	*a = malloc(sizeof(int) * 1);
	a[0] = 0;

	printf("%d\n", a[0]);
	double_p(&a);
	printf("%d\n", a[0]);

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

	// int		i;
	// t_list	*h;

	// t_list	*f;
	// t_list	*s;
	// t_list	*t;

	// f = malloc(sizeof(t_list *));
	// s = malloc(sizeof(t_list *));
	// t = malloc(sizeof(t_list *));

	// f->content = (int *)1;
	// f->next = s;

	// s->content = (int *)2;
	// s->next = t;

	// t->content = (int *)3;
	// t->next = NULL;

	// h = f;
	// while (h)
	// {
	// 	printf("%d\n", (int)h->content);
	// 	h = h->next;
	// }

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