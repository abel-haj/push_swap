#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	ft_print_result(t_list *elem)
{
	int	len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
}

void	ft_del(void *content)
{
	free(content);
}

t_list	*ft_lstnewone(void const *content)
{
	t_list	  *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
	}
	else
	{
		if (!(elem->content = malloc(sizeof(*(elem->content)) * sizeof(content))))
		{
			free(elem);
			return (NULL);
		}
		elem->content = memcpy(elem->content, content, sizeof(content));
	}
	elem->next = NULL;
	return (elem);
}

void	ft_lst_print_before(t_list *lst)
{

	lst->next = lst;
	lst = lst->next;
	ft_print_result(lst);
	write(1, "\n", 1);
}

int main(int argc, const char *argv[])
{
	t_list	  *elem;
	t_list	  *elem2;
	t_list	  *elem3;
	t_list	  *elem4;
	char	str [] = "lorem";
	char	str2 [] = "ipsum";
	char	str3 [] = "dolor";
	char	str4 [] = "sit";

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[1]) == 1)
	{
		ft_lstdelone(elem3, &ft_del);
		if (elem)
			ft_print_result(elem);
		else
			write(1, "NULL", 4);
		write(1, "\n", 1);
		if (elem2)
			ft_print_result(elem2);
		else
			write(1, "NULL", 4);
		write(1, "\n", 1);
		if (elem3)
			ft_print_result(elem3);
		else
			write(1, "NULL", 4);
		write(1, "\n", 1);
		if (elem4)
			ft_print_result(elem4);
		else
			write(1, "NULL", 4);
	}
	else if (atoi(argv[1]) == 2)
	{
		ft_print_result(elem3);
		ft_lst_print_before(elem3);
	}
	return (0);
}
