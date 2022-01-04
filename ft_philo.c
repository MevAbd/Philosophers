/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 09:30:22 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/31 15:25:16 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

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
	ft_join(philo);
	ft_end(philo);
	return (0);
}
