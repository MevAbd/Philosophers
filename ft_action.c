/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:25:53 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 18:37:28 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_sleep(long time, t_philo *philo, int verif)
{
	long	goal;

	goal = ft_time() + time;
	if (verif == 1)
	{
		while (ft_time() < goal)
		{
			usleep(1);
		}
	}
	while (ft_time() < goal && philo->info_ptr->die == 0)
	{
		usleep(time * 1000);
		ft_dead(philo);
	}
}

void	ft_thinking(t_philo *philo)
{
	char	*id;
	char	*time;

	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->time, 0);
	if (philo->info_ptr->die == 0)
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
}

void	ft_sleeping(t_philo *philo)
{
	char	*id;
	char	*time;

	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->time, 0);
	if ( philo->info_ptr->die == 0)
	{
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " is sleeping\n", 13);
		pthread_mutex_unlock(&philo->info_ptr->write);
		ft_sleep(philo->info_ptr->tts, philo, 0);
	}
	free(id);
	free(time);
}

void	ft_dead(t_philo *philo)
{
	int	i;
	long time;

	time = ft_time();
	i = philo->info_ptr->n_philo;
	while (--i)
	{
		if ((ft_time() - philo->time
			- philo->last_meal >= philo->info_ptr->ttd))
		{
		//	printf("philo->id == %d\n", philo->id);
		//	printf("time now == %ld\n time ttd == %d\n", (ft_time() - philo->time - philo->last_meal), philo->info_ptr->ttd);
			philo->info_ptr->die = philo->id;
		}
	}
}
