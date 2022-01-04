/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:37:16 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 21:25:08 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

#include "ft_philo.h"

void	ft_close(t_philo *philo)
{
	char	*id;
	char	*time;

	time = ft_itoa(ft_time() - philo->time, 0);
	id = ft_itoa(philo->id, 0);
	if (philo->id == philo->info_ptr->die)
	{
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " died\n", 6);
		pthread_mutex_unlock(&philo->info_ptr->write);
	}
	free(id);
	free(time);
}

void	ft_close_solo(t_philo *philo)
{
	char	*id;
	char	*time;

	time = NULL;
	id = ft_itoa(philo->id, 0);
	if (philo->id == philo->info_ptr->die)
	{
		ft_sleep((philo->info_ptr->ttd), philo, 1);
		time = ft_itoa(ft_time() - philo->time, 0);
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " died\n", 6);
		pthread_mutex_unlock(&philo->info_ptr->write);
	}
	free(id);
	if (time)
		free(time);
}
