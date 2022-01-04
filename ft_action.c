/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:25:53 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 22:39:30 by malbrand         ###   ########.fr       */
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
	else
	{
		if (!philo->info_ptr->die)
			usleep(time * 1000);
	}
}

void	ft_action(t_philo *philo, char *str)
{
	if (philo->info_ptr->die == 0 || str[3] == 's')
	{
		if (str[3] == 'e')
		{	
			ft_lock_fork(philo);
			ft_write_philo(philo, str);
			philo->p_max_eat--;
			philo->last_meal = ft_time() - philo->time;
			ft_sleep(philo->info_ptr->tte, philo, 0);
		}
		else if (str[3] == 's')
		{
			ft_write_philo(philo, str);
			ft_unlock_fork(philo);
			ft_sleep(philo->info_ptr->tts, philo, 0);
		}
		else
			ft_write_philo(philo, str);
	}
}

void	ft_dead(t_philo *philo)
{
	while (philo->info_ptr->die == 0)
	{
		if ((ft_time() - philo->time
				- philo->last_meal >= philo->info_ptr->ttd))
			philo->info_ptr->die = philo->id;
		philo = philo->next;
	}
}
