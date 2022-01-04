/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 09:28:49 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 07:21:16 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				sig;
	int				max_eat;
	int				n_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				die;
	int				double_die;
	long			time;
	void			*philo_ptr;
	pthread_mutex_t	write;
	pthread_mutex_t	test;
	pthread_mutex_t	*fork;
}			t_info;

typedef struct s_philo
{
	int				id;
	int				p_max_eat;
	long			stalk;
	long			last_meal;
	t_info			*info_ptr;
	pthread_t		t_id;
	struct s_philo	*next;
}					t_philo;

int			ft_atoi(char const *s);
int			ft_parsing(int ac, char **av);
int			ft_strncmp(char const *s1, char const *s2, size_t n);

char		*ft_itoa(int n, unsigned int j);

void		ft_thread(t_philo *philo);
void		ft_join(t_philo *philo);
void		ft_end(t_philo *philo);
void		ft_monitoring(t_philo *philo);
void		ft_sleep(t_info *info, long time, t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_dead(t_philo *philo);
void		ft_close_solo(t_philo *philo);
void		ft_lstadd_back(t_philo **alst, t_philo *new);

long		ft_time(void);

size_t		ft_strlen(const char *str);

t_info		*ft_fill_info(int ac, char **av);

t_philo		*ft_lstlast(t_philo *lst);
t_philo		*ft_fill_philo(t_info *info);

#endif
