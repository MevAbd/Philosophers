/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:16:17 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 07:26:32 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_fork(t_philo *philo, pthread_mutex_t *fork)
{
	char	*id;
	char	*time;

	while (fork->__align)
		ft_dead(philo);
	if (philo->info_ptr->die)
		return ;
//	pthread_mutex_lock(fork);
	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->info_ptr->time, 0);
	if ((philo->info_ptr-> sig == 1 || philo->info_ptr->sig == 0)
		&& philo->info_ptr->die == 0)
	{
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " has taken a fork\n", 18);
		pthread_mutex_unlock(&philo->info_ptr->write);
	}
	free(id);
	free(time);
}

void	ft_eat(t_philo *philo)
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
		write(1, " is eating\n", 11);
		pthread_mutex_unlock(&philo->info_ptr->write);
		philo->stalk = ft_time() - philo->info_ptr->time;
		philo->p_max_eat--;
		philo->last_meal = philo->stalk;
		ft_sleep(philo->info_ptr, philo->info_ptr->tte, philo);
	}
	free(id);
	free(time);
}

void	ft_monitoring_bis(t_philo *philo)
{	
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
}

void	ft_monitoring(t_philo *philo)
{
	t_info	*info;
	t_philo	*last;
	int		check;

//	pthread_mutex_lock(&philo->info_ptr->test);
	info = philo->info_ptr;
	last = philo;
	check = philo->id;
	if (last->next)
		last = last->next;
	while (last->id != check)
		last = last->next;
	if (info->n_philo == 1)
	{
		info->die = 1;
		return ;
	}
	ft_monitoring_bis(philo);
//	pthread_mutex_unlock(&philo->info_ptr->fork);
	ft_eat(philo);
//	pthread_mutex_unlock(&philo->info_ptr->test);
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->next->id - 1]);
	ft_sleeping(philo);
	ft_thinking(philo);
}
