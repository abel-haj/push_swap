#include "push_swap.h"


/*
 * Rotate a stack
 * Top element becomes last
 */
void    rotate_stack(int **ints, int size, char *op)
{
	int	i;
	int	tmp;

	i = size - 1;
	tmp = (*ints)[i];
	while (i > 0)
	{
		(*ints)[i] = (*ints)[i - 1];
		i--;
	}
	(*ints)[i] = tmp;
	write(1, op, ft_strlen(op));
}

/*
 *
 */
void	rr(int **ints_a, int **ints_b, int size_a, int size_b)
{
    rotate_stack(ints_a, size_a, "");
    rotate_stack(ints_b, size_b, "");
    write(1, "rr\n", 3);
}

/*
 * SIZE IS TOP
 * 0 IS BOTTOM
 */

/*
 *  The bottom element becomes the first
 */
void    rrotate_stack(int **ints, int size, char *op)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = (*ints)[0];
	while (i < size - 1)
	{
		(*ints)[i] = (*ints)[i + 1];
		i++;
	}
	(*ints)[i] = tmp;
	write(1, op, ft_strlen(op));
}

/*
 *
 */
void	rrr(int **ints_a, int **ints_b, int size_a, int size_b)
{
    rrotate_stack(ints_a, size_a, "");
    rrotate_stack(ints_b, size_b, "");
    write(1, "rrr\n", 4);
}
