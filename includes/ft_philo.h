/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:59:14 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/05 10:36:36 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "struct.h"

int		ft_max_eat(t_philo *philo);

void	ft_join(t_philo *philo);
void	ft_dead(t_philo *philo);
void	*ft_loop(t_philo *philo);
void	ft_thread(t_philo *philo);
void	ft_lock_fork(t_philo *philo);
void	ft_monitoring(t_philo *philo);
void	ft_unlock_fork(t_philo *philo);
void	ft_action(t_philo *philo, char *str);
void	ft_write_philo(t_philo *philo, char *str);
void	ft_sleep(long time, t_philo *philo, int n);
void	ft_lstadd_back(t_philo **alst, t_philo *new);

long	ft_time(void);

#endif
