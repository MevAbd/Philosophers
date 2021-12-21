/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:47:39 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/21 05:33:02 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, (void *)0);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}

t_phil_inf	*ft_init_phil_inf(t_phil_inf *philo, t_info *inf)
{
	philo->info = inf;
	philo->time = ft_time();
	return (philo);
}
