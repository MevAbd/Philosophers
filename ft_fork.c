/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:44:14 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 22:45:09 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (philo->info_ptr->die)
		return ;
	if (philo->info_ptr->die == 0)
	{
		pthread_mutex_lock(fork);
		ft_write_philo(philo, "has taken a fork\n");
	}
}

void	ft_lock_fork(t_philo *philo)
{	
	ft_fork(philo, &philo->info_ptr->fork[philo->id - 1]);
	ft_fork(philo, &philo->info_ptr->fork[philo->next->id - 1]);
}

void	ft_unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->next->id - 1]);
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->id - 1]);
}
