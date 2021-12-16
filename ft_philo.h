/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:25:59 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/16 15:25:17 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_info
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_eat;
	int	error;
}				t_info;

typedef struct s_phil_inf
{
	int				odd_eat;
	int				even_eat;
	int				eat_limit;
	int				n_philo;
	long			time;
	void			*philo_ptr;
	pthread_mutex_t	info_write;
	pthread_mutex_t	read_info;
	pthread_mutex_t	death;
	pthread_mutex_t	finish;
}					t_phil_inf;

int		ft_atoi(char const *s);
int		ft_strncmp(char const *s1, char const *s2, size_t n);

char	*ft_itoa(int n, unsigned int j);

size_t	ft_strlen(const char *str);

t_info	*ft_parsing(int ac, char **av, t_info *info);
t_info	*ft_init(int ac);

#endif
