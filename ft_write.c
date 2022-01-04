/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:12:43 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 20:09:08 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_philo.h"

void	ft_write_philo(t_philo *philo, char *str)
{
	char	*id;
	char	*time;

	id = ft_itoa(philo->id, 0);
	pthread_mutex_lock(&philo->info_ptr->write);
	time = ft_itoa(ft_time() - philo->time, 0);
	if (!philo->info_ptr->die)
	{
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " ", 1);
		write(1, str, ft_strlen(str));
	}
	pthread_mutex_unlock(&philo->info_ptr->write);
	free(time);
	free(id);
}
