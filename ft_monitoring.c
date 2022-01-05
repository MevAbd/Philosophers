/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:48:16 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/05 10:31:01 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_monitoring(t_philo *philo)
{
	if (philo->info_ptr->n_philo == 1)
	{
		philo->info_ptr->die = 1;
		return ;
	}
	ft_action(philo, "is eating\n");
	ft_action(philo, "is sleeping\n");
	ft_action(philo, "is thinking\n");
}

void	*ft_loop(t_philo *philo)
{
	if (philo->id == 1 && philo->next->id == 1)
	{	
		ft_sleep((philo->info_ptr->ttd), philo, 1);
		ft_write_philo(philo, "died\n");
		return ((void *)0);
	}
	if (philo->info_ptr->n_philo % 2)
	{
		if (philo->id == philo->info_ptr->n_philo)
			ft_sleep(philo->info_ptr->tte * 2, philo, 0);
		else if (philo->id % 2)
			ft_sleep(philo->info_ptr->tte, philo, 0);
	}
	else if (philo->id % 2)
		ft_sleep(philo->info_ptr->tte, philo, 0);
	while ((philo->info_ptr->die == 0) && (ft_max_eat(philo) == 0))
	{
		if (philo->id <= philo->info_ptr->n_philo)
			ft_monitoring(philo);
	}
	if (philo->info_ptr->die == philo->id)
		ft_write_philo(philo, "died\n");
	return ((void *)0);
}
