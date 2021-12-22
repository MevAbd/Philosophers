/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:47:39 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/22 18:43:40 by malbrand         ###   ########.fr       */
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
	int	i;

	i = 0;
	philo->info = inf;
	philo->time = ft_time();
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->info->nb_philo);
	if (!philo->fork)
		return (NULL);
	philo->even_eat = philo->info->nb_philo / 2;
	if (philo->info->nb_philo % 2 == 0)
		philo->odd_eat = philo->even_eat;
	else
		philo->odd_eat = philo->even_eat + 1;
	pthread_mutex_init(&philo->info_write, NULL);
	pthread_mutex_init(&philo->read_info, NULL);
	pthread_mutex_init(&philo->death, NULL);
	pthread_mutex_init(&philo->finish, NULL);
	while (i < philo->info->nb_philo)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
	return (philo);
}

t_philo	*ft_n_create(t_phil_inf *philo_info, int n)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = n;
	philo->dead = 0;
	philo->p_info = philo_info;
	return (philo);
}

t_philo	*ft_create(t_phil_inf *philo_info)
{
	int		i;
	t_philo	*ret;
	t_philo	*in;
	t_philo	*last;

	i = 0;
	ret = NULL;
	while (i < philo_info->info->nb_philo)
	{
		if (!ret)
			ret = ft_n_create(philo_info, i + 1);
		else
		{
			in = ft_n_create(philo_info, i + 1);
			in->next = ret;
			ret = in;
		}
		i++;
	}
	last = ret;
	while (last && last->next)
		last = last->next;
	last->next = ret;
	return (ret);
}
