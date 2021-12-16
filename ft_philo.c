/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:21:49 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/16 15:39:31 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	main(int ac, char **av)
{
	t_info		*inf;
	t_philo_inf	*philo_inf;

	inf = ft_init(ac);
	if (ac == 5 || ac == 6)
	{
		inf = ft_parsing(ac, av, inf);
		philo_inf = maloc(sizeof(t_philo_inf));
		if (!philo_inf)
		{
			return (1);
			free(inf);
		}
	}
	free(inf);
	return (0);
}
