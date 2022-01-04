/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:21:04 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 07:33:06 by malbrand         ###   ########.fr       */
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
	else
		return (0);
	return (1);
}

void	*ft_loop(t_philo *philo)
{	
	int	ret;

	ret = ft_max_eat(philo);
	if (philo->id % 2 == 0)
		usleep(philo->info_ptr->tte * 1000);
	if (philo->id == philo->info_ptr->n_philo && philo->id % 2 != 0)
		usleep((philo->info_ptr->tte + philo->info_ptr->tts) * 1000);
	while (philo->info_ptr->die == 0 && (philo->info_ptr->sig == 0
			|| philo->info_ptr->sig == 1) && ret == 0)
	{
//		else if (philo->id == philo->info_ptr->n_philo && philo->id % 2 != 0)
//			usleep((philo->info_ptr->tte + philo->info_ptr->tts) * 1000);
		ft_dead(philo);
		ret = ft_max_eat(philo);
		if (philo->id <= philo->info_ptr->n_philo)
			ft_monitoring(philo);
		ret = ft_max_eat(philo);
	}
	if (philo->info_ptr->double_die == 0)
		ft_close_solo(philo);
	return ((void *)0);
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
