#include "push_swap.h"

/*
 * SIZE IS TOP
 * 0 IS BOTTOM
 */

/*
 * Push from stack 1 to 2
 */
void	push_stack(int **ints_from, int **ints_to, int *size_from, int *size_to, char *op)
{
	// a 0 -> b 0
	int	i;
	// int	*tmp_to;

	// tmp_to = *ints_to;
	// (*ints_to) = malloc(sizeof(int) * *size_to + 1);
	// while (i < *size_to)
	// {
	// 	(*ints_to)[i] = tmp_to[i];
	// 	i++;
	// }
	// (*ints_to)[i] = (*ints_from)[*size_from - 1];
	// KEEPING SAME ALLOCATED DATA
	// CHANGING ONLY HYPOTHETICAL SIZE
	(*ints_to)[*size_to] = (*ints_from)[*size_from - 1];
	(*size_to)++;
	(*size_from)--;
	write(1, op, ft_strlen(op));
}

/*
 * Swap the top elements in a
 */
void	swap_stack(int **ints_a, int size_a, char *op)
{
	int	tmp;
	tmp = (*ints_a)[size_a - 2];
	(*ints_a)[size_a - 2] = (*ints_a)[size_a - 1];
	(*ints_a)[size_a - 1] = tmp;
	write(1, op, ft_strlen(op));
}

/*
 * Swap two stacks at the same time
 */
void	ss(int **ints_a, int **ints_b, int size_a, int size_b)
{
	swap_stack(ints_a, size_a, "");
	swap_stack(ints_b, size_b, "");
	write(1, "ss\n", 3);
}
