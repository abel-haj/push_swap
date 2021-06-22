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
	// if (i >= 10)
	// {
	// 	if (ft_strncmp(s, "2147483647", ft_strlen("2147483647") + 1) > 0)
	// 		return (0);
	// 	if (ft_strncmp(s, "-2147483648", ft_strlen("-2147483648") + 1) > 0)
	// 		return (0);
	// }
	if (i > 0 && s[i-1] == '-')
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	t_list	int_l;

	i = 1;
	j = 0;
	if (argc > 2)
	{
		while (i < argc)
		{
			// printf("[%ld:%s] -> %d\n", i+1, argv[i], is_number(argv[i]));

			if (is_number(argv[i]))
			{
				printf("%d\n", atoi(argv[i]));
				// printf("[%ld:%s] => %d\n", i+1, argv[i], ft_strncmp(argv[i], "-2147483648", ft_strlen("-2147483648") + 1));
				// printf("[%ld:%s] => %d\n", i+1, argv[i], ft_strncmp(argv[i], "2147483647", ft_strlen("2147483648") + 1));
				// 4294967296
			}
			// else
			// 	printf("")
			i++;
		}
	}
	return (0);
}