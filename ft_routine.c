/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:44:43 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 07:02:53 by malbrand         ###   ########.fr       */
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
	i = info->n_philo + 1;
	ret = 0;
	eat = 0;
	while (philo && --i)
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
	if (info->sig == 0 && !info->even_eat)
	{
		info->sig = 1;
		info->even_eat = info->even_eat_tmp;
	}
	else if (info->sig == 1 && !info->odd_eat)
	{
		info->sig = 0;
		info->odd_eat = info->odd_eat_tmp;
	}
	ret = ft_dead(info);
	if (ret == 1)
		info->sig = 2;
	if (ret == 2)
		info->sig = 3;
	*sig = info->sig;
	pthread_mutex_unlock(&info->read_info);
	pthread_mutex_unlock(&info->write_info);
}

void	*ft_loop(t_philo *philo)
{
	int	sig;

	sig = -1;
	while (sig != 2 && sig != 3)
	{	
		printf("hello\n");
		printf("%d %d\n", philo->id, sig);
		ft_signal(philo->info_ptr, &sig);
		printf("%d %d\n", philo->id, sig);
		if ((philo->id % 2 == 0 && sig == 0x00)
			|| (philo->id % 2 != 0 && sig == 0x01))
		{
			printf("test\n");
			ft_eat(philo);
		}
	}
	ft_close(philo);
	return ((void *)0);
}
