/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 04:45:25 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/30 17:42:27 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_close(t_philo *philo)
{
	t_philo	*cpy;
	int		i;

	pthread_mutex_lock(&philo->info_ptr->dead);
	cpy = philo->info_ptr->philo_ptr;
	i = philo->info_ptr->n_philo;
	while (cpy && i)
	{
		if (cpy->die)
		{
			ft_write_solo(philo, "died");
			cpy->die = 0;
			break ;
		}
		cpy = cpy->next;
		i--;
	}
	pthread_mutex_unlock(&philo->info_ptr->dead);
}

void	ft_write_solo(t_philo *philo, char *str)
{
	static int		i;
	char			*time;
	char			*id;

	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->info_ptr->time, 0);
	if (!i)
	{
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " ", 1);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		i = 1;
	}
	free(id);
	free(time);
}

void	ft_write(t_philo *philo, char *str)
{
	char	*time;
	char	*id;
	int		end;

	pthread_mutex_lock(&philo->info_ptr->control);
	id = ft_itoa(philo->id, 0);
	time = ft_itoa(ft_time() - philo->info_ptr->time, 0);
	pthread_mutex_lock(&philo->info_ptr->write_info);
	if (philo->info_ptr->sig == 3 || philo->info_ptr->sig == 2)
		end = 2;
	else
		end = 0;
	pthread_mutex_unlock(&philo->info_ptr->write_info);
	if (!end)
	{
		write(1, time, ft_strlen(time));
		write(1, " ", 1);
		write(1, id, ft_strlen(id));
		write(1, " ", 1);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	free(id);
	free(time);
	pthread_mutex_unlock(&philo->info_ptr->control);
}

void	ft_sleep(t_info *info, long time)
{
	long	goal;
	int		sig;

	sig = 0;
	goal = ft_time() + time;
	while (ft_time() < goal && sig != 2 && sig != 3)
	{
		ft_signal(info, &sig);
		usleep(10);
	}
}

void	ft_unlock(t_philo *philo)
{
	pthread_mutex_lock(&philo->info_ptr->write_info);
	philo->stalk = ft_time() - philo->info_ptr->time;
	if (philo->info_ptr->sig == 0)
		philo->info_ptr->even_eat--;
	else
		philo->info_ptr->odd_eat--;
	philo->verif++;
	pthread_mutex_unlock(&philo->info_ptr->write_info);
	ft_sleep(philo->info_ptr, philo->tte);
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->next->id] - 1);
	pthread_mutex_unlock(&philo->info_ptr->fork[philo->id] - 1);
}
