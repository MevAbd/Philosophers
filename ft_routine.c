/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:44:43 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 05:52:45 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_ret(int i, int ret)
{
	if (i)
		return (2);
	return (ret);
}

int	ft_dead(t_info *info)
{
	int		i;
	int		ret;
	int		eat;
	t_philo	*philo;

	pthread_mutex_lock(&info->dead);
	philo = info->philo_ptr;
	i = info->n_philo;
	ret = 0;
	eat = 0;
	while (philo && i)
	{
		if (philo->stalk != 0 && ((ft_time() - info->time) - philo->stalk)
			>= philo->ttd)
		{
			ret = 1;
			philo->die = 1;
		}
		if (info->max_eat > 0 && philo->verif == info->max_eat)
			eat++;
		philo = philo->next;
	}
	ret = ft_ret(info->n_philo, ret);
	pthread_mutex_unlock(&info->dead);
	return (ret);
}

void	ft_signal(t_info *info, int *sig)
{
	int	ret;

	pthread_mutex_lock(&info->read_info);
	pthread_mutex_lock(&info->write_info);
	if (info->sig == 0 && !info->max_even)
	{
		info->sig = 1;
		info->max_even = info->even_eat;
	}
	else if (info->sig == 1 && !info->max_odd)
	{
		info->sig = 0;
		info->max_odd = info->odd_eat;
	}
	ret = ft_dead(info);
	if (ret == 2)
		info->sig = 2;
	*sig = info->sig;
	pthread_mutex_unlock(&info->read_info);
	pthread_mutex_unlock(&info->write_info);
}

void	*ft_loop(t_philo *philo)
{
	int	sig;

	sig = 0;
	while (sig != 2 && sig != 3)
	{
		ft_signal(philo->info_ptr, &sig);
		if ((philo->id % 2 == 0 && sig == 0)
			|| (philo->id % 2 != 0 && sig == 1))
			ft_eat(philo);
	}
	ft_close(philo);
	return ((void *)0);
}
