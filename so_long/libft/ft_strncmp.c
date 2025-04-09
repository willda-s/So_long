/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:38 by willda-s          #+#    #+#             */
/*   Updated: 2024/11/26 17:21:20 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = 0;
	while ((s2[i] || s1[i]) && i < length)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char tab[] = "abcdef";
	char tab2[] = "abc\375xx";
	size_t l = 5;
	printf("%d\n", ft_strncmp(tab, tab2, l));
	//printf("%d", strncmp(tab, tab2, l));
}*/
