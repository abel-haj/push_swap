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
		if (i + 1 < size && ints[i] < ints[i + 1])
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
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;

	i = 1;
	j = 0;
	if (argc > 1)
	{	// 3	 =	4	- 1
		size_a = argc - 1;
		size_b = argc - 1;
		stack_a = malloc(sizeof(int) * size_a);
		stack_b = malloc(sizeof(int) * size_b);
		while (i < argc)
		{
			if (is_number(argv[i]))
			{	//			3	  - 3 - 1
				stack_a[size_a - i] = ft_atoi(argv[i]);
				if (stack_a[size_a - i] == -1 && ft_strncmp("-1", argv[i], 2))
				{
					printf("%s OVERFLOW\n", argv[i]);
					// write(1, "Error\n", 6);
					free(stack_a);
					free(stack_b);
					exit(EXIT_FAILURE);
				}
				else if (stack_a[size_a - i] == 0 && ft_strncmp("0", argv[i], 1))
				{
					printf("%s UNDERFLOW\n", argv[i]);
					// write(1, "Error\n", 6);
					free(stack_a);
					free(stack_b);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				printf("%s: Not a number\n", argv[i]);
				// write(1, "Error\n", 6);
				free(stack_a);
				free(stack_b);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		i = 0;
		if (is_duplicate(stack_a, size_a))
		{
			printf("Duplicate\n");
			// write(1, "Error\n", 6);
			free(stack_a);
			free(stack_b);
			exit(EXIT_FAILURE);
		}



		if (is_sorted(stack_a, size_a))
		{
			printf("sorted\n");
		}
		else
		{

			i = size_a;
			while (i > 0)
			{
				printf("%d ", stack_a[i - 1]);
				i--;
			}
			printf("\n");

			if (size_a == 2)
			{
				swap_stack(&stack_a, size_a, "sa\n");
			}
			else if (size_a == 3)
			{
				// write(1, "1\n", 2);
			}
			if (size_a <= 5)
			{
				// write(1, "2\n", 2);
			}
			else
			{
				// write(1, "3\n", 2);
			}

			i = size_a;
			while (i > 0)
			{
				printf("%d ", stack_a[i - 1]);
				i--;
			}
			printf("\n");
		}

		free(stack_a);
		free(stack_b);
	}
	return (0);
}