#include "push_swap.h"

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
	if (i >= 10)
	{
		if (ft_strncmp(s, "2147483647", ft_strlen("2147483647") + 1) > 0)
			return (0);
		if (ft_strncmp(s, "-2147483648", ft_strlen("-2147483648") + 1) > 0)
			return (0);
	}
	return (1);
}

int		main(void)
{
	size_t	i;
	size_t	j;
	size_t	n_ints;
	char	*line;
	char	**ints;
	t_list	*my_list;
	t_list	*head_list;

	my_list = NULL;
	head_list = NULL;
	ints = ft_split(line, ' ');
	n_ints = ft_countsplit(line, ' ');
	if (n_ints == 0)
		printf("empty\n");
	else if (n_ints == 1)
		printf("too little\n");
	else
	{
// no duplicates
		i = 0;
		while (i < n_ints)
		{
			// no chars
			if (!is_number(ints[i]))
			{
				printf("not allowed\n");
				break;
			}
			i++;
		}
	}

	ft_freesplitted(ints, n_ints);
	free(line);
	return (0);
}
