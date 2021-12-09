/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:25:59 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/09 04:22:32 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_philo
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_eat;
	int	error;
}				t_philo;


int	ft_atoi(char const *s);
int	ft_strncmp(char const *s1, char const *s2, size_t n);

char	*ft_itoa(int n, unsigned int j);

size_t	ft_strlen(const char *str);

t_philo	ft_parsing(int ac, char **av, t_philo philo);

#endif
