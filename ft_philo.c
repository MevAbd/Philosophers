/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:58:41 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 18:04:37 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;

	if (ft_parsing(ac, av))
		return (0);
//	printf("1\n");
	info = ft_fill_info(ac, av);
//	printf("2\n");
	philo = ft_fill_philo(info);
//	printf("3\n");
	info->philo_ptr = philo;
	ft_thread(philo);
//	printf("4\n");
	ft_join(philo);
//	printf("5\n");
	return (1);
}
