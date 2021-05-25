#include <stdio.h>
#include <string.h>

int		main()
{
	// printf("%d\n", ft_atoi("-4147483649"));
	printf("%d\n", ft_strncmp("-2147483648", "-2147483648888", ft_strlen("-2147483648") + 1));
	// printf("%d\n", strcmp("2147483647", "2147483647"));
}