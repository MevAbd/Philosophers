/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:21:49 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/22 18:41:20 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_exit(t_info *info, t_phil_inf *philo)
{
	if (info->error == 0)
		write(1, "Error\nNegative numbers are impossible\n", 39);
	if (info->error == 1)
		write(1, "Error\nOne of strings is not a number\n", 41);
	free(info);
	free(philo);
	exit (0);
}

int	main(int ac, char **av)
{
	t_info		*inf;
	t_phil_inf	*info_philo;
	t_philo		*philo;

	inf = ft_init(ac);
	(void)philo;
	info_philo = malloc(sizeof(t_phil_inf));
	if (!info_philo)
	{
		free(inf);
		exit(0);
	}
	if (ac == 5 || ac == 6)
	{
		inf = ft_parsing(ac, av, inf);
		if (inf->error != 2)
			ft_exit(inf, info_philo);
		info_philo = ft_init_phil_inf(info_philo, inf);
		philo = ft_create(info_philo);
	}
	else
		write(1, "Error\nNot good number of arg\n", 29);
	free(info_philo);
	free(inf);
	return (0);
}
