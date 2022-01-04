/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:58:45 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 06:46:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_close_solo(t_philo *philo)
{
	char	*id;
	char	*time;

	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->info_ptr->time, 0);
	if (!philo->info_ptr->double_die && philo->id == philo->info_ptr->die)
	{
		pthread_mutex_lock(&philo->info_ptr->write);
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " died\n", 6);
		philo->info_ptr->double_die = 1;
		pthread_mutex_unlock(&philo->info_ptr->write);
	}
	free(id);
	free(time);
	philo->stalk = ft_time() - philo->info_ptr->time;
}

void	ft_end(t_philo *philo)
{
	t_info	*info;
	t_philo	*next;
	int		i;
	int		n_philo;

	i = 0;
	info = philo->info_ptr;
	n_philo = info->n_philo;
	free(info);
	while (i < n_philo)
	{
		next = philo->next;
		free(philo);
		philo = next;
		i++;
	}
}
