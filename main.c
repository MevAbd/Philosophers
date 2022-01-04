/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:58:41 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 22:54:53 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "init.h"

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
	return (1);
}
