/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:58:41 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/05 10:55:47 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "init.h"

void	ft_exit(t_philo *philo)
{
	t_philo	*cpy;
	int		i;

	i = philo->info_ptr->n_philo;
	pthread_mutex_destroy(&philo->info_ptr->write);
	free(philo->info_ptr->fork);
	while (i)
	{
		cpy = philo->next;
		free(philo);
		philo = cpy;
		i--;
	}
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;

	if (ft_parsing(ac, av))
		return (0);
	info = ft_fill_info(ac, av);
	philo = ft_fill_philo(info);
	info->philo_ptr = philo;
	ft_thread(philo);
	ft_dead(philo);
	ft_join(philo);
	ft_exit(philo);
	free(info);
	return (1);
}
