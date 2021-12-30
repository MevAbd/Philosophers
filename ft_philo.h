/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:52:22 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/30 01:11:48 by malbrand         ###   ########.fr       */
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
	int				odd_eat;
	int				odd_eat_tmp;
	int				even_eat;
	int				even_eat_tmp;
	int				max_eat;
	int				n_philo;
	long			time;
	void			*philo_ptr;
	pthread_mutex_t	write_info;
	pthread_mutex_t	read_info;
	pthread_mutex_t	dead;
	pthread_mutex_t	finish;
	pthread_mutex_t	control;
	pthread_mutex_t	*fork;
}					t_info;

typedef struct s_philo
{
	int					id;
	int					die;
	int					ttd;
	int					tte;
	int					tts;
	int					verif;
	long				stalk;
	t_info				*info_ptr;
	pthread_mutex_t		fork;
	pthread_t			t_id;
	struct s_philo		*next;
}						t_philo;

int			ft_atoi(char const *s);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
int			ft_parsing(int ac, char **av);

char		*ft_itoa(int n, unsigned int j);

long		ft_time(void);

void		ft_thread(t_philo *philo);
void		*ft_loop(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_write_solo(t_philo *philo, char *str);
void		ft_write(t_philo *philo, char *str);
void		ft_sleep(t_info *info, long time);
void		ft_join(t_philo *philo);
void		ft_unlock(t_philo *philo);
void		ft_close(t_philo *philo);
void		ft_signal(t_info *info, int *sig);
void		ft_lstadd_back(t_philo **alst, t_philo *new);

size_t		ft_strlen(const char *str);

t_info		*ft_init_info(int ac, char **av);

t_philo		*ft_create_philo(t_info *info, char **av);
t_philo		*ft_lstlast(t_philo *lst);

#endif
