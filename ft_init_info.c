/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:56:38 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 06:18:20 by malbrand         ###   ########.fr       */
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

t_info	*ft_init_bis(t_info	*info)
{
	int	i;

	i = 0;
	info->even_eat_tmp = info->even_eat;
	info->odd_eat_tmp = info->odd_eat;
	pthread_mutex_init(&info->write_info, NULL);
	pthread_mutex_init(&info->read_info, NULL);
	pthread_mutex_init(&info->dead, NULL);
	pthread_mutex_init(&info->finish, NULL);
	pthread_mutex_init(&info->control, NULL);
	while (i < info->n_philo)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	return (info);
}

t_info	*ft_init_info(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->sig = 0;
	info->n_philo = ft_atoi(av[1]);
	info->even_eat = info->n_philo / 2;
	if (ac == 5)
		info->max_eat = 0;
	else
		info->max_eat = ft_atoi(av[5]);
	if (info->n_philo % 2 == 0)
		info->odd_eat = info->even_eat;
	else
		info->odd_eat = info->even_eat + 1;
	info->time = ft_time();
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->fork)
		return (NULL);
	return (ft_init_bis(info));
}
