/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:24:58 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/16 05:42:26 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

t_info	*ft_init(int ac)
{
	t_info	*inf;

	inf = malloc(sizeof(t_info));
	if (!inf)
		return (NULL);
	inf->nb_philo = 0;
	inf->time_die = 0;
	inf->time_eat = 0;
	inf->time_sleep = 0;
	if (ac == 5)
		inf->nb_eat = -1;
	else
		inf->nb_eat = 0;
	return (inf);
}

void	ft_exit(char *str, int i)
{
	if (i == 0)
		write(1, "Error\nNegative numbers are impossible\n", 39);
	else if (i == 1)
		write(1, "Error\nOne of the strings is not a number\n", 41);
	free(str);
	exit(0);
}

void	ft_fill_struct_bis(t_info *info, int ac, char **av)
{
	char	*test;

	info->time_sleep = ft_atoi((av[4]));
	test = ft_itoa(info->time_sleep, 0);
	if (ft_strncmp(test, av[4], ft_strlen(av[4])) != 0)
		ft_exit(test, 1);
	if (info->time_sleep < 1)
		ft_exit(test, 0);
	if (ac == 6)
	{
		free(test);
		info->nb_eat = ft_atoi((av[5]));
		test = ft_itoa(info->nb_eat, 0);
		if (ft_strncmp(test, av[5], ft_strlen(av[5])) != 0)
			ft_exit(test, 1);
		if (info->time_sleep < 1)
			ft_exit(test, 0);
	}
	free(test);
}

void	ft_fill_struct(t_info *info, int ac, char **av)
{
	char	*test;

	info->nb_philo = ft_atoi(av[1]);
	test = ft_itoa(info->nb_philo, 0);
	if (ft_strncmp(test, av[1], ft_strlen(av[1])) != 0)
		ft_exit(test, 1);
	if (info->nb_philo < 1 || info->nb_philo > 200)
		ft_exit(test, 0);
	free(test);
	info->time_die = ft_atoi(av[2]);
	test = ft_itoa(info->time_die, 0);
	if (ft_strncmp(test, av[2], ft_strlen(av[2])) != 0)
		ft_exit(test, 1);
	if (info->time_die < 1)
		ft_exit(test, 0);
	free(test);
	info->time_eat = ft_atoi(av[3]);
	test = ft_itoa(info->time_eat, 0);
	if (ft_strncmp(test, av[3], ft_strlen(av[3])) != 0)
		ft_exit(test, 1);
	if (info->time_eat < 1)
		ft_exit(test, 0);
	free(test);
	ft_fill_struct_bis(info, ac, av);
}

t_info	*ft_parsing(int ac, char **av, t_info *info)
{
	if (ac == 5)
		ft_fill_struct(info, ac, av);
	if (ac == 6)
		ft_fill_struct(info, ac, av);
	return (info);
}
