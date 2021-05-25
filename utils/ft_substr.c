/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:33:45 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 00:07:31 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*string;

	if (!s)
		return (NULL);
	i = 0;
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (NULL);
	while (len > i && ft_strlen(s) > start)
	{
		string[i] = s[i + start];
		i++;
	}
	string[i] = '\0';
	return (string);
}
