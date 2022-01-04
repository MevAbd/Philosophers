/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:48:16 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 22:00:20 by malbrand         ###   ########.fr       */
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
	int	ret;

	ret = ft_max_eat(philo);
	if (philo->id == 1 && philo->next->id == 1)
	{	
		philo->info_ptr->die = 1;
		ft_close_solo(philo);
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
	while (philo->info_ptr->die == 0 && ret == 0)
	{
		if (philo->id <= philo->info_ptr->n_philo)
			ft_monitoring(philo);
		ret = ft_max_eat(philo);
	}
	if (philo->info_ptr->die == philo->id)
		ft_close(philo);
	return ((void *)0);
}
