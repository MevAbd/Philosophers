/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:20:20 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/30 01:08:37 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	ft_write(philo, "has taken a fork");
}

static void	ft_solo(t_philo *philo)
{
	ft_fork(philo, &philo->info_ptr->fork[philo->id - 1]);
	ft_sleep(philo->info_ptr, philo->ttd);
	ft_write_solo(philo, "died");
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->id - 1]);
	philo->info_ptr->sig = 2;
}

void	ft_eat(t_philo *philo)
{
	if (philo->id == philo->next->id)
	{
		ft_solo(philo);
		return ;
	}
	if (philo->id < philo->next->id)
	{
		ft_fork(philo, &philo->info_ptr->fork[philo->id - 1]);
		ft_fork(philo, &philo->info_ptr->fork[philo->next->id - 1]);
	}
	else
	{
		ft_fork(philo, &philo->info_ptr->fork[philo->next->id - 1]);
		ft_fork(philo, &philo->info_ptr->fork[philo->id - 1]);
	}
	usleep(10);
	ft_write(philo, "is eating");
	ft_unlock(philo);
	usleep(10);
	ft_write(philo, "is sleeping");
	usleep(10);
	ft_sleep(philo->info_ptr, philo->tts);
	ft_write(philo, "is thinking");
}
