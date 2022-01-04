/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:07:11 by malbrand          #+#    #+#             */
/*   Updated: 2022/01/04 21:53:43 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

typedef struct s_info
{
	int				ttd;
	int				tte;
	int				tts;
	int				n_philo;	
	int				max_eat;
	int				die;
	struct s_philo	*philo_ptr;
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
}					t_info;

typedef struct s_philo
{
	int				id;
	int				p_max_eat;
	long			last_meal;
	long			time;
	pthread_t		t_id;
	struct s_info	*info_ptr;
	struct s_philo	*next;
}					t_philo;
#endif
