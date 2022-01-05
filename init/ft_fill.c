/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:34:09 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/05 10:33:13 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "ft_libft.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, (void *)0);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}

t_info	*ft_fill_info(int ac, char **av)
{
	t_info	*info;
	int		i;

	i = 0;
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->n_philo = ft_atoi(av[1]);
	info->ttd = ft_atoi(av[2]);
	info->tte = ft_atoi(av[3]);
	info->tts = ft_atoi(av[4]);
	info->die = 0;
	pthread_mutex_init(&info->write, NULL);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	while (i < info->n_philo)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	if (ac == 5)
		info->max_eat = -1;
	else
		info->max_eat = ft_atoi(av[5]);
	return (info);
}

t_philo	*ft_create_one(t_info *info, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->id = id;
	philo->info_ptr = info;
	philo->next = NULL;
	philo->last_meal = 0;
	philo->time = ft_time();
	philo->p_max_eat = info->max_eat;
	return (philo);
}

t_philo	*ft_fill_philo(t_info *info)
{
	t_philo	*philo;
	t_philo	*in;
	int		i;

	i = 0;
	philo = NULL;
	while (i < info->n_philo)
	{
		if (!philo)
			philo = ft_create_one(info, i + 1);
		else
		{
			in = ft_create_one(info, i + 1);
			ft_lstadd_back(&philo, in);
		}
		i++;
	}
	ft_lstadd_back(&philo, philo);
	return (philo);
}
