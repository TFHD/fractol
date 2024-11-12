/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:26:04 by sabartho          #+#    #+#             */
/*   Updated: 2024/11/12 12:06:36 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

float	ft_atof(char *str)
{
	float	result;
	float	pow;
	int		i;

	i = 0;
	pow = 0.1;
	result = ft_atoi(str);
	while (str[i] != '.')
	{
		if (str[i] == 0)
			return (result);
		i++;
	}
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result + (str[i] - 48) * pow;
		pow *= 0.1;
		i++;
	}
	if (str[0] == '-')
		return (result * -1);
	return (result);
}

float	*ft_parse(int ac, char **args)
{
	int		i;
	float	*result;

	i = 0;
	if (ac < 2)
		return (0);
	result = malloc(sizeof(float) * ac - 1);
	if (result == NULL)
		return (NULL);
	while (args[i])
	{
		result[i] = ft_atof(args[i]);
		i++;
	}
	return (result);
}
