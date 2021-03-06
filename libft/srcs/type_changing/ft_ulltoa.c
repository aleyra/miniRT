/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:02:22 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/08 10:14:03 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ull_len(unsigned long long n, unsigned long long *i)
{
	int	size;

	size = 0;
	*i = 1;
	if (n < 1)
		size++;
	while (*i <= n)
	{
		*i *= 10;
		size++;
	}
	return (size);
}

char	*ft_ulltoa(unsigned long long n)
{
	char					*ulltoa;
	int						size;
	unsigned long long		i;
	int						j;

	size = ull_len(n, &i);
	ulltoa = malloc((size + 1) * sizeof(char));
	if (!(ulltoa))
		return (NULL);
	i /= 10;
	j = 0;
	while (i > 1)
	{
		ulltoa[j] = '0' + n / i;
		j++;
		n %= i;
		i /= 10;
	}
	ulltoa[j] = '0' + n;
	ulltoa[size] = 0;
	return (ulltoa);
}
