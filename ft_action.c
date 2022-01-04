/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:17:02 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/31 15:17:08 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_sleep(t_info *info, long time, t_philo *philo)
{
	long	goal;
	int		sig;

	sig = 0;
	(void)info;
	goal = ft_time() + time;
	while (ft_time() < goal && info->die == 0)
	{
		usleep(10);
		ft_dead(philo);
	}
}

void	ft_thinking(t_philo *philo)
{
	char	*id;
	char	*time;

	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->info_ptr->time, 0);
	if ((philo->info_ptr-> sig == 1 || philo->info_ptr->sig == 0)
		&& philo->info_ptr->die == 0)
	{
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " is thinking\n", 13);
		pthread_mutex_unlock(&philo->info_ptr->write);
	}
	free(id);
	free(time);
	philo->stalk = ft_time() - philo->info_ptr->time;
}

void	ft_sleeping(t_philo *philo)
{
	char	*id;
	char	*time;

	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->info_ptr->time, 0);
	if ((philo->info_ptr-> sig == 1 || philo->info_ptr->sig == 0)
		&& philo->info_ptr->die == 0)
	{
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " is sleeping\n", 13);
		pthread_mutex_unlock(&philo->info_ptr->write);
		ft_sleep(philo->info_ptr, philo->info_ptr->tts, philo);
	}
	free(id);
	free(time);
	philo->stalk = ft_time() - philo->info_ptr->time;
}

void	ft_dead(t_philo *philo)
{
	int	i;

	i = philo->info_ptr->n_philo;
	while (--i)
	{
		if (ft_time() - philo->info_ptr->time
			- philo->last_meal >= philo->info_ptr->ttd)
			philo->info_ptr->die = philo->id;
	}
}
