/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:21:49 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/16 05:42:34 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*PrintHello(void *threadid)
{
	long t;

	t = (long)threadid;
	printf("Thread = %ld\n", t);
	pthread_exit(NULL);
}

int	main(int ac, char **av)
{
	t_info		*inf;

	inf = ft_init(ac);
	printf("ac == %d\n", ac);
	if (ac == 5 || ac == 6)
		inf = ft_parsing(ac, av, inf);
	printf("nb philo == %d time die == %d time eat == %d time sleep == %d nb eat == %d error == %d\n", inf->nb_philo, inf->time_die, inf->time_eat, inf->time_sleep, inf->nb_eat, inf->error);
	return (0);
}
