/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:59:14 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 19:53:03 by malbrand         ###   ########.fr       */
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

int		ft_atoi(char const *s);
int		ft_parsing(int ac, char **av);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_max_eat(t_philo *philo);

char	*ft_itoa(int n, unsigned int j);

void	ft_join(t_philo *philo);
void	ft_dead(t_philo *philo);
void	ft_thread(t_philo *philo);
void	ft_monitoring(t_philo *philo);
void	ft_lock_fork(t_philo *philo);
void	ft_unlock_fork(t_philo *philo);
void	ft_close_solo(t_philo *philo);
void	ft_close(t_philo *philo);
void	ft_action(t_philo *philo, char *str);
void	ft_write_philo(t_philo *philo, char *str);
void	ft_sleep(long time, t_philo *philo, int n);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
void	*ft_loop(t_philo *philo);

long	ft_time(void);


t_philo	*ft_lstlast(t_philo *lst);

size_t	ft_strlen(const char *str);

#endif