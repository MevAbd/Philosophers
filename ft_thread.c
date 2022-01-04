/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:04:43 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 21:43:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_max_eat(t_philo *philo)
{
	t_philo	*cpy;

	cpy = philo;
	while (cpy->next->id != 1)
	{
		if (cpy->p_max_eat == 0)
			cpy = cpy->next;
		else
			return (0);
	}
	if (cpy->p_max_eat == 0)
		return (1);
	return (0);
}

void	ft_thread(t_philo *philo)
{
	int		i;
	t_philo	*cpy;
	t_info	*info;

	info = philo->info_ptr;
	i = info->n_philo;
	cpy = philo;
	while (i)
	{
		pthread_create(&cpy->t_id, NULL, (void *)&ft_loop, cpy);
		cpy = cpy->next;
		i--;
	}
}

void	ft_join(t_philo *philo)
{
	int		i;
	t_philo	*cpy;
	t_info	*info;

	info = philo->info_ptr;
	i = info->n_philo;
	cpy = philo;
	while (i)
	{
		pthread_join(cpy->t_id, NULL);
		cpy = cpy->next;
		i--;
	}
}
