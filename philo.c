/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:21:49 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/09 04:44:09 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	philo = ft_parsing(ac, av, philo);
	printf("philo == %d die == %d, eat == %d sleep == %d\n", philo.nb_philo, philo.time_die, philo.time_eat, philo.time_sleep);
	return (0);
}
