/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:50:25 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 22:52:10 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

int	ft_atoi(char const *s)
{
	int	i;
	int	ret;
	int	neg;

	i = 0;
	ret = 0;
	neg = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + s[i] - '0';
		i++;
	}
	ret = ret * neg;
	return (ret);
}
