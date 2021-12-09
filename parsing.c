/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:24:58 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/09 04:48:10 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_philo *philo, int ac)
{
	if (ac == 5)
	{
		philo->nb_philo = 0;
		philo->time_die = 0;
		philo->time_eat = 0;
		philo->time_sleep = 0;
		philo->nb_eat = -1;
	}
	if (ac == 6)
	{
		philo->nb_philo = 0;
		philo->time_die = 0;
		philo->time_eat = 0;
		philo->time_sleep = 0;
		philo->nb_eat = 0;
	}
}

void	ft_exit(char *str)
{
	free(str);
	exit(0);
}

void	ft_fill_struct(t_philo *philo, int ac, char**av)
{
	char *test;

	philo->nb_philo = ft_atoi(av[1]);
	test = ft_itoa(philo->nb_philo, 0);
	if (ft_strncmp(test, av[1], ft_strlen(av[1]) != 0))
		ft_exit(test);
	if (philo->nb_philo < 1 || philo->nb_philo > 200)
		ft_exit(test);
	free(test);

	philo->time_die = ft_atoi(av[2]);
	test = ft_itoa(philo->time_die, 0);
	if (ft_strncmp(test, av[2], ft_strlen(av[2])) != 0)
		ft_exit(test);
	if (philo->time_die < 1)
		ft_exit(test);
	free(test);
	philo->time_eat = ft_atoi(av[3]);
	test = ft_itoa(philo->time_eat, 0);
	if (ft_strncmp(test, av[3], ft_strlen(av[3])) != 0)
		ft_exit(test);
	if (philo->time_eat < 1)
		ft_exit(test);
	free(test);
	philo->time_sleep = ft_atoi((av[4]));
	test = ft_itoa(philo->time_sleep, 0);
	if (ft_strncmp(test, av[4], ft_strlen(av[4])) != 0)
		ft_exit(test);
	if (philo->time_sleep < 1)
		ft_exit(test);
	if (ac == 6)
	{
		free(test);
		philo->nb_eat = ft_atoi((av[5]));
		test = ft_itoa(philo->nb_eat, 0);
		if (ft_strncmp(test, av[5], ft_strlen(av[5])) != 0)
			ft_exit(test);
		if (philo->time_sleep < 1)
			ft_exit(test);
	}
	free(test);
}

t_philo	ft_parsing(int ac, char **av, t_philo philo)
{
	ft_init(&philo, 5);
	if (ac == 5)
	{
		ft_init(&philo, ac);
		ft_fill_struct(&philo, ac, av);
		
	}
	if (ac == 6)
	{
		ft_init(&philo, ac);
		ft_fill_struct(&philo, ac, av);
	}
	return (philo);
}
