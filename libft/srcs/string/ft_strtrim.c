/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:25:39 by lburnet           #+#    #+#             */
/*   Updated: 2021/02/17 11:12:38 by lucille          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

static size_t	len_f_tri(const char *s1, const char *set)
{
	size_t		j;
	size_t		len;
	int			non_set;

	len = ft_strlen(s1);
	non_set = 0;
	while (non_set == 0 && *s1 != 0)
	{
		j = 0;
		while (set[j] != 0)
		{
			if (*s1 != set[j++])
			{
				if (set[j] == 0)
					non_set = 1;
			}
			else
			{
				len--;
				j = ft_strlen(set);
			}
		}
		s1++;
	}
	return (len);
}

static size_t	len_b_tri(const char *s1, const char *set, size_t len)
{
	size_t		i;
	size_t		j;
	int			non_set;

	i = ft_strlen(s1) - 1;
	non_set = 0;
	while (non_set == 0 && s1[i] && len != 0)
	{
		j = 0;
		while (set[j] != 0)
		{
			if (s1[i] != set[j++])
			{
				if (set[j] == 0)
					non_set = 1;
			}
			else
			{
				len--;
				j = ft_strlen(set);
			}
		}
		i--;
	}
	return (len);
}

static void		in_while(char const *s1, char const *set, int **i, int *isset)
{
	if (s1[(*i)[0]] == set[(*i)[1]])
		*isset = 1;
	if (s1[(*i)[0]] != set[(*i)[1]])
		(i[1])++;
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*r;
	int			i[2];
	size_t		isset;

	if (!s1 || !set)
		return (NULL);
	if (!(r = malloc((len_b_tri(s1, set, len_f_tri(s1, set)) + 1) *
					sizeof(char))))
		return (NULL);
	isset = 1;
	i[0] = 0;
	while (isset == 1)
	{
		i[1] = 0;
		isset = 0;
		while (set[i[1]] != 0 && isset == 0)
			in_while(s1, set, &i, &isset);
		i[0]++;
	}
	r = ft_strncpy(r, &s1[i[0] - 1], len_b_tri(s1, set, len_f_tri(s1, set)));
	r[len_b_tri(s1, set, len_f_tri(s1, set))] = 0;
	return (r);
}
