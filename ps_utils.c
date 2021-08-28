#include "push_swap.h"

/*
 * Norm workaround
 */
int	ternary_norm(int cond, int a, int b)
{
	if (cond)
		return (a);
	else
		return (b);
}

/*
 * Checks string if it has no more than
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
