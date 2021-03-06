#include "push_swap.h"

void	print_stack(int *a, int size)
{
	while (size > 0)
	{
		printf("%d ", a[size - 1]);
		size--;
	}
	printf("\n");
}

void	print_stacks(int *a, int *b, int size_a, int size_b)
{
	int	i;
	int	size;

	i = 0;
	size = ternary_norm(size_a > size_b, size_a, size_b);
	while (i < size)
	{
		if (i < size_a)
			printf("%5d", a[i]);
		else
			printf("     ");
		
		if (i < size_b)
			printf("\t%5d\n", b[i]);
		else
			printf("\n");
		i++;
	}
	printf("--------------------\n");
}

int	get_biggest_ind(int *stack, int size)
{
	int	i;
	int	big;

	i = 0;
	big = i;
	while (i < size)
	{
		if (stack[i] > stack[big])
			big = i;
		i++;
	}
	return (big);
}

int	get_smaller_ind_but(int *stack, int size, int but)
{
	int	i;
	int	sm;
	int	*stacktmp;
	int	sizetmp;

	i = 0;
	sm = 0;
	sizetmp = 0;
	stacktmp = malloc(sizeof(int) * size);
		while (i < size)
		{
			// smallest
			if (but == -1)
			{
				if (stack[sm] > stack[i])
					sm = i;
			}

			// store every number bigger than
			// {stack[but]}
			if (stack[but] < stack[i])
			{
				stacktmp[sizetmp] = stack[i];
				sizetmp++;
			}
			i++;
		}

		if (but == -1)
		{
			free(stacktmp);
			return (sm);
		}

		printf(" %d\n", sm);

		i = 0;
		while (i < sizetmp)
		{
			if (stacktmp[sm] > stacktmp[i])
				sm = i;
			i++;
		}
		return (sm);
}

/*
 * SIZE IS TOP
 * 0 IS BOTTOM
 */
void	sort_three(int *a)
{
	int	big;

	big = get_biggest_ind(a, 3);
	if (big == 0)
		swap_stack(&a, 3, "sa\n");
	else if (big == 1)
	{
		if (a[0] > a[2])
		{
			swap_stack(&a, 3, "sa\n");
			rotate_stack(&a, 3, "ra\n");
		}
		else
			rrotate_stack(&a, 3, "rra\n");
	}
	else if (big == 2)
	{
		if (a[0] < a[1])
		{
			swap_stack(&a, 3, "sa\n");
			rrotate_stack(&a, 3, "rra\n");
		}
		else
			rotate_stack(&a, 3, "ra\n");
	}
}

void	sort_four(int *a, int *b, int sizea, int sizeb)
{
	size_t	i;
	size_t	sm;

	// GET SMALLEST NUMBER
	i = 0;
	sm = i;
	while (i < sizea)
	{
		if (a[sm] > a[i])
			sm = i;
		i++;
	}
	// PUSH SMALLEST ONE TO STACK B AGAIN
	if (sm == 2)
		rotate_stack(&a, sizea, "ra\n");
	else if (sm == 1 || sm == 0)
	{
		rrotate_stack(&a, sizea, "rra\n");
		if (sm == 1)
			rrotate_stack(&a, sizea, "rra\n");
	}
	push_stack(&a, &b, &sizea, &sizeb, "pb\n");

	// SORT THREE REMAINING
	if (!is_sorted(a, 3))
		sort_three(a);

	// POP BACK OTHER ONE
	push_stack(&b, &a, &sizeb, &sizea, "pa\n");
}

/*
 * SIZE IS TOP
 * 0 IS BOTTOM
 */
void	sort_five(int *a, int *b, int sizea, int sizeb)
{
	size_t	i;
	size_t	sm;

	// GET SMALLEST NUMBER
	i = 0;
	sm = i;
	while (i < sizea)
	{
		if (a[sm] > a[i])
			sm = i;
		i++;
	}
	// PUSH SMALLEST ONE TO STACK B
	if (sm == 3)
		rotate_stack(&a, sizea, "ra\n");
	else if (sm == 2)
	{
		rotate_stack(&a, sizea, "ra\n");
		rotate_stack(&a, sizea, "ra\n");
	}
	else if (sm == 1 || sm == 0)
	{
		rrotate_stack(&a, sizea, "rra\n");
		if (sm == 1)
			rrotate_stack(&a, sizea, "rra\n");
	}

	push_stack(&a, &b, &sizea, &sizeb, "pb\n");

	// GET SMALLEST NUMBER AGAIN	
	i = 0;
	sm = i;
	while (i < sizea)
	{
		if (a[sm] > a[i])
			sm = i;
		i++;
	}
	// PUSH SMALLEST ONE TO STACK B AGAIN
	if (sm == 2)
		rotate_stack(&a, sizea, "ra\n");
	else if (sm == 1 || sm == 0)
	{
		rrotate_stack(&a, sizea, "rra\n");
		if (sm == 1)
			rrotate_stack(&a, sizea, "rra\n");
	}
	push_stack(&a, &b, &sizea, &sizeb, "pb\n");

	// SORT THREE REMAINING
	if (!is_sorted(a, 3))
		sort_three(a);

	// POP BACK OTHER TWO
	push_stack(&b, &a, &sizeb, &sizea, "pa\n");
	push_stack(&b, &a, &sizeb, &sizea, "pa\n");
}

void	sort_a_lot(int *a, int *b, int sizea, int sizeb)
{
	size_t	i;
	size_t	j;
	// create new array
	int	*stack_tmp;
	int	sizetmp;
	int	sm;

	i = 0;
	j = 1;
	sm = 0;
	sizetmp = 0;
	stack_tmp = malloc(sizeof(int) * sizea);
	// while (i < sizea)
	// {
		while (j < sizea)
		{
			if (a[j] < a[sm])
				sm = j;
			j++;
		}

		stack_tmp[sizetmp] = a[sm];
		sizetmp++;

		// TODO :
		// 		sort 
		// while (j < sizea)
		// {
		// 	if ()
		// }
	// 	i++;
	// }
	// sm = get_smaller_ind_but(a, sizea, -1);
	// printf("(%d : %d) ", sm, a[sm]);

	// sm = get_smaller_ind_but(a, sizea, sm);
	// printf("(%d : %d) ", sm, a[sm]);

	sm = get_smaller_ind_but(a, sizea, 0);
	printf("(%d : %d) ", sm, a[sm]);

	printf("\n");
	// print_stack(stack_tmp, i);
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
			if (size_a == 2)
			{
				swap_stack(&stack_a, size_a, "sa\n");
			}
			else if (size_a == 3)
			{
				sort_three(stack_a);
			}
			else if (size_a == 4)
			{
				sort_four(stack_a, stack_b, 4, 0);
			}
			else if (size_a == 5)
			{
				sort_five(stack_a, stack_b, 5, 0);
			}
			else if (size_a >= 20)
			{
				sort_a_lot(stack_a, stack_b, size_a, size_b);
			}
			else
			{
				printf("sort a 19 - 6 : %d\n", size_a);
			}
			print_stack(stack_a, size_a);
		}

		free(stack_a);
		free(stack_b);
	}
	return (0);
}