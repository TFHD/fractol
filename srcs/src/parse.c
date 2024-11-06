/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:19:48 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/05 13:52:57 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	negate;
	int	i;

	result = 0;
	negate = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negate = -negate;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * negate);
}

float ft_atof(char *str)
{
	float	number;
	int		i;
	float	power;

	i = 0;
	power = 0.1;
	number = ft_atoi(str) * 1.0;
	if (!ft_strchr(str, '.'))
		return (number);
	while (str[i] != '.')
		i++;
	i++;
	while (str[i] != '\0')
	{
		number = number + (power * (str[i] - 48));
		power *= 0.1;
		i++;
	}
	return (number);
}

float	*ft_parse(int ac, char **av)
{
	float	*tab;
	int		i;

	tab = malloc(sizeof(float) * (ac));
	i = 0;
	if (!tab)
		return (0);
	while (av[i])
	{
		tab[i] = atof(av[i]);
		i++;
	}
	return (tab);
}
