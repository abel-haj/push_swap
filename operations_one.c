#include "push_swap.h"

/*
 * SIZE IS TOP
 * 0 IS BOTTOM
 */

/*
 * Push from b to a
 */
void	pa(int **ints_a, int **ints_b, int *size_a, int *size_b)
{
	// a 0 -> b 0
	int	i;
	int	*tmp_a;

	tmp_a = *ints_a;
	(*ints_a) = malloc(sizeof(int) * *size_a + 1);
	while (i < size_a)
	{
		(*ints_a)[i] = tmp_a[i];
		i++;
	}
	(*ints_a)[i] = (*ints_b)[*size_b - 1];
	(*size_a)++;
	(*size_b)--;
}

/*
 * Swap the top elements in a
 */
void	sa(int **ints_a, int size_a)
{
	int	tmp;
	tmp = (*ints_a)[size_a - 2];
	(*ints_a)[size_a - 2] = (*ints_a)[size_a - 1];
	(*ints_a)[size_a - 1] = tmp;
}
