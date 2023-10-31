/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekmekci <sekmekci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:18:03 by sekmekci          #+#    #+#             */
/*   Updated: 2023/10/17 19:03:50 by sekmekci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	a;

	a = ft_strlen(s) + 1;
	while (--a >= 0)
		if (s[a] == (char)c)
			return ((char *)(s + a));
	return (NULL);
}
