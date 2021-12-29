/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:20:20 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/29 05:30:43 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	ft_write(philo, "has taken a fork");
}

void	ft_solo(t_philo *philo)
{
	ft_fork(philo, &philo->info_ptr->fork[philo->id - 1]);
	ft_sleep(philo->info_ptr, philo->ttd);
	ft_write_solo(philo, "died");
	philo->info_ptr->sig = 3;
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
	ft_write(philo, "is eating");
	ft_unlock(philo);
	ft_write(philo, "is sleeping");
	ft_sleep(philo->info_ptr, philo->tts);
	ft_write(philo, "is thinking");
}
