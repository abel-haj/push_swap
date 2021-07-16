#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// // void	pa(int **ints_a, int **ints_b, int *size_a, int *size_b);
// // void	pb(int **ints_a, int **ints_b, int *size_a, int *size_b);
void	push_stack(int **ints_a, int **ints_b, int *size_a, int *size_b, char *op);
void	swap_stack(int **ints, int size, char *op);
// // void	sa(int **ints_a, int size_a);
// // void	sb(int **ints_b, int size_b);
void	ss(int **ints_a, int **ints_b, int size_a, int size_b);
// // void	ra(int **ints_a, int size_a);
// // void	rb(int **ints_b, int size_b);
void    rotate_stack(int **ints, int size, char *op);
void	rr(int **ints_a, int **ints_b, int size_a, int size_b);
void    rrotate_stack(int **ints, int size, char *op);
// // void	rra(int **ints_a, int size_a);
// // void	rrb(int **ints_b, int size_b);
void	rrr(int **ints_a, int **ints_b, int size_a, int size_b);

#endif