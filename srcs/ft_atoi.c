/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 03:10:58 by root              #+#    #+#             */
/*   Updated: 2022/11/06 03:10:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_space(const char *ss)
{
	if (*ss == ' ' || *ss == '\r' || *ss == '\v' || *ss == '\t'
		|| *ss == '\n' || *ss == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	ans;
	int		gg;

	ans = 0;
	gg = 1;
	while (*str && ft_space(str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			gg = -1;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((ans * 10 + (str[i] - '0')) / 10 != ans)
		{
			if (gg == -1)
				return (0);
			else
				return (-1);
		}
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(ans * gg));
}
