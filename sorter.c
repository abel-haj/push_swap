#include "push_swap.h"

/*
 * checks string if it has no more than
 * one '-' and no charcters including '+'
 */
int	is_number(char *s)
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

int	is_duplicate(int *ints, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = i + 1;

	while (i < size)
	{
		tmp = ints[i]; // 0
		i++; // 1
		while (j < size)
		{
			if (tmp == ints[j]) // 0  
				return (1);
			j++;
		}
	}
	return (0);
}

int	is_sorted(int *ints, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i + 1 < size && ints[i] > ints[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
 * 0 IS TOP
 * SIZE IS BOTTOM
 */
int	main(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	int		*int_args;
	int		int_size;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		int_size = argc - 1;
		int_args = malloc(sizeof(int) * int_size);
		while (i < argc)
		{
			if (is_number(argv[i]))
			{
				int_args[int_size - i - 1] = ft_atoi(argv[i]);
				if (int_args[int_size - i - 1] == -1 && ft_strncmp("-1", argv[i], 2))
				{
					printf("%s OVERFLOW\n", argv[i]);
					// write(1, "Error\n", 6);
					write(1, "1", 1);
					free(int_args);
					exit(EXIT_FAILURE);
				}
				else if (int_args[int_size - i - 1] == 0 && ft_strncmp("0", argv[i], 1))
				{
					printf("%s UNDERFLOW\n", argv[i]);
					// write(1, "Error\n", 6);
					write(1, "2", 1);
					free(int_args);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				printf("%s: Not a number\n", argv[i]);
				// write(1, "Error\n", 6);
					write(1, "3", 1);
				free(int_args);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		i = 0;
		if (is_duplicate(int_args, int_size))
		{
			printf("Duplicate\n");
			// write(1, "Error\n", 6);
					write(1, "4", 1);
			free(int_args);
			exit(EXIT_FAILURE);
		}

		if (is_sorted(int_args, int_size))
		{
			printf("sorted\n");
		}
		else
		{
			printf("magic\n");
		}

		i = 0;
		while (i < int_size)
		{
			printf("%d ", int_args[i]);
			i++;
		}

					write(1, "5", 1);
		// free(int_args);
	}
	return (0);
}