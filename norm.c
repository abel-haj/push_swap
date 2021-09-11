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
		if (but == -1)
		{
			if (stack[sm] > stack[i])
				sm = i;
		}
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
	while (i < sizetmp)
	{
		if (stacktmp[sm] > stacktmp[i])
			sm = i;
		i++;
	}
	return (sm);
}